#pragma once

#include <vector>

struct Star {
    // Stores (x, y, z) or (x, y) position of a star
    std::vector<int> position;

    float solarLuminosity;
    int id;

    Star(std::vector<int> inPos, float inLum, inID) {
        position = inPos;
        solarLuminosity = inLum;
        id = inID;
    }
}