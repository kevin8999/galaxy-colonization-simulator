#include "Star.h"

#include <iostream>

void Star::print() const {
    std::cout << "ID: " << id << std::endl;
    std::cout << "Position: " << "(";

    for (int i = 0; i < position.size() - 1; ++i)
        std::cout << position[i] << ", ";

    std::cout << position[position.size() - 1] << ")" << std::endl;

    std::cout << "Luminosity: " << solarLuminosity << std::endl;
    std::cout << "Visited: " << (visited ? "True" : "False") << std::endl;
}
