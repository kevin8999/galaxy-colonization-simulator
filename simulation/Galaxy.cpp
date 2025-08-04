#include "Galaxy.h"
#include "KDTree.h"
#include "Node.h"
#include "Neighbor.h"
#include "CONSTANTS.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <thread>

std::vector<Star> Galaxy::load(const std::string& galaxyFile) {
    // Parse input of CSV
    std::ifstream inputStream(galaxyFile);
    std::string line;

    // Skip first line
    std::getline(inputStream, line);

    // Parse lines in CSV
    while (std::getline(inputStream, line)) {
        std::vector<std::string> row;
        std::stringstream ss(line);
        std::string cell;

        // Parse each line in the CSV
        while (std::getline(ss, cell, ',')) {
            row.push_back(cell);
        }

        /*
         *  Columns to extract from the CSV:
         *       1  → ID
         *       8  → x-position
         *       9  → y-position
         *       10 → z-position
         *       18 → solar luminosity
         */

        // Define star based on values in the row
        Star star;
        unsigned long id = std::stoul(row[1]);
        star.id = static_cast<unsigned int>(id); // ID in data starts at 1
        star.position = {
            // Convert each value to double and store as position star.position
            std::stod(row[8])  * LIGHT_YEAR, // x
            std::stod(row[9])  * LIGHT_YEAR, // y
            std::stod(row[10]) * LIGHT_YEAR  // z
        };
        star.solarLuminosity = std::stof(row[18]);

        stars.push_back(star);
    }
    // Force stars to have the same capacity as its size
    stars.shrink_to_fit();

    unsigned int dimensions = stars[0].position.size();
    tree.setDimensions(dimensions);

    bool printSize = false;

    if (printSize)
        std::cout << stars.size() << std::endl;

    return stars;
}

void Galaxy::print(int max) const {
    if (max > stars.size())
        max = stars.size();

    for (int i = 0; i < max; ++i) {
        stars[i].print();
    }
}

std::vector<Star> Galaxy::getStars() {
    return stars;
}

void Galaxy::getClosestStars(const unsigned int& target, unsigned int& numClosest) {
    // Get closest stars to target

    if (target > stars.size()) {
        std::cerr << "Error: target is greater than stars.size()" << "\n";
        std::cout << "\t Target: " << target << std::endl;
        std::cout << "\t stars.size(): " << stars.size() << std::endl;
        return;
    }

    const Star* targetStar = &stars[target];
    Node targetNode(targetStar);

    // Find K Nearest Neighbors
    std::vector<Neighbor> closestNodes = tree.knn(&targetNode, ++numClosest);

    // Store nearest neighbors in hash map
    for (Neighbor& neighbor : closestNodes) {
        if (neighbor.node->id == target) continue;
        neighbors[target].push_back(neighbor);
    }
}

void Galaxy::insertIntoKDTree() {
    // Insert stars into tree
    tree.insertStars(stars);
    std::cout << "Finished inserting " << stars.size() << " stars into KDTree" << std::endl;
}

void Galaxy::printClosest(const unsigned int &id) {
    // Prints closest stars for a given ID.
    // For this function to work, the star must have been visited and the closest stars must have been found already

    std::vector<Neighbor>& target = neighbors[id];

    std::cout << "Target: " << id << std::endl;
    for (const Neighbor neighbor : target) {
        std::cout << "\tNeighbor: " << neighbor.node->id << std::endl;
        std::cout << "\tDistance: " << neighbor.distance << std::endl;
    }
}

void Galaxy::visit(Star* source, Star* destination, double& distance) {
    // Creates a parametric equation to model a spacecraft travelling from source to destination

    // If      source has not been visited        OR       destination has been visited
    if (visited.find(source->id) == visited.end() || visited.find(destination->id) != visited.end())
        return;

    unsigned int id = ++numShipsSent;
    float launchTime = clock.now();
    Spacecraft ship(id, source, destination, launchTime, distance);
    ships.push_back(ship);
    visited.insert(destination->id);
}

void Galaxy::visit(unsigned int source, unsigned int destination, double& distance) {
    Star* sourceStar = &stars[source];
    Star* destinationStar = &stars[destination];
    visit(sourceStar, destinationStar, distance);
}

void Galaxy::visitClosest(const unsigned int target) {
    // Visits closest stars. `target` must already have a vector of closest stars to it
    std::vector<Neighbor>& closest = neighbors[target];

    for (const Neighbor neighbor : closest) {
        unsigned int& destinationID = neighbor.node->id;
        double distance = neighbor.distance;

        visit(target, destinationID, distance);
    }
}

void Galaxy::colonizeFrom(unsigned int id) {
    // Start colonization process at `id`
    visited.insert(id);
    stars[id].visited = true;

    getClosestStars(id, numClosestToSearch);
    visitClosest(id);
}

void Galaxy::update() {
    // Update state of objects in Galaxy

    clock.tick();
    double currentTime = clock.now();

    for (auto it = ships.begin(); it != ships.end(); ) {
        Spacecraft& ship = *it;
        ship.updatePosition(currentTime);

        if (ship.arrived) {
            unsigned int& destinationID = ship.destination->id;
            colonizeFrom(destinationID);

            // Delete current ship and get next ship
            it = ships.erase(it);
        }
        else {
            ++it;
        }
    }
}

void Galaxy::start() {
    unsigned int startID = 0;
    insertIntoKDTree();

    colonizeFrom(startID);

    running = true;
    started = true;
    paused = false;
}

void Galaxy::run() {
    if (started == false) {
        std::cerr << "Galaxy::run() : Attempting to run Galaxy before calling Galaxy.start()" << std::endl;
        return;
    }

    std::cout << "Running galaxy colonization simulation" << std::endl;

    while (running) {
        if (!paused) {
            update();
            std::this_thread::sleep_for(delay);
            std::cout << "Updated\n";
        }
        else {
            // Delay and do nothing
            std::this_thread::sleep_for(delay);
        }
    }

    std::cout << "Thread stopped." << "\n";
}

void Galaxy::pause() {
    paused = true;
    std::cout << "Galaxy colonization simulation paused." << std::endl;
}

void Galaxy::resume() {
    paused = false;
    std::cout << "Galaxy colonization simulation resumed." << std::endl;
}

void Galaxy::timerControl() {
    std::string c;

    while (true) {
        std::cin >> c;

        if (c == "p" || c == "pause") {
            pause();
        }
        else if (c == "r" || c == "resume") {
            resume();
        }
        else if (c == "q" || c == "quit") {
            running = false;
            std::cout << "Quitting out of program..." << std::endl;
            break;
        }
        else {
            std::cerr << "Galaxy::timerControl() : Unknown command: " << c << std::endl;
        }
    }

}