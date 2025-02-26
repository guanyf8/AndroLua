package com.lockheed.parallelLJ;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.util.Log;
import android.widget.TextView;

import com.lockheed.parallelLJ.databinding.ActivityMainBinding;

import org.jetbrains.annotations.Nullable;

import java.nio.Buffer;

import party.iroiro.luajava.AbstractLua;
import party.iroiro.luajava.ClassPathLoader;
import party.iroiro.luajava.ExternalLoader;
import party.iroiro.luajava.Lua;
import party.iroiro.luajava.LuaNatives;
import party.iroiro.luajava.lua53.Lua53;
import party.iroiro.luajava.lua53.Lua53Natives;

public class MainActivity extends AppCompatActivity {

    // Used to load the 'parallelLJ' library on application startup.
    static {
        System.loadLibrary("parallelLJ");
    }

    private ActivityMainBinding binding;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        binding = ActivityMainBinding.inflate(getLayoutInflater());
        setContentView(binding.getRoot());
        AbstractLua L=new Lua53();
        LuaNatives n=L.getLuaNatives();
        L.setExternalLoader(new ExternalLoader() {
            private String parentPath="./LuaScript";
            @Override
            public @Nullable Buffer load(String module, Lua L) {
                String filepath=parentPath+module;
                Buffer b = null;
                return b;
            }
        });
//        L.run(L.loadExternal("A.lua"),"test");
//        Log.i("hello","hello");
        L.run("local a=java.import('android.util.Log')\n" +
                "\n" +
                "a:i(\"tset\",\"hello from the lua\")");



        // Example of a call to a native method
        TextView tv = binding.sampleText;
        tv.setText(stringFromJNI());
    }

    /**
     * A native method that is implemented by the 'parallelLJ' native library,
     * which is packaged with this application.
     */
    public native String stringFromJNI();
}