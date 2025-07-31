#pragma once

#include <iostream>
#include <vector>
#include "Star.h"

// Stores data for Star in KDTree
class Node {
public:
    unsigned int id;
    std::vector<float> position;
    Node* left;
    Node* right;

    Node() {
        id = 0;
        left = nullptr;
        right = nullptr;
    };

    Node(const unsigned int& id, const std::vector<float>& position) {
        this->id = id;
        this->position = position;

        left = nullptr;
        right = nullptr;
    }

    Node(const std::vector<float>& position) {
        this->id = 0;
        this->position = position;

        left = nullptr;
        right = nullptr;
    }

    Node(const Star& star) {
        this->id = star.id;
        this->position = star.position;

        left = nullptr;
        right = nullptr;
    }

    Node operator=(const Node& other) {
        if (this != &other) {
            position = other.position;
            left = other.left;
            right = other.right;
        }

        return *this;
    }

    bool operator==(const Node& other) const {
        if (this->position.size() != other.position.size()) {
            return false;
        }

        for (unsigned int i = 0; i < position.size(); ++i) {
            if (position[i] != other.position[i]) {
                return false;
            }
        }
        return true;
    }

    bool operator!=(const Node& other) const {
        // if this.numDimensions != other.numDimensions
        if (this->position.size() != other.position.size()) {
            return true;
        }

        for (unsigned int i = 0; i < position.size(); ++i) {
            if (position[i] == other.position[i]) {
                return false;
            }
        }
        return true;
    }

    void print(std::string beginChar) const {
        // Prints contents of Node object with a beginning character
        if (this == nullptr) {
            std::cerr << "Node::print() : Node is nullptr" << "\n";
            return;
        }

        std::cout << beginChar << "ID: " << this->id << "\n";
        std::cout << beginChar << "Position: " << "(";

        for (int i = 0; i < position.size() - 1; ++i)
            std::cout << position[i] << ", ";

        std::cout << position[position.size() - 1] << ")" << "\n";
    }

    void print() const {
        print("");
    }
};