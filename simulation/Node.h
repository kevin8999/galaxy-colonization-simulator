#pragma once

#include <vector>
#include "Star.h"

// Stores data for Star in KDTree
class Node {
public:
    unsigned int id;
    std::vector<int> position;
    Star* left;
    Star* right;

    Node(unsigned int id, const std::vector<int>& position) {
        this->id = id;
        this->position = position;

        left = nullptr;
        right = nullptr;
    }

    Node operator=(Node* other) {
        if (this != &other) {
            value = other->value;
            left = other->left;
            right = other->right;
        }

        return *this;
    }
};