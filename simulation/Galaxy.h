#pragma once

#include "Star.h"

#include <string>
#include <unordered_map>

// Stores a galaxy of stars as a digraph representation
class Galaxy {
private:
    std::vector<Star> stars;
    std::unordered_map<int, Star> starID;

    // Stores distances between Star A and Star B
    std::unordered_map<int, std::pair<int, float>> distances;

public:
    Galaxy() = default;
    Galaxy(const std::string& fileName) {
        file = fileName;
    }

    std::vector<Star> load(const std::string& galaxyFile);  // Loads star positions based on file configuration of galaxy as specified in `file`

    void findClosestStars();  // Tells each star in the galaxy to find its closest neighbors

    void print(unsigned int max = 50) const; // Prints data in stars

    std::vector<Star> getStars();

    ~Galaxy() {
        distances = {};
        stars = {};
    }
};