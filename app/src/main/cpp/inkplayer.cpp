#include <jni.h>
#include <string>

extern "C" {
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
#include <libavcodec/jni.h>
#include <libswscale/swscale.h>
#include <libswresample/swresample.h>
}

extern "C" JNIEXPORT jstring JNICALL
Java_pers_hexuren_inkplayer_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = avformat_configuration();
    return env->NewStringUTF(hello.c_str());
}
