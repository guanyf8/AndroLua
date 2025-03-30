package com.lockheed.androlua;

import android.os.Handler;
import android.os.Looper;
import android.util.Log;

import java.lang.reflect.InvocationHandler;
import java.lang.reflect.Method;
import java.lang.reflect.Proxy;
import java.util.Objects;

public class LuaCallbackDispatcher implements InvocationHandler {
    private Object callback;
    private Handler _handler;
    private String TAG="CallBackDispatcher";

    public LuaCallbackDispatcher(Object callback) {
        this.callback = callback;
        _handler=new Handler(Objects.requireNonNull(Looper.myLooper()));

    }

    public static Object bind(Object targetObject) {
        LuaCallbackDispatcher handler = new LuaCallbackDispatcher(targetObject);
        return Proxy.newProxyInstance(targetObject.getClass().getClassLoader(), targetObject.getClass().getInterfaces(), handler);
    }

    @Override
    public Object invoke(Object proxy, final Method method, final Object[] args) throws Throwable {
        Runnable runnable=new Runnable() {
            @Override
            public void run() {
                try {
                    method.invoke(callback, args);
                }catch (Exception e){
                    Log.i(TAG,"callback failed");
                }
            }
        };
        _handler.post(runnable);
        return null;
    }

}
