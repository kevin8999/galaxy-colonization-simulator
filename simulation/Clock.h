#pragma once

class Clock {
private:
    // Time in years
    float currentTime = 0.0f;
    float timeStep;

public:
    explicit Clock(const float delta) {
        timeStep = delta;
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