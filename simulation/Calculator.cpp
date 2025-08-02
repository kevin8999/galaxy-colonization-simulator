#include "Calculator.h"

#include <cmath>
#include <iostream>
#include <stdexcept>

float Calculator::calcDistance(Star& s1, Star& s2) {
    const std::vector<float>& pos1 = s1.position;
    const std::vector<float>& pos2 = s2.position;

    if (pos1.size() != pos2.size()) {
        std::cerr << "ERROR: pos1 != pos2 " << "(" << pos1.size() << " != " << pos2.size() << ")" << std::endl;
    }

    float dist = 0.0f;

    for (int val = 0; val < pos1.size(); ++val) {
        const float displacement = pos2[val] - pos1[val];
        dist += displacement * displacement;
    }

    return std::sqrt(dist);
}

float Calculator::calcDistance(Star* s1, Star* s2) {
    const std::vector<float>& pos1 = s1->position;
    const std::vector<float>& pos2 = s2->position;

    if (pos1.size() != pos2.size()) {
        std::cerr << "ERROR: pos1 != pos2 " << "(" << pos1.size() << " != " << pos2.size() << ")" << std::endl;
    }

    float dist = 0.0f;

    for (int val = 0; val < pos1.size(); ++val) {
        const float displacement = pos2[val] - pos1[val];
        dist += displacement * displacement;
    }

    return std::sqrt(dist);
}

float Calculator::calcDistance(Node* s1, Node* s2) {
    if (s1 == nullptr || s2 == nullptr) {
        throw std::invalid_argument("Calculator::calcDistance() : One or both nodes are nullptr.");
    }

    const std::vector<float>& pos1 = s1->position;
    const std::vector<float>& pos2 = s2->position;

    if (pos1.size() != pos2.size()) {
        throw std::invalid_argument("Calculator::calcDistance() : Dimension mismatch between position vectors.");
    }

    float dist = 0.0f;

    for (int val = 0; val < pos1.size(); ++val) {
        const float displacement = pos2[val] - pos1[val];
        dist += displacement * displacement;
    }

    return std::sqrt(dist);
}