// Copyright 2021 Artyom Lavrov

#include "TimedDoor.h"
#include <iostream>

TimedDoor::TimedDoor(unsigned int _sec)
    : open(false), sec(_sec) {
    dtAdapter = new DoorTimeAdapter(*this);
}

void TimedDoor::unlock() {
    open = true;
    Timer timer;
    timer.RegistTimer(*dtAdapter, sec);
}

void TimedDoor::lock() {
    open = false;
}

bool TimedDoor::isOpen() {
    return open;
}

void TimedDoor::throwState() {
    if (isOpen()) {
        throw std::string("the door is opened!");
    } else {
        throw std::string("the door is closed!");
    }
}

DoorTimeAdapter::DoorTimeAdapter(const TimedDoor& _tDoor)
    : tDoor(_tDoor) {
}

void TimedDoor::DoorTimeOut() const {
    throw std::string("close the door!");
}

void DoorTimeAdapter::Timeout() const {
    tDoor.DoorTimeOut();
}

void Timer::RegistTimer(const DoorTimeAdapter& _dtAdapter, unsigned int _sec) {
    SleepTimer(_sec);
    
    _dtAdapter.Timeout();
}

void Timer::SleepTimer(unsigned int _sec) {
    time_t end = time(nullptr) + _sec;
    
    while (end - time(nullptr)) {
    }
}
