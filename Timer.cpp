#include "Timer.h"

#include <iostream>

Timer::Timer() {
    this->timeStarted=0;
    this->timeEnded=0;
}
int Timer::start() {
    this->timeStarted=clock();
    return 1;
}
int Timer::stop() {
    this->timeEnded=clock();
    return 1;
}
int Timer::result() {
    return (timeEnded-timeStarted)/double(CLOCKS_PER_SEC)*1000;
}
void Timer::reset() {
    this->timeStarted=0;
    this->timeEnded=0;
}
bool Timer::testTimer() {
    if (this->start()==1) {
        if (this->stop()==1) {
            this->reset();
            return true;
        }
    }
    return false;
}



