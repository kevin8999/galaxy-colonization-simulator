#pragma once

#include <vector>

struct Star {
    // Stores (x, y, z) or (x, y) position of a star
    std::vector<float> position;

    float solarLuminosity;
    unsigned int id;
    bool visited;

    // FUNCTIONS

    Star(std::vector<float>& inPos, float& inLum, unsigned int& inID) {
        position = inPos;
        solarLuminosity = inLum;
        id = inID;
        visited = false;
    }
    Star() {
        visited = false;
    }

    void print() const;

    std::vector<Star> findClosestStars(unsigned int n);  // Finds closest n stars
};

