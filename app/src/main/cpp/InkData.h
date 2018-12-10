//
// Created by hexuren on 18-12-7.
//

#ifndef INKPLAYER_INKDATA_H
#define INKPLAYER_INKDATA_H


struct InkData {
    unsigned char *data = 0;
    int size = 0;
    bool isAudio = false;

    /**
     * 清理数据
     */
    void drop();
};


#endif //INKPLAYER_INKDATA_H
