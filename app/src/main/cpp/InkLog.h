//
// Created by hexuren on 18-12-7.
//

#ifndef INKPLAYER_INKLOG_H
#define INKPLAYER_INKLOG_H


class InkLog {

};

#ifdef ANDROID
#include <android/log.h>
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG,"Ink_LOG",__VA_ARGS__)
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO,"Ink_LOG",__VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR,"Ink_LOG",__VA_ARGS__)
#else
#define LOGD(...) printf("Ink_LOG",__VA_ARGS__)
#define LOGI(...) printf("Ink_LOG",__VA_ARGS__)
#define LOGE(...) printf("Ink_LOG",__VA_ARGS__)
#endif

#endif //INKPLAYER_INKLOG_H
