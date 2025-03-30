package com.lockheed.parallelLJ;

import android.util.Log;

import java.util.HashMap;
import java.util.Map;

public class Util {
    static class message{
        int mmm=666;
    }
    public static void testComplex(Map<?,?> picPath, boolean dolateAfterSave, final callback cb) {
        Thread t = new Thread(new Runnable() {
            @Override
            public void run() {
                Map<String, Object> ret = new HashMap<>();
                ret.put("code", "2333");
                ret.put("msg", "yeah!");
//-个内嵌map
                ret.put("messageClass", new HashMap<String, message>());
                ((Map) ret.get("messageClass")).put("instance", new message());

                ret.put("testclass", new JustForFun("Jack", 999));
                Log.i("callback", "I have imvoke the right function");
                cb.callbackFunction(ret);
            }
        });
        t.start();
    }
}
