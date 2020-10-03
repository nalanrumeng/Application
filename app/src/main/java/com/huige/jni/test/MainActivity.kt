package com.huige.jni.test

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.util.Log

class MainActivity : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        val tag = javaClass.simpleName
        setContentView(R.layout.activity_main)
        val count = JNITools.add(3,5)
        Log.i(tag,"count:$count")
        val data = JNITools.getData()
        Log.i(tag,"getData:${data}")
        val data1 = JNITools.setData("3443")
        Log.i(tag,"setData:${data1}")
    }
}