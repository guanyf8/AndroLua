package com.lockheed.parallelLJ;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Context;
import android.os.Bundle;
import android.widget.Button;
import android.widget.TextView;
import android.widget.Toast;

import com.lockheed.androlua.androLuaSDK;
import com.lockheed.parallelLJ.databinding.ActivityMainBinding;

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
        androLuaSDK.getInstance().SDKInit(C);

        setContentView(R.layout.activity_main);

        // 获取按钮引用
        Button btn1 = findViewById(R.id.btn1);
        Button btn2 = findViewById(R.id.btn2);
        Button btn3 = findViewById(R.id.btn3);
        Button btn4 = findViewById(R.id.btn4);
        Button btn5 = findViewById(R.id.btn5);
        Button btn6 = findViewById(R.id.btn6);
        Button btn7 = findViewById(R.id.btn7);

        // 按钮1点击事件 - 显示Toast
        btn1.setOnClickListener(v -> {
            androLuaSDK.getInstance().luaRunOnMain("test/worker_thread_invoke");
        });

        // 按钮2点击事件 - 跳转新页面
        btn2.setOnClickListener(v -> {
            androLuaSDK.getInstance().luaRunOnMain("test/task_thread_test");
        });

        // 按钮3点击事件 - 改变背景颜色
        btn3.setOnClickListener(v -> {
            androLuaSDK.getInstance().luaRunOnMain("test/shared_set");
        });

        // 按钮4点击事件 - 关闭当前页面
        btn4.setOnClickListener(v -> {
            androLuaSDK.getInstance().luaRunOnMain("test/cross_vm_ffi");
        });

        btn5.setOnClickListener(v -> {
            androLuaSDK.getInstance().luaRunOnMain("test/pressure1");
        });

        btn6.setOnClickListener(v -> {
            androLuaSDK.getInstance().luaRunOnMain("test/pressure2");
        });

        btn7.setOnClickListener(v -> {
            androLuaSDK.getInstance().luaRunOnMain("test/create_and_close");
        });


        // Example of a call to a native method
        TextView tv = binding.sampleText;
        String content="hello world from c++!!!!!";
        tv.setText(content);
    }
}