//
// Created by xjh on 18-12-10.
//

#include "IObserver.h"

void IObserver::addObserver(IObserver *obs) {
    if(!obs)
        return;
    mux.lock();
    observers.push_back(obs);
    mux.unlock();
}

void IObserver::notify(InkData data) {
    mux.lock();
    for(int i=0; i<observers.size(); i++) {
        observers[i]->update(data);
    }
    mux.unlock();
}