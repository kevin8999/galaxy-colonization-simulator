#pragma once

#include "Star.h"
#include "Calculator.h"

// Speed of light in meters per second
const double SPEED_OF_LIGHT = 299'792'458;

struct Spacecraft {
    unsigned int id;
    Star* origin = nullptr;
    Star* destination = nullptr;

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

    Spacecraft(unsigned int& id, Star* origin, Star* destination, float& departureTime, float distance) {
        this->id = id;
        this->origin = origin;
        this->destination = destination;

        // Launch at departureTime
        this->launch(departureTime, distance);
    }

    // TODO: Calculate velocity given a star's luminosity

    void launch(const float& departTime);
    void launch(const float& departTime, const float& distance);

};