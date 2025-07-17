#pragma once

#include <vector>

struct Star {
    // Stores (x, y, z) or (x, y) position of a star
    std::vector<int> position;

    float solarLuminosity;
    unsigned int id;
    bool visited;

    Star(std::vector<int> inPos, float inLum, unsigned int inID) {
        position = inPos;
        solarLuminosity = inLum;
        id = inID;
    }

    std::vector<Star> findClosestStars(unsigned int n);  // Finds closest n stars
}