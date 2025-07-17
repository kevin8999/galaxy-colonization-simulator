#pragma once

#include "Star.h"

#include <string>

// Stores a galaxy of stars as a digraph representation
class Galaxy {
private:
    std::string file;
    std::vector<Stars> stars;

    // Stores distances between Star A and Star B
    std::pair<std::pair<Star, Star>, float> distances;

public:
    Galaxy();
    Galaxy(std::string fileName) {
        file = fileName;
    }

    std::vector<Star> setStarPos();
    float calcDistance(Star& s1, Star& s2);
    void findClosestStars();

    ~Galaxy();
};