package com.lockheed.parallelsdk;

import android.os.Handler;
import android.os.Looper;

import org.jetbrains.annotations.NotNull;

import java.nio.Buffer;

import party.iroiro.luajava.AbstractLua;
import party.iroiro.luajava.LuaException;
import party.iroiro.luajava.lua53.Lua53;

public class SafeLua53 extends Lua53 {
    Looper looper;
    public Handler _handler;

    public SafeLua53(){
        super();
        Thread t=new Thread(new Runnable() {
            @Override
            public void run() {
                Looper.prepare();
                looper=Looper.myLooper();
                _handler = new Handler(looper);
                Looper.loop();
            }
        });
        t.start();

    }

    public SafeLua53(Looper looper){
        super();
        this.looper=looper;
        if(_handler==null) {
            _handler = new Handler(Looper.getMainLooper());
        }else{
            _handler = new Handler(looper);
        }
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
        _handler.post(new Runnable() {
            @Override
            public void run() {
                call_parent_run(script);
            }
        });
    }

    @Override
    public void run(Buffer buffer,String name)throws LuaException{
        _handler.post(new Runnable() {
            @Override
            public void run() {
                call_parent_run(buffer, name);
            }
        });
    }
}
