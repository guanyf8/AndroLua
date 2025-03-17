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

        //init
        parallelSDK.getInstance().SDKInit(C);

        parallelSDK.getInstance().luaRunOnMain("test/worker_thread_invoke");
        parallelSDK.getInstance().luaRunOnMain("test/task_thread_test");
        parallelSDK.getInstance().luaRunOnMain("test/java_object_callback");

        // Example of a call to a native method
        TextView tv = binding.sampleText;
        String content="hello world from c++!!!!!";
        tv.setText(content);
    }
}