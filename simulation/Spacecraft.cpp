#include "Spacecraft.h"
#include "Calculator.h"

#include <iostream>

void Spacecraft::launch(const float &departTime) {
    departureTime = departTime;

    totalDistance = Calculator::calcDistance(origin, destination);
    this->travelTime = velocity / totalDistance;
    this->arrivalTime = departureTime + travelTime;

    enRoute = true;
}

void Spacecraft::launch(const float &departTime, const float &distance) {
    departureTime = departTime;

    totalDistance = distance * LIGHT_YEAR;
    this->travelTime = static_cast<float>(velocity / totalDistance);
    this->arrivalTime = departureTime + travelTime;

    enRoute = true;
}
void Spacecraft::getDirectionVector() {
    // Computes the normalized direction vector from origin to destination.
    // This unit vector indicates the direction of motion for each dimension and the distance that `Spacecraft` travels
    // in each `timeStep`

    for (int i = 0; i < origin->position.size(); ++i) {
        float value = destination->position[i] - origin->position[i];
        directionVector.push_back(static_cast<float>(value / totalDistance));
    }
}

void Spacecraft::updatePosition(const double currentTime) {
    if (directionVector.size() == 0) {
        std::cerr << "Spacecraft::updatePosition() : Spacecraft.directionVector has a length of 0." << "\n";
        return;
    }

    // Check if arrivalTime equals currentTime
    if (currentTime >= arrivalTime) {
        enRoute = false;
        arrived = true;
        return;
    }

    for (int i = 0; i < position.size(); ++i) {
        this->position[i] = origin->position[i] + (directionVector[i] * (currentTime - departureTime) * velocity);
    }
}
