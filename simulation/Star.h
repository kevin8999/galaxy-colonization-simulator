#pragma once

#include <vector>

struct Star {
    // Stores (x, y, z) or (x, y) position of a star
    std::vector<double> position;

    float solarLuminosity;
    unsigned int id;
    bool visited;

    // FUNCTIONS

    Star(std::vector<double>& inPos, float& inLum, unsigned int& inID) {
        position = inPos;
        solarLuminosity = inLum;
        id = inID;
        visited = false;
    }
    Star() {
        visited = false;
    }

    void print() const;
};

