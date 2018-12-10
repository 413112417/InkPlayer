//
// Created by xjh on 18-12-10.
//

#ifndef INKPLAYER_IDECODE_H
#define INKPLAYER_IDECODE_H

#include <list>
#include "DecodeParameters.h"
#include "IObserver.h"

/**
 * 解码接口,支持硬解码
 */
class IDecode : public IObserver {
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
     * 从线程中获取解码结果 再次调用会复用上次空间,线程不安全
     */
    virtual InkData receiveFrame() = 0;

    /**
     * 接收到解封装的数据
     */
    virtual void update(InkData data);

    /**
     * 判断当前解码器类型
     */
    bool isAudio = false;

    /**
     * 最多缓存帧
     */
    int maxCacheSize = 100;

protected:
    virtual void run();

    /**
     * 缓冲帧
     */
    std::list<InkData> cacheList;
    std::mutex cacheMut;
};


#endif //INKPLAYER_IDECODE_H
