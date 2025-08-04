#pragma once

class Clock {
private:
    // Time in years
    double currentTime = 0.0f;
    double timeStep;  // How many years to go forward

    // How long to delay each tick by in seconds
    float delay = 0.5f;

public:
    explicit Clock(const double stepSize) {
        timeStep = stepSize;
    }

    // Move currentTime forward one timeStep
    void tick();

    float now() const;
    void reset();
};
