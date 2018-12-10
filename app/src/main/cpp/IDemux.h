//
// Created by hexuren on 18-12-7.
//

#ifndef INKPLAYER_IDEMUX_H
#define INKPLAYER_IDEMUX_H


#include "InkData.h"
#include "IObserver.h"
#include "DecodeParameters.h"

/**
 * 解封装接口
 */
class IDemux : public IObserver {

public:

    /**
     * 打开文件或者流媒体 支持rtsp rtmp http
     * @param url
     * @return
     */
    virtual bool open(const char *url) = 0;

    /**
     * 获取视频参数
     */
    virtual DecodeParameters getVideoParameters() = 0;

    /**
     * 获取音频参数
     */
    virtual DecodeParameters getAudioParameters() = 0;

    /**
     * 读取一帧数据,数据由调用者清理
     * @return
     */
    virtual InkData read() = 0;

protected:
    virtual void run();
};


#endif //INKPLAYER_IDEMUX_H
