#pragma once

template <typename T>
class Node {
public:
    T value;
    T* left;
    T* right;

    Node(T& input) {
        value = input;
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