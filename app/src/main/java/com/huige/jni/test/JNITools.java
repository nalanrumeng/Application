package com.huige.jni.test;

/**
 * Created by libai on 2018/4/12.
 */

public class JNITools {

    static {
        System.loadLibrary("jnidemo3");
    }

    //加法
    public static native int  add(int a,int b);

    //减法
    public static native int sub(int a,int b);

    //乘法
    public static native int mul(int a,int b);

    //除法
    public static native int div(int a,int b);

    public static native String getData();

    //java层传递字符串，native层对字符串进行加工返回
    public static native String setData(String value);


}
