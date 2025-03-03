package com.lockheed.parallelLJ;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Context;
import android.content.res.AssetFileDescriptor;
import android.content.res.AssetManager;
import android.os.Bundle;
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

import party.iroiro.luajava.AbstractLua;
import party.iroiro.luajava.ClassPathLoader;
import party.iroiro.luajava.ExternalLoader;
import party.iroiro.luajava.Lua;
import party.iroiro.luajava.LuaNatives;
import party.iroiro.luajava.lua53.Lua53;
import party.iroiro.luajava.lua53.Lua53Natives;

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
        AbstractLua L1=parallelSDK.getInstance().LuaNewState();
        L1.setExternalLoader(new ExternalLoader() {
            AssetManager assetManager= C.getAssets();

            @Override
            public @Nullable Buffer load(String module, Lua L) {
                String luaPath = module.replace('.', '/') + ".lua";

                try (AssetFileDescriptor fd = assetManager.openFd(luaPath)) {
                    // 获取文件长度（直接内存需要预知大小）
                    long fileSize = fd.getLength();
                    if (fileSize > Integer.MAX_VALUE) {
                        throw new IOException("File too large: " + fileSize + " bytes");
                    }

                    // 创建直接内存缓冲区
                    ByteBuffer directBuffer = ByteBuffer.allocateDirect((int) fileSize);

                    // 使用NIO通道高效读取
                    try (FileInputStream fis = fd.createInputStream()) {
                        FileChannel channel = fis.getChannel();

                        // 一次性读取到直接内存（比循环read更高效）
                        while (directBuffer.hasRemaining()) {
                            if (channel.read(directBuffer) == -1) {
                                break;
                            }
                        }
                    }

                    // 切换为读取模式（position=0，limit=实际大小）
                    directBuffer.flip();
                    return directBuffer;
                } catch (IOException e) {
                    // 处理文件未找到等情况
                    Log.e("LuaLoader", "Failed to load module: " + module, e);
                    throw new RuntimeException(e);
                }
            }
        });
        AbstractLua L2=parallelSDK.getInstance().LuaNewState();
        L2.setExternalLoader(new ExternalLoader() {
            AssetManager assetManager= C.getAssets();

            @Override
            public @Nullable Buffer load(String module, Lua L) {
                String luaPath = module.replace('.', '/') + ".lua";

                try (AssetFileDescriptor fd = assetManager.openFd(luaPath)) {
                    // 获取文件长度（直接内存需要预知大小）
                    long fileSize = fd.getLength();
                    if (fileSize > Integer.MAX_VALUE) {
                        throw new IOException("File too large: " + fileSize + " bytes");
                    }

                    // 创建直接内存缓冲区
                    ByteBuffer directBuffer = ByteBuffer.allocateDirect((int) fileSize);

                    // 使用NIO通道高效读取
                    try (FileInputStream fis = fd.createInputStream()) {
                        FileChannel channel = fis.getChannel();

                        // 一次性读取到直接内存（比循环read更高效）
                        while (directBuffer.hasRemaining()) {
                            if (channel.read(directBuffer) == -1) {
                                break;
                            }
                        }
                    }

                    // 切换为读取模式（position=0，limit=实际大小）
                    directBuffer.flip();
                    return directBuffer;
                } catch (IOException e) {
                    // 处理文件未找到等情况
                    Log.e("LuaLoader", "Failed to load module: " + module, e);
                    throw new RuntimeException(e);
                }
            }
        });
        L1.loadExternal("java_object_send");
        L1.pCall(0,0);
        L2.loadExternal("java_object_recv");
        L2.pCall(0,0);
        // Example of a call to a native method
        TextView tv = binding.sampleText;
        String content="hello world from c++!!!!!";
        tv.setText(content);
    }
}