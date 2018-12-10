//
// Created by xjh on 18-12-10.
//

extern "C" {
#include <libavcodec/avcodec.h>
}
#include "InkDecode.h"
#include "InkLog.h"

bool InkDecode::open(DecodeParameters parameters) {
    if(!parameters.param)
        return false;
    AVCodecParameters *p = parameters.param;
    //1.查找解码器
    AVCodec *cd = avcodec_find_decoder(p->codec_id);
    if(!cd) {
        LOGE("avcodec_find_decoder %d failed", p->codec_id);
    }
    LOGI("avcodec_find_decoder success");
    //2.创建上下文,并复制参数
    codec = avcodec_alloc_context3(cd);
    avcodec_parameters_to_context(codec, p);

    codec->thread_count = 8;

    //3.打开解码器
    int re = avcodec_open2(codec, 0, 0);
    if(re != 0) {
        LOGE("avcodec_open2 failed");
        return false;
    }

    if(codec->codec_type == AVMEDIA_TYPE_VIDEO) {
        isAudio = false;
    } else {
        isAudio = true;
    }
    LOGI("avcodec_open2 success");
    return true;
}

/**
 * 发送数据到解码线程
 */
bool InkDecode::sendPacket(InkData data) {
    if(data.size <= 0 || !data.data) {
        return false;
    }

    if(!codec) {
        return false;
    }

    int re = avcodec_send_packet(codec, reinterpret_cast<const AVPacket *>(data.data));
    if(re != 0) {
        return false;
    }
    return true;
}

/**
 * 从线程中获取解码结果
 */
InkData InkDecode::receiveFrame() {
    if(!codec) {
        return InkData();
    }
    int re = avcodec_receive_frame(codec, frame);
    if(re != 0) {
        return InkData();
    }

    InkData data;
    data.data = reinterpret_cast<unsigned char *>(frame);
    if(codec->codec_type == AVMEDIA_TYPE_VIDEO) {
        data.size = (frame->linesize[0]
                    + frame->linesize[1]
                    + frame->linesize[2]) * frame->height;
    }

    return data;
}