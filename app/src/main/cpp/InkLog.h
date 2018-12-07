//
// Created by hexuren on 18-12-7.
//

#ifndef INKPLAYER_INKLOG_H
#define INKPLAYER_INKLOG_H


class InkLog {

};

#ifdef ANDROID
#include <android/log.h>
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG,"InkPlayer",__VA_ARGS__)
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO,"InkPlayer",__VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR,"InkPlayer",__VA_ARGS__)
#else
#define LOGD(...) printf("InkPlayer",__VA_ARGS__)
#define LOGI(...) printf("InkPlayer",__VA_ARGS__)
#define LOGE(...) printf("InkPlayer",__VA_ARGS__)
#endif

#endif //INKPLAYER_INKLOG_H
