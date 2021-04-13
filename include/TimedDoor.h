// Copyright 2021 Artyom Lavrov

#ifndef INCLUDE_TIMEDDOOR_H_
#define INCLUDE_TIMEDDOOR_H_

#include <string>
#include <ctime>

class Door {
public:
    virtual bool isOpen() = 0;
    virtual void lock() = 0;
    virtual void unlock() = 0;
};

class DTAdapter;

class TDoor : public Door {
private:
    bool open;
    unsigned int sec;
    DTAdapter* dtAdapter;

public:
    explicit TDoor(unsigned int _sec);
    bool isOpen() override;
    void throwState();
    void lock() override;
    void unlock() override;
    void DoorTimeOut() const;
};

class TClient {
public:
    virtual void Timeout() const = 0;
};

class DTAdapter : public TClient {
private:
    const TDoor& tDoor;
public:
    explicit DTAdapter(const TDoor& _tDoor);
    void Timeout() const override;
};


class Timer {
public:
    void RegistTimer(const DTAdapter& _dtAdapter, unsigned int _sec);
    void SleepTimer(unsigned int _sec);
};

#endif  // INCLUDE_TIMEDDOOR_H_

