#include <jni.h>
#include <string>
#include "InkLog.h"
#include "IDemux.h"
#include "InkDemux.h"
#include "IDecode.h"
#include "InkDecode.h"

extern "C" {
#include <android/log.h>
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
#include <libavcodec/jni.h>
#include <libswscale/swscale.h>
#include <libswresample/swresample.h>
}

extern "C"
JNIEXPORT void JNICALL
Java_pers_hexuren_inkplayer_InkPlayer_open(JNIEnv *env, jclass type, jstring path_) {
    const char *path = env->GetStringUTFChars(path_, 0);

    IDemux *demux = new InkDemux();

    bool re = demux->open(path);

    if(re) {
        IDecode *aDecode = new InkDecode();
        aDecode->open(demux->getAudioParameters());

        IDecode *vDecode = new InkDecode();
        vDecode->open(demux->getVideoParameters());

        demux->addObserver(aDecode);
        demux->addObserver(vDecode);

        demux->start();
        aDecode->start();
        vDecode->start();

        ThreadSleep(3000);
        demux->stop();
    }
    env->ReleaseStringUTFChars(path_, path);
}