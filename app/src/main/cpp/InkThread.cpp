//
// Created by hexuren on 18-12-9.
//

#include "InkThread.h"
#include "InkLog.h"

#include <thread>
using namespace std;

void InkSleep(int mis) {
    chrono::milliseconds du(mis);
    this_thread::sleep_for(du);
}

void InkThread::start() {
    isExit = false;
    thread th(&InkThread::threadMain, this);
    th.detach();
}

void InkThread::stop() {
    isExit = true;
    for(int i=0; i<200; i++) {
        if(!isRunning) {
            LOGI("停止线程成功");
            return;
        }
        InkSleep(1);
    }
    LOGD("停止线程超时");
}

void InkThread::run() {

}

void InkThread::threadMain() {
    isRunning = true;
    LOGI("线程函数进入");
    run();
    LOGI("线程函数退出");
    isRunning = false;
}