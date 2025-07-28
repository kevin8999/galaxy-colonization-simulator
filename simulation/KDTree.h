#pragma once
#include <map>

#include "Node.h"
#include "Star.h"

/*  This file creates a data structure called a "KD-Tree".
 *
 *  A KD-Tree is short for "K-Dimensional Tree". It creates a tree where every node in the tree creates a hyperplane
 *  that splits the entire space into two parts.
 *
 *  As an example, I will describe the insertion algorithm.
 *
 *  INSERTION (3 dimensions)
 *
 *      Start at root
 *      while (not at leaf node)
 *          Compare newPoint's 1st dimension with root's 1st dimension
 *              If newPoint's 1st dimension < root's 1st dimension:
 *                  traverseLeft()
 *              Else:
 *                  traverseRight()
 *
 *          Compare newPoint's 2nd dimension with root's 2nd dimension
 *              If newPoint's 2nd dimension < root's 2nd dimension:
 *                  traverseLeft()
 *              Else:
 *                  traverseRight()
 *
 *          Compare newPoint's 3rd dimension with root's 3rd dimension
 *              If newPoint's 3rd dimension < root's 3rd dimension:
 *                  traverseLeft()
 *              Else:
 *                  traverseRight()
 *
 *          Continue this process (comparing dimensions) while cycling through dimensions (1, 2, 3, 1, 2, 3, ...)
 */

bool compareDimension(std::vector<int>& x, std::vector<int>& y, unsigned int& i) {
    return x[i] < y[i];
}

template <typename T>
class KDTree {
private:
    std::map<unsigned int, T> container;
    unsigned int dimensions;
    unsigned int numNodes;
    unsigned int maxDepth;

public:
    KDTree(unsigned int dimensions) {
        this->dimensions = dimensions;
        numNodes = 0;
        maxDepth = 0;
        root = nullptr;
    }

    ~KDTree() {
        root = nullptr;
    }

    Node<T>* root;

    Node<T>* insert(Node<T>* insertNode);
    Node<T>* remove(Node<T>* removeNode);
    Node<T>* search(Node<T>* searchNode);
};

