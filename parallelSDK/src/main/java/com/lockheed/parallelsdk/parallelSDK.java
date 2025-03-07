package com.lockheed.parallelsdk;

import android.content.Context;
import android.content.res.AssetFileDescriptor;
import android.content.res.AssetManager;
import android.os.Looper;
import android.util.Log;

import org.jetbrains.annotations.Nullable;

import java.io.ByteArrayOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.nio.Buffer;
import java.nio.ByteBuffer;
import java.util.TreeMap;
import java.util.concurrent.ThreadPoolExecutor;

import party.iroiro.luajava.AbstractLua;
import party.iroiro.luajava.ExternalLoader;
import party.iroiro.luajava.Lua;

//需要在主线程进行初始化，需要MainLua来做一些事情
public class parallelSDK {
    static parallelSDK instance=null;
    AbstractLua MainLua;   //记录SDK持有的主lua state
    TreeMap<Integer,Long> StateThreadTree;
    ThreadPoolExecutor TaskPool;
    Context C;
    // Used to load the 'parallelsdk' library on application startup.
    static {
        System.loadLibrary("parallelsdk");
    }

    private parallelSDK() {
        // 防止反射破坏单例
        if (instance != null) {
            throw new IllegalStateException("parallelSDK instance already created");
        }
    }

    public static parallelSDK getInstance() {
        if (instance == null) {
            // 通过同步块来确保线程安全
            synchronized (parallelSDK.class) {
                if (instance == null) {
                    instance = new parallelSDK();
                }
            }
        }
        return instance;
    }

    public boolean SDKInit(Context context){
        C=context;
        MainLua=LuaNewState(Looper.getMainLooper());
//        StateThreadTree.put(MainLua.getId(), MainLua.getPointer());
        return MainLua!=null;
    }

    private AbstractLua LuaNewState(Looper looper){
        AbstractLua L=new SafeLua53(looper);
        L.setExternalLoader(new DefaultLuaLoader(C));
        L.openLibraries();
        //为luaState准备C function，传入id和queue
        SDKLuaInit(L.getPointer(),L.getId());

        return L;
    }

    public AbstractLua LuaNewState(){
        AbstractLua L=new SafeLua53();
        L.setExternalLoader(new DefaultLuaLoader(C));
        L.openLibraries();
        //为luaState准备C function，传入id和queue
        SDKLuaInit(L.getPointer(),L.getId());

        return L;
    }

    public int luaNewStateC(){
        AbstractLua L=new SafeLua53();
        L.setExternalLoader(new DefaultLuaLoader(C));
        L.openLibraries();
        SDKLuaInit(L.getPointer(),L.getId());
        return L.getId();
    }

    public void LuaCloseState(AbstractLua L){;
        ((SafeLua53)L).looper.quitSafely();
        L.close();
    }

    public void closeLuaStateC(int id){
        AbstractLua L=AbstractLua.getInstance(id);
        ((SafeLua53)L).looper.quitSafely();
        L.close();
    }

    public static void Tick(int id){
        AbstractLua L=AbstractLua.getInstance(id);
        //这里异步扔走了
        ((SafeLua53)L).run("local a=require(\"cross_vm\")" +
                "a.analyzer(_thread.processtask())");
    }

    public native long SDKLuaInit(long luaState,int id);
}