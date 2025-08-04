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

void Spacecraft::launch(const float &departTime, const double &distance) {
    departureTime = departTime;

    totalDistance = distance;
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

    std::cout << "Spaceship " << id << " (" << origin->id << "->" << destination->id << ")\n";

    // Check if arrivalTime equals currentTime
    if (currentTime >= arrivalTime) {
        enRoute = false;
        arrived = true;

        if (print) {
            std::cout << "Spaceship " << this->id << " arrived at destination" << std::endl;
            std::cout << "\t Destination: " << destination->id << std::endl;
            std::cout << "\t Time: " << currentTime << std::endl;
            std::cout << "\t Distance: " << totalDistance << std::endl;
        }
        return;
    }

    for (int i = 0; i < position.size(); ++i) {
        this->position[i] = origin->position[i] + (directionVector[i] * (currentTime - departureTime) * velocity);
    }
}
