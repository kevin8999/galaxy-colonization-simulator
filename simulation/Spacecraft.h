#pragma once

#include <cmath>

#include "Star.h"

// Speed of light in meters per second
const float SPEED_OF_LIGHT = 299'792'458;
const double LIGHT_YEAR = 9.460730473 * std::pow(10, 15);

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

    bool arrived = false;

    std::vector<float> position;

    /*  directionVector the direction of travel as a normalized vector for each spatial dimension.
     *
     *  Each element corresponds to the rate of change in one dimension (x, y, z, etc.),
     *  scaled to ensure the ship moves with a length of velocity from the origin to the destination
     *
     *  For example, if the ship travels from origin A to destination B over time `t`, the
     *  position in dimension i is updated using:
     *
     *     position[i] = origin->position[i] + directionVector[i] * (currentTime - departureTime);
     *
     *  This allows the ship’s position to be updated linearly over time along the correct path.
     */
    std::vector<double> directionVector;

    bool print = true;

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

    Spacecraft(unsigned int& id, Star* origin, Star* destination, float& departureTime, double distance) {
        this->id = id;
        this->origin = origin;
        this->destination = destination;
        getDirectionVector();

        // Launch at departureTime
        this->launch(departureTime, distance);
    }

    // TODO: Calculate velocity given a star's luminosity

    void launch(const float& departTime);
    void launch(const float& departTime, const double& distance);

    void getDirectionVector();
    void updatePosition(const double currentTime);
};