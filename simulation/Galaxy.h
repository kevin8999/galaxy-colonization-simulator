#pragma once

#include "Star.h"

#include <string>

// Stores a galaxy of stars as a digraph representation
class Galaxy {
private:
    std::string file = "../data/hygdata_cleaned.csv";
    std::vector<Star> stars;

    // Stores distances between Star A and Star B
    std::pair<std::pair<Star, Star>, float> distances;

public:
    Galaxy() = default;
    Galaxy(const std::string& fileName) {
        file = fileName;
    }

    std::vector<Star> load();  // Loads star positions based on file configuration of galaxy as specified in `file`

    void findClosestStars();  // Tells each star in the galaxy to find its closest neighbors

    void print(unsigned int max = 50); // Prints data in stars

    ~Galaxy() {
        distances = {};
        file = "";
        stars = {};
    }
};