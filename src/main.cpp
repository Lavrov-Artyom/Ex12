// Copyright 2021 Artyom Lavrov

#include <iostream>
#include <string>
#include "TimedDoor.h"

int main() {
    TDoor* Door = new TDoor(5);

    try {
        Door->unlock();
        Door->throwState();
    }

    catch (std::string Note) {
        std::cout << Note << std::endl;
    }
    return 0;
}