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

// Timer
#include <thread>
#include <atomic>
#include <chrono>
using namespace std::chrono_literals; // ns, us, ms, s, h, etc.

// Stores a galaxy of stars as a digraph representation
class Galaxy {
private:
    std::vector<Star> stars;
    unsigned int dimensions;
    std::set<unsigned int> visited;

    std::list<Spacecraft> ships;
    unsigned int numShipsSent = 0;

    // Stores closest neighbors for a star
    std::unordered_map<unsigned int, std::vector<Neighbor> > neighbors;
    unsigned int numClosestToSearch = 20;

    KDTree tree;

    double stepSize = std::pow(10, 11);
    Clock clock = Clock(stepSize);

public:
    std::atomic<bool> running = false;

    bool paused  = true;
    bool started = false;
    std::chrono::milliseconds delay = 250ms;

    Galaxy() = default;

    std::vector<Star> load(const std::string& galaxyFile);
    void print(int max = 50) const;

    std::vector<Star> getStars();

    void getClosestStars(const unsigned int &target, unsigned int &numClosest);  // Gets closest stars for target
    void visitClosest(unsigned int target);
    void visit(Star* source, Star* destination, double &distance);
    void visit(unsigned int source, unsigned int destination, double &distance);

    void insertIntoKDTree();
    void printClosest(const unsigned int &id);

    void colonizeFrom(unsigned int id);
    void update();

    // Timer management
    void start();
    void run();
    void pause();
    void resume();
    void timerControl();

    ~Galaxy() {
        neighbors = {};
        stars = {};
    }
};