#include "Clock.h"

void Clock::tick() {
    currentTime += timeStep;
}

float Clock::now() const {
    return currentTime;
}

void Clock::reset() {
    currentTime = 0.0f;
}