#include "Spacecraft.h"
#include "Calculator.h"

#include <iostream>

void Spacecraft::launch(const float &departTime) {
    departureTime = departTime;

    totalDistance = Calculator::calcDistance(origin, destination);
    this->travelTime = static_cast<float>(velocity / totalDistance);
    this->arrivalTime = departureTime + travelTime;

    enRoute = true;
}

void Spacecraft::launch(const float &departTime, const float &distance) {
    departureTime = departTime;

    totalDistance = distance;
    this->travelTime = static_cast<float>(velocity / totalDistance);
    this->arrivalTime = departureTime + travelTime;

    enRoute = true;
}
