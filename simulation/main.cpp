#include "Galaxy.h"
#include "Star.h"
#include "KDTree.h"

#include <iostream>

void printKDTreeTest() {
    std::string galaxyFile = "../data/hygdata_cleaned.csv";
    Galaxy galaxy;
    galaxy.load(galaxyFile);

    unsigned int dimensions = 3;
    KDTree tree(dimensions);

    std::vector<Star> stars = galaxy.getStars();
    tree.insertStars(stars);

    unsigned int max = 30;
    tree.print(max);
}

int main() {
    printKDTreeTest();

    return 0;
}