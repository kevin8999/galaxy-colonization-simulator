#pragma once

#include "Star.h"
#include "Calculator.h"

// Speed of light in meters per second
const double SPEED_OF_LIGHT = 299'792'458;

struct Spacecraft {
    unsigned int id;
    Star* origin;
    Star* destination;

    // Values                 // Units
    /************************************/
    float  departureTime;     // Years
    float  arrivalTime;       // Years
    float  travelTime;        // Years
    double totalDistance;     // Meters
    // Velocity is set to the speed of Voyager 1
    float  velocity = 17080;  // Meters per Second

    // Area of sail pushing spacecraft in meters squared
    float sailArea = 100;

    // States if the Spacecraft object is currently heading to destination
    bool enRoute = false;

    Spacecraft() {
        origin = nullptr;
        enRoute = false;
        totalDistance = 0;

    }

    Spacecraft(unsigned int& id, Star* origin, Star* destination, float& departureTime) {
        this->id = id;
        this->origin = origin;
        this->destination = destination;

        // Launch at departureTime
        this->launch(departureTime);
    }

    float calcVelocity() {
        // TODO: Calculate velocity given a star's luminosity
        return velocity;
    }

    void launch(const float& departTime) {
        departureTime = departTime;

        totalDistance = Calculator::calcDistance(origin, destination);
        this->travelTime = static_cast<float>(velocity / totalDistance);
        this->arrivalTime = departureTime + travelTime;

        enRoute = true;
    }
};