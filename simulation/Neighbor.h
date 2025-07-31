#pragma once

#include "Node.h"

struct Neighbor {
    float distance;
    Node* node;
    Node* target;

    Neighbor() {
        distance = 0;
        node = nullptr;
        target = nullptr;
    }

    Neighbor(Node* target, Node* node) {
        this->target = target;
        this->node = node;
        distance = 0;
    }

    float calcDistance();

    // Comparison for max-heap
    bool operator<(const Neighbor& other) const {
        return distance < other.distance;
    }
};

struct NeighborCompare {
    bool operator()(const Neighbor& a, const Neighbor& b) const {
        return a.distance < b.distance; // max-heap: Neighbor with larger distance is root
    }
};