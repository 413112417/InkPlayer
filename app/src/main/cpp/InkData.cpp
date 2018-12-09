//
// Created by hexuren on 18-12-7.
//

#include "InkData.h"
extern "C" {
#include <libavformat/avformat.h>
}

void InkData::drop() {
    if(!data) return;
    av_packet_free((AVPacket **) &data);
    data = 0;
    size = 0;
}