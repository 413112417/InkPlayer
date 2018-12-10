//
// Created by xjh on 18-12-10.
//

#ifndef INKPLAYER_IOBSERVER_H
#define INKPLAYER_IOBSERVER_H


#include "InkData.h"
#include "InkThread.h"
#include <vector>
#include <mutex>

class IObserver : public InkThread {
public:
    //观察者接收数据函数
    virtual void update(InkData data) {}

    //添加观察者(线程安全)
    void addObserver(IObserver *obs);

    //通知所有观察者(线程安全)
    void notify(InkData data);

protected:
    std::vector<IObserver *> observers;
    std::mutex mux;
};


#endif //INKPLAYER_IOBSERVER_H
