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

    // Move currentTime forward one timeStep
    void tick();

    float now() const;
    void reset();
};
