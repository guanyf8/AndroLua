package com.lockheed.parallelsdk;

import android.content.Context;
import android.content.res.AssetFileDescriptor;
import android.content.res.AssetManager;
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
import party.iroiro.luajava.lua53.Lua53;

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
        MainLua=LuaNewState();
        C=context;
        LuaNewState().setExternalLoader(new ExternalLoader() {
            AssetManager assetManager=C.getAssets();

            @Override
            public @Nullable Buffer load(String module, Lua L) {String luaPath = module.replace('.', '/') + ".lua";

                try {
                    // 打开assets文件描述符
                    AssetFileDescriptor fd = assetManager.openFd(luaPath);

                    // 读取文件内容到字节数组
                    InputStream is = fd.createInputStream();
                    ByteArrayOutputStream buffer = new ByteArrayOutputStream();

                    byte[] data = new byte[1024];
                    int bytesRead;
                    while ((bytesRead = is.read(data)) != -1) {
                        buffer.write(data, 0, bytesRead);
                    }

                    // 关闭资源
                    is.close();
                    fd.close();

                    // 转换为ByteBuffer返回（根据实际Buffer类型调整）
                    return ByteBuffer.wrap(buffer.toByteArray());
                } catch (IOException e) {
                    // 处理文件未找到等情况
                    Log.e("LuaLoader", "Failed to load module: " + module, e);
                    throw new RuntimeException(e);
                }
            }
        });
        StateThreadTree.put(MainLua.getId(), MainLua.getPointer());
        return MainLua!=null;
    }

    public AbstractLua LuaNewState(){
        AbstractLua L=new Lua53();
        SDKInitLua(L.getPointer());
        return L;
    }


    public native long SDKInitLua(long luaState);
}