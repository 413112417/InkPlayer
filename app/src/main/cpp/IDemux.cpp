//
// Created by hexuren on 18-12-7.
//

#include "IDemux.h"

void IDemux::run() {
    while (!isExit) {
        InkData data = read();
        if(data.size > 0) {
            notify(data);
        }
    }
}