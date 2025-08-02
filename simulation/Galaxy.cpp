#include "Galaxy.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>

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
         * Columns to extract from the CSV:
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
            // Convert each value to float and store as position star.position
            std::stof(row[8]),  // x
            std::stof(row[9]),  // y
            std::stof(row[10])  // z
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
