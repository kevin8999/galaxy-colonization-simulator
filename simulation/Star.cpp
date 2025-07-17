#include "Star.h"

#include <iostream>

void Star::print() const {
    std::cout << "ID: " << id << std::endl;
    std::cout << "Position: " << "(";

    for (const float& val : position)
        std::cout << val << ", ";

    std::cout << ")" << std::endl;

    std::cout << "Luminosity: " << solarLuminosity << std::endl;
    std::cout << "Visited: " << (visited ? "True" : "False") << std::endl;
}
