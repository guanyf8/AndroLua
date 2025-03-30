package com.lockheed.androlua;

import android.content.Context;
import android.os.Looper;
import android.util.Log;

import party.iroiro.luajava.AbstractLua;
import party.iroiro.luajava.lua53.Lua53;
import party.iroiro.luajava.value.LuaValue;

//需要在主线程进行初始化，需要MainLua来做一些事情
public class androLuaSDK {
    static androLuaSDK instance=null;
    SafeLua53 MainLua;   //记录SDK持有的主lua state

    long MainMsgQueue;
    Context C;
    // Used to load the 'androlua' library on application startup.
    static {
        System.loadLibrary("androlua");
    }

    private androLuaSDK() {
        // 防止反射破坏单例
        if (instance != null) {
            throw new IllegalStateException("androLuaSDK instance already created");
        }
    }

    public static androLuaSDK getInstance() {
        if (instance == null) {
            // 通过同步块来确保线程安全
            synchronized (androLuaSDK.class) {
                if (instance == null) {
                    instance = new androLuaSDK();
                }
            }
        }
        return instance;
    }

    public boolean SDKInit(Context context){
        C=context;
        MainLua= (SafeLua53) LuaNewState(Looper.getMainLooper());
//        StateThreadTree.put(MainLua.getId(), MainLua.getPointer());
        MainLua.getGlobal("tqueue");
        MainMsgQueue=MainLua.getLuaNatives().
                    lua_touserdata(MainLua.getPointer(),
                            -1);
        MainLua.pop(1);
        return MainLua!=null;
    }

    public void luaRunOnMain(String trunk){
        MainLua._handler.post(new Runnable() {
           @Override
           public void run() {
               Log.d("Lua"+String.valueOf(MainLua.getId()),"init done");
               MainLua.loadExternal(trunk);
               MainLua.pCall(0,0);
           }
       });
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

    public void closeLuaState(AbstractLua L){;
        ((SafeLua53)L).mHandlerThread.quitSafely();
        L.close();
    }

    public long luaNewStateC(){
        AbstractLua L=new SafeLua53();
        L.setExternalLoader(new DefaultLuaLoader(C));
        L.openLibraries();
        return SDKLuaInit(L.getPointer(),L.getId());
    }

    public void closeLuaStateC(int id){
        AbstractLua L=AbstractLua.getInstance(id);
        ((SafeLua53)L).mHandlerThread.quitSafely();
        L.close();
    }

    //没有Looper
    public long luaNewLightStateC(){
        AbstractLua L=new Lua53();
        L.setExternalLoader(new DefaultLuaLoader(C));
        L.openLibraries();
        return SDKLightLuaInit(L.getPointer(),L.getId());
    }

    public void closeLightStateC(int id){
        AbstractLua L=AbstractLua.getInstance(id);
        L.close();
    }

    public static void Tick(int id){
        AbstractLua L=AbstractLua.getInstance(id);
//        Log.d("Tick","before"+L.getId());
        //这里异步扔走了
//        if(L==null)return;
        ((SafeLua53)L).run("local a=require(\"cross_vm\")" +
                "a.executer(_thread.execute())");
    }

    private long getFirstContact(int id){
        AbstractLua L=AbstractLua.getInstance(id);
        long lS=L.getPointer();
//        Log.d("Tick","before"+L.getId());
        //这里异步扔走了
        ((SafeLua53)L)._handler.post(new Runnable() {
            @Override
            public void run() {
                FirstContact(lS,MainMsgQueue);
            }
        });
        return MainMsgQueue;
    }

    public native void FirstContact(long luaState,long queue);
    public native long SDKLuaInit(long luaState,int id);

    public native long SDKLightLuaInit(long luaState,int id);
}