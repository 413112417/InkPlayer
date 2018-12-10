//
// Created by xjh on 18-12-10.
//

#ifndef INKPLAYER_INKDECODE_H
#define INKPLAYER_INKDECODE_H

#include "IDecode.h"

struct AVCodecContext;
struct AVFrame;
class InkDecode : public IDecode {
public:
    /**
     * 打开解码器
     */
    virtual bool open(DecodeParameters parameters);

    /**
     * 发送数据到解码线程
     */
    virtual bool sendPacket(InkData data);

    /**
     * 从线程中获取解码结果
     */
    virtual InkData receiveFrame();

protected:
    AVCodecContext *codec = 0;
    AVFrame *frame = 0;
};


#endif //INKPLAYER_INKDECODE_H
