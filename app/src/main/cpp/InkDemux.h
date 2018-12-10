//
// Created by hexuren on 18-12-7.
//

#ifndef INKPLAYER_INKDEMUX_H
#define INKPLAYER_INKDEMUX_H

#include "IDemux.h"
extern "C" {
#include <libavformat/avformat.h>
}

class InkDemux : public IDemux {

public:

    InkDemux();

    /**
     * 打开文件或者流媒体 支持rtsp rtmp http
     * @param url
     * @return
     */
    virtual bool open(const char *url);

    /**
     * 获取视频参数
     */
    virtual DecodeParameters getVideoParameters();

    /**
     * 获取音频参数
     */
    virtual DecodeParameters getAudioParameters();

    /**
     * 读取一帧数据,数据由调用者清理
     * @return
     */
    virtual InkData read();

private:
    AVFormatContext *fc = 0;
    int audioStream = 1;
    int videoStream = 0;
};


#endif //INKPLAYER_INKDEMUX_H
