package com.lockheed.androlua;

import android.content.Context;
import android.content.res.AssetFileDescriptor;
import android.content.res.AssetManager;
import android.util.Log;

import org.jetbrains.annotations.Nullable;

import java.io.FileInputStream;
import java.io.IOException;
import java.nio.Buffer;
import java.nio.ByteBuffer;
import java.nio.channels.FileChannel;

import party.iroiro.luajava.ExternalLoader;
import party.iroiro.luajava.Lua;

public class DefaultLuaLoader implements ExternalLoader {
    Context C;
    AssetManager assetManager;

    public DefaultLuaLoader(Context c){
        C=c;
        assetManager=C.getAssets();
    }

    @Override
    public @Nullable Buffer load(String module, Lua L) {
        String luaPath = module.replace('.', '/') + ".lua";

        try (AssetFileDescriptor fd = assetManager.openFd("SDK-lua/"+luaPath)) {
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
}
