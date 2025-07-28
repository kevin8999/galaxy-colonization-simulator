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
        star.id = std::stoi(row[1]);
        star.position = {
            // Convert each value to float and store as position star.position
            std::stof(row[8]),  // x
            std::stof(row[9]),  // y
            std::stof(row[10])  // z
        };
        star.solarLuminosity = std::stof(row[18]);

        stars.push_back(star);
    }

    std::cout << stars.size() << std::endl;

    return stars;
}

void Galaxy::print(unsigned int max) {

void Galaxy::print(unsigned int max) const {
    if (max > stars.size())
        max = stars.size();

    for (int i = 0; i < max; ++i) {
        stars[i].print();
    }
}

std::vector<Star> Galaxy::getStars() {
    return stars;
}
