package com.lockheed.parallelsdk;

import static android.webkit.ConsoleMessage.MessageLevel.LOG;

import android.os.Handler;
import android.os.HandlerThread;
import android.os.Looper;
import android.util.Log;

import org.jetbrains.annotations.NotNull;

import java.nio.Buffer;

import party.iroiro.luajava.AbstractLua;
import party.iroiro.luajava.LuaException;
import party.iroiro.luajava.lua53.Lua53;

public class SafeLua53 extends Lua53 {
    Looper looper;
    HandlerThread mHandlerThread;;
    public Handler _handler;

    public SafeLua53(){
        super();
        mHandlerThread= new HandlerThread("Lua"+getId());
        mHandlerThread.start();
        _handler = new Handler( mHandlerThread.getLooper() );

    }

    public SafeLua53(Looper looper){
        super();
        this.looper=looper;
        _handler = new Handler(looper);
    }

    public SafeLua53(long L, int id, AbstractLua main){
        super(L,id,main);
        looper=Looper.myLooper();
        if(_handler==null) {
            _handler = new Handler(Looper.getMainLooper());
        }else{
            _handler = new Handler(looper);
        }
    }

    private void call_parent_run(String script)throws LuaException {
        super.run(script);
    }

    private void call_parent_run(Buffer buffer,String name)throws LuaException {
        super.run(buffer,name);
    }

    @Override
    public void run(String script) throws LuaException {
        Log.d("run"+getId(),"prerun");
        while(_handler==null);
        Log.d("run"+getId(),"pass while");
        _handler.post(new Runnable() {
            @Override
            public void run() {
                Log.d("Lua"+String.valueOf(getId()),"executing script");
                call_parent_run(script);
            }
        });
    }

    @Override
    public void run(Buffer buffer,String name)throws LuaException{
        _handler.post(new Runnable() {
            @Override
            public void run() {
                Log.d("Lua"+String.valueOf(getId()),"executing script");
                call_parent_run(buffer, name);
            }
        });
    }
}
