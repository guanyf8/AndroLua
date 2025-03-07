package com.lockheed.parallelLJ;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Context;
import android.content.res.AssetFileDescriptor;
import android.content.res.AssetManager;
import android.os.Bundle;
import android.os.Looper;
import android.util.Log;
import android.widget.TextView;

import com.lockheed.parallelLJ.databinding.ActivityMainBinding;

import org.jetbrains.annotations.Nullable;

import java.io.ByteArrayOutputStream;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.nio.Buffer;
import java.nio.ByteBuffer;
import java.nio.channels.FileChannel;
import java.util.Timer;

import party.iroiro.luajava.AbstractLua;
import party.iroiro.luajava.ClassPathLoader;
import party.iroiro.luajava.ExternalLoader;
import party.iroiro.luajava.Lua;
import party.iroiro.luajava.LuaNatives;
import party.iroiro.luajava.lua53.Lua53;
import party.iroiro.luajava.lua53.Lua53Natives;

import com.lockheed.parallelsdk.SafeLua53;
import com.lockheed.parallelsdk.parallelSDK;

public class MainActivity extends AppCompatActivity {

    // Used to load the 'parallelLJ' library on application startup.
    static {
        System.loadLibrary("parallelLJ");
    }

    private ActivityMainBinding binding;
    private Context C=null;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        binding = ActivityMainBinding.inflate(getLayoutInflater());
        setContentView(binding.getRoot());
        C=this.getApplicationContext();
        parallelSDK.getInstance().SDKInit(C);
        AbstractLua L1=parallelSDK.getInstance().LuaNewState();

        AbstractLua L2=parallelSDK.getInstance().LuaNewState();

//        Runnable r=new Runnable() {
//            @Override
//            public void run() {
//
//            }
//        };
//        Thread t=new Thread(r);
//        t.start();
        long start=System.currentTimeMillis();
        while(((SafeLua53) L1)._handler==null ||((SafeLua53) L2)._handler==null);
        long end=System.currentTimeMillis();

        Log.i("Time",String.valueOf(end-start));

        ((SafeLua53) L1)._handler.post(new Runnable() {
               @Override
               public void run() {
                   Log.d("Lua"+String.valueOf(L1.getId()),"init done");
                   L1.loadExternal("test/java_object_send");
                   L1.pCall(0,0);
               }
           }
        );

        ((SafeLua53)L2)._handler.post(new Runnable() {
            @Override
            public void run() {
                Log.d("Lua"+String.valueOf(L2.getId()),"init done");
//                L2.loadExternal("d_s");
//                L2.pCall(0,0);
            }
        });
        // Example of a call to a native method
        TextView tv = binding.sampleText;
        String content="hello world from c++!!!!!";
        tv.setText(content);
    }
}