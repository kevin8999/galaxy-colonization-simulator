#pragma once

#include "Star.h"
#include "KDTree.h"

#include <string>
#include <unordered_map>
#include <set>
#include <list>

// Stores a galaxy of stars as a digraph representation
class Galaxy {
private:
    std::vector<Star> stars;
    unsigned int dimensions;
    std::set<unsigned int> visited;

    std::list<Spacecraft> ships;

    // Stores closest neighbors for a star
    std::unordered_map<unsigned int, std::vector<Neighbor> > neighbors;
    unsigned int numClosestToSearch = 20;

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
        neighbors = {};
        stars = {};
    }
};