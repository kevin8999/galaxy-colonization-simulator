#pragma once

#include <vector>
#include "Star.h"

// Stores data for Star in KDTree
class Node {
public:
    unsigned int id;
    std::vector<float> position;
    Node* left;
    Node* right;

    Node(unsigned int id, const std::vector<int>& position) {

    Node(const unsigned int& id, const std::vector<float>& position) {
        this->id = id;
        this->position = position;

        left = nullptr;
        right = nullptr;
    }

    Node operator=(Node& other) {

    Node operator=(const Node& other) {
        if (this != &other) {
            position = other.position;
            left = other.left;
            right = other.right;
        }

        return *this;
    }
};