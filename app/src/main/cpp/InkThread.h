//
// Created by hexuren on 18-12-9.
//

#ifndef INKPLAYER_INKTHREAD_H
#define INKPLAYER_INKTHREAD_H

void InkSleep(int mis);

class InkThread {
public:
    //启动线程
    virtual void start();
    //安全停止现场
    virtual void stop();
    //入口主函数
    virtual void run();

protected:
    bool isExit = false;
    bool isRunning = false;

private:
    void threadMain();
};

#endif //INKPLAYER_INKTHREAD_H
