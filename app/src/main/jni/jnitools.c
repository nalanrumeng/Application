#include <jni.h>
#include <android/log.h>
#include <stdio.h>
#include <stdlib.h>
#include<sys/types.h>
#include<dirent.h>
#include<unistd.h>


jint addNumber(JNIEnv *env, jclass clazz, jint a, jint b);

jint subNumber(JNIEnv *env, jclass clazz, jint a, jint b);

jint mulNumber(JNIEnv *env, jclass clazz, jint a, jint b);

jint divNumber(JNIEnv *env, jclass clazz, jint a, jint b);

jstring getData(JNIEnv *env, jclass clazz);

jstring setData(JNIEnv *env,jclass clazz, jstring value);


JNIEXPORT jint JNI_OnLoad(JavaVM *vm, void *reserved) {

    //打印日志，说明已经进来了
    __android_log_print(ANDROID_LOG_DEBUG, "JNITag", "enter jni_onload");

    JNIEnv *env = NULL;
    jint result = -1;

    // 判断是否正确
    if ((*vm)->GetEnv(vm, (void **) &env, JNI_VERSION_1_6) != JNI_OK) {
        return result;
    }

    //注册四个方法，注意签名
    const JNINativeMethod method[] = {
            {"add",     "(II)I",                (void *) addNumber},
            {"sub",     "(II)I",                (void *) subNumber},
            {"mul",     "(II)I",                (void *) mulNumber},
            {"div",     "(II)I",                (void *) divNumber},
            {"getData", "()Ljava/lang/String;", (void *) getData},
            {"setData", "(Ljava/lang/String;)Ljava/lang/String;", (void *) setData}
    };

    //找到对应的JNITools类
    jclass jClassName = (*env)->FindClass(env, "com/huige/jni/test/JNITools");

    //开始注册
    jint ret = (*env)->RegisterNatives(env, jClassName, method, 6);

    //如果注册失败，打印日志
    if (ret != JNI_OK) {
        __android_log_print(ANDROID_LOG_DEBUG, "JNITag", "jni_register Error");
        return -1;
    }

    return JNI_VERSION_1_6;
}




jint addNumber(JNIEnv *env, jclass clazz, jint a, jint b) {
    return a + b;
}

jint subNumber(JNIEnv *env, jclass clazz, jint a, jint b) {
    return a - b;
}

jint mulNumber(JNIEnv *env, jclass clazz, jint a, jint b) {
    return a * b;
}

jint divNumber(JNIEnv *env, jclass clazz, jint a, jint b) {
    return a / b;
}

jstring getData(JNIEnv *env, jclass clazz) {
    return (*env)->NewStringUTF(env, "sd/caee/eee");
}

jstring setData(JNIEnv *env, jclass clazz,jstring value){
    const char *nativeString = (*env)->GetStringUTFChars(env,value, 0);
    char * extraString = "www";
//    int natvieStringLen = strlen(nativeString);
//    int extraStringLen = strlen(nativeString);
    char * result = malloc(strlen(nativeString)+strlen(extraString)+1);
    __android_log_print(ANDROID_LOG_DEBUG, "JNITag", "result1");
    strcpy(result,nativeString);
    strcat(result, extraString);
    __android_log_print(ANDROID_LOG_DEBUG, "JNITag", "result2");
    __android_log_print(ANDROID_LOG_DEBUG, "JNITag", "result3");
    (*env)->ReleaseStringUTFChars(env,value, nativeString);
    return (*env)->NewStringUTF(env, result);
}


