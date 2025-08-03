#pragma once

#include "Node.h"

struct Neighbor {
    /*  The `Neighbor` class stores two nodes:
     *
     *  - `Neighbor.target` : the reference node
     *  - `Neighbor.node` : the neighbor of `Neighbor.target`
     *
     *  It also stores the distance between `Neighbor.target` and `Neighbor.node` as `Neighbor.distance`.
     */

    float distance;
    Node* node;
    Node* target;

    Neighbor() {
        distance = 0;
        node = nullptr;
        target = nullptr;
    }

    Neighbor(Node* target, Node* node);

    // Comparison for max-heap
    bool operator<(const Neighbor& other) const {
        return distance < other.distance;
    }

    // Comparison for min-heap
    bool operator>(const Neighbor& other) const {
        return distance > other.distance;
    }

    bool operator==(const Neighbor& other) const {
        return distance == other.distance;
    }
};

struct NeighborCompare {
    bool operator()(const Neighbor& a, const Neighbor& b) const {
        return a.distance < b.distance; // max-heap: Neighbor with larger distance is root
    }
};