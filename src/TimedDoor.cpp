// Copyright 2021 Artyom Lavrov

#include "TimedDoor.h"
#include <iostream>

TDoor::TDoor(unsigned int _sec)
    : open(false), sec(_sec) {
    dtAdapter = new DTAdapter(*this);
}

void TDoor::lock() {
    open = false;
}

void TDoor::unlock() {
    open = true;
    Timer timer;
    timer.RegistTimer(*dtAdapter, sec);
}

bool TDoor::isOpen() {
    return open;
}

void TDoor::throwState() {
    if (isOpen()) {
        throw std::string("the door is opened!");
    }
    else {
        throw std::string("the door is closed!");
    }
}

void TDoor::DoorTimeOut() const {
    throw std::string("close the door!");
}

DTAdapter::DTAdapter(const TDoor& _tDoor)
    : tDoor(_tDoor) {
}

void DTAdapter::Timeout() const {
    tDoor.DoorTimeOut();
}

void Timer::RegistTimer(const DTAdapter& _dtAdapter,
    unsigned int _sec) {
    SleepTimer(_sec);
    _dtAdapter.Timeout();
}

void Timer::SleepTimer(unsigned int _sec) {
    time_t end = time(nullptr) + _sec;
    while (end - time(nullptr)) {
    }
}