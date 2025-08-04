#pragma once

class Clock {
private:
    // Time in years
    float currentTime = 0.0f;
    float timeStep;  // How many years to go forward

    // How long to delay each tick by in seconds
    float delay = 0.5f;

public:
    explicit Clock(const float stepSize) {
        timeStep = stepSize;
    }

    void tick() {
        currentTime += timeStep;
    }

    float now() const {
        return currentTime;
    }

    void reset() {
        currentTime = 0.0f;
    }
};