#pragma once

#include "Star.h"
#include "KDTree.h"
#include "Spacecraft.h"
#include "Clock.h"
#include "Neighbor.h"

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

    Clock clock = Clock(1.0f);

public:
    Galaxy() = default;

    std::vector<Star> load(const std::string& galaxyFile);
    void print(int max = 50) const;

    std::vector<Star> getStars();

    void getClosestStars(const unsigned int &target, unsigned int &numClosest);  // Gets closest stars for target
    void visitClosest(unsigned int target);
    void visit(Star* source, Star* destination, float &distance);
    void visit(unsigned int source, unsigned int destination, float &distance);

    void insertTree();
    void printClosest(const unsigned int &id);

    void start(unsigned int id);
    void update();

    ~Galaxy() {
        neighbors = {};
        stars = {};
    }
};