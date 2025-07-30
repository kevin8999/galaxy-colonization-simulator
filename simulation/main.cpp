#include "Galaxy.h"
#include "Star.h"
#include "KDTree.h"

#include <iostream>

void nearestNeighborTest(std::vector<std::vector<float>>& positions, std::vector<float>& targetPosition) {
    std::vector<Node> nodes;

    for (int i = 0; i < positions.size(); ++i) {
        Node node(i, positions[i]);
        nodes.push_back(node);
    }

    const unsigned int dimensions = 2;
    KDTree tree(dimensions);
    tree.insertNodes(nodes);

    Node target(targetPosition);
    Node* nearest = tree.nearestNeighbor(&target);

    if (nearest != nullptr) {
        std::cout << "NEAREST NODE:" << "\n";
        nearest->print();
    }
    else
        std::cout << "nearest is nullptr" << "\n";
}

void nearestNeighborTest1() {
    std::vector<std::vector<float>> positions = {
        {3, 1},
        {8, 7},
        {10, 2},
        {5, 4},
        {2, 6},
        {13, 3}
    };
    std::vector<float> targetPosition = {9, 4};

    nearestNeighborTest(positions, targetPosition);
}

void nearestNeighborTest2() {
    std::vector<std::vector<float>> positions = {
        {2.0f, 3.0f},
        {5.5f, 4.2f},
        {9.0f, 6.8f},
        {4.2f, 7.7f},
        {8.1f, 1.3f},
        {7.4f, 2.2f},
        {3.3f, 5.5f},
        {1.0f, 9.1f},
        {6.5f, 8.8f},
        {2.2f, 4.4f}
    };
    std::vector<float> targetPosition = {7, 2};

    nearestNeighborTest(positions, targetPosition);
}

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
    nearestNeighborTest1();
    nearestNeighborTest2();

    return 0;
}