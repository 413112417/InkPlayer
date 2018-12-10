//
// Created by hexuren on 18-12-7.
//

#include "InkDemux.h"
#include "InkLog.h"

bool InkDemux::open(const char *url) {

    int re = avformat_open_input(&fc, url, 0, 0);
    if(re != 0) {
        LOGE("打开失败: %s", av_err2str(re));
        return false;
    }
    LOGI("打开成功");
    getVideoParameters();
    getAudioParameters();
    return true;
}

DecodeParameters InkDemux::getVideoParameters() {
    if(!fc) {
        LOGE("getVideoParameters failed! fc is null");
        return DecodeParameters();
    }
    int re = av_find_best_stream(fc, AVMEDIA_TYPE_VIDEO, -1, -1, 0, 0);
    if(re < 0) {
        LOGE("av_find_best_stream failed!");
        return DecodeParameters();
    }
    videoStream = re;
    DecodeParameters decodeParameters;
    decodeParameters.param = fc->streams[re]->codecpar;
    return decodeParameters;
}

DecodeParameters InkDemux::getAudioParameters() {
    if(!fc) {
        LOGE("getVideoParameters failed! fc is null");
        return DecodeParameters();
    }
    int re = av_find_best_stream(fc, AVMEDIA_TYPE_AUDIO, -1, -1, 0, 0);
    if(re < 0) {
        LOGE("av_find_best_stream failed!");
        return DecodeParameters();
    }
    audioStream = re;
    DecodeParameters decodeParameters;
    decodeParameters.param = fc->streams[re]->codecpar;
    return decodeParameters;
}

InkData InkDemux::read() {
    if(!fc) return InkData();
    InkData data;
    AVPacket *pkt = av_packet_alloc();
    int re = av_read_frame(fc, pkt);
    if(re != 0) {
        av_packet_free(&pkt);
        return InkData();
    }
    LOGI("packet size is: %d pts is: %lld", pkt->size, pkt->pts);
    data.data = (unsigned char *) pkt;
    data.size = pkt->size;
    if(pkt->stream_index == audioStream) {
        data.isAudio = true;
    } else if(pkt->stream_index == videoStream) {
        data.isAudio = false;
    } else {
        av_packet_free(&pkt);
        return InkData();
    }
    return data;
}

InkDemux::InkDemux() {
    static bool isFirst = true;
    if(isFirst) {
        isFirst = false;

        //注册所有封装器
        av_register_all();
        LOGI("注册所有封装器成功");

        //注册所有解码器
        avcodec_register_all();
        LOGI("注册所有解码器成功");

        //初始化网络
        avformat_network_init();
        LOGI("初始化网络成功");
    }
};