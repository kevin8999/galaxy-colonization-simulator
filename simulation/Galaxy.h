#pragma once

#include "Star.h"
#include "KDTree.h"

#include <string>
#include <unordered_map>
#include <set>

// Stores a galaxy of stars as a digraph representation
class Galaxy {
private:
    std::vector<Star> stars;
    unsigned int dimensions;
    std::set<unsigned int> visited;

    // Stores distances between Star A and Star B
    std::unordered_map<unsigned int, std::vector<std::pair<unsigned int, float>> > distances;

    KDTree tree;

public:
    Galaxy() = default;

    std::vector<Star> load(const std::string& galaxyFile);
    void print(int max = 50) const;

    std::vector<Star> getStars();

    void getClosestStars(const unsigned int &target, unsigned int &numClosest);  // Gets closest stars for target
    void insertTree();
    void printClosest(const unsigned int &id);

    ~Galaxy() {
        distances = {};
        stars = {};
    }
};