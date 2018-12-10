//
// Created by xjh on 18-12-10.
//

#include "IDecode.h"
#include "InkLog.h"

void IDecode::update(InkData data) {
    if(data.isAudio != isAudio) {
        return;
    }
    while (!isExit) {
        cacheMut.lock();
        if(cacheList.size() < maxCacheSize) {
            cacheList.push_back(data);
            cacheMut.unlock();
            break;
        }
        cacheMut.unlock();
        ThreadSleep(1);
    }
}

void IDecode::run() {
    while (!isExit) {
        cacheMut.lock();
        if(cacheList.empty()) {
            cacheMut.unlock();
            ThreadSleep(1);
            continue;
        }
        //取出缓冲
        InkData data = cacheList.front();
        cacheList.pop_front();

        if(this->sendPacket(data)) {
            while (!isExit) {
                //获取解码数据
                InkData frame = receiveFrame();
                if(!frame.data) {
                    break;
                } else {
                    //发送给观察者
                    LOGI("receive frame size=%d", frame.size);
                    this->notify(frame);
                }
            }
        }
        data.drop();
        cacheMut.unlock();
    }
}