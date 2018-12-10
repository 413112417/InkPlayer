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
    return true;
}

InkData InkDemux::read() {
    if(!fc) return InkData();
    InkData inkData;
    AVPacket *pkt = av_packet_alloc();
    int re = av_read_frame(fc, pkt);
    if(re != 0) {
        av_packet_free(&pkt);
        return InkData();
    }
    LOGI("packet size is: %d pts is: %d", pkt->size, pkt->pts);
    inkData.data = (unsigned char *) pkt;
    inkData.size = pkt->size;
    return inkData;
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