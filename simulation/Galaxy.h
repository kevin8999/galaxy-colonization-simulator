#pragma once

#include "Star.h"
#include "KDTree.h"

#include <string>
#include <unordered_map>

// Stores a galaxy of stars as a digraph representation
class Galaxy {
private:
    std::vector<Star> stars;
    std::unordered_map<int, Star> starID;

    // Stores distances between Star A and Star B
    std::unordered_map<int, std::pair<int, float>> distances;

    KDTree tree;

public:
    Galaxy() = default;

    std::vector<Star> load(const std::string& galaxyFile);
    void print(int max = 50) const;

    std::vector<Star> getStars();

    ~Galaxy() {
        distances = {};
        stars = {};
    }
};