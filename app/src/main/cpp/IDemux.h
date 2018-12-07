//
// Created by hexuren on 18-12-7.
//

#ifndef INKPLAYER_IDEMUX_H
#define INKPLAYER_IDEMUX_H


#include "InkData.h"

/**
 * 解封装接口
 */
class IDemux {

public:

    /**
     * 打开文件或者流媒体 支持rtsp rtmp http
     * @param url
     * @return
     */
    virtual bool open(const char *url) = 0;

    /**
     * 读取一帧数据,数据由调用者清理
     * @return
     */
    virtual InkData read() = 0;
};


#endif //INKPLAYER_IDEMUX_H
