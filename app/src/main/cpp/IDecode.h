//
// Created by xjh on 18-12-10.
//

#ifndef INKPLAYER_IDECODE_H
#define INKPLAYER_IDECODE_H

#include "DecodeParameters.h"
#include "IObserver.h"

/**
 * 解码接口,支持硬解码
 */
class IDecode : IObserver {
public:
    /**
     * 打开解码器
     */
    virtual bool open(DecodeParameters parameters) = 0;

    /**
     * 发送数据到解码线程
     */
    virtual bool sendPacket(InkData data) = 0;

    /**
     * 从线程中获取解码结果
     */
    virtual InkData receiveFrame() = 0;
};


#endif //INKPLAYER_IDECODE_H
