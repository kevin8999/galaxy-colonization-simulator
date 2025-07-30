#pragma once

#include <map>
#include <vector>

#include "Node.h"
#include "Star.h"

/*  This file creates a data structure called a "KD-Tree".
 *
 *  A KD-Tree is short for "K-Dimensional Tree". A KD-Tree is a binary tree that organizes points in K dimensions.
 *
 *  However, it functions differently to a binary tree.
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

class KDTree {
private:
    unsigned int K;
    unsigned int numNodes;
    unsigned int maxDepth;

public:
    KDTree(const unsigned int& dimensions) {
        this->K = dimensions;  // K dimensions
        numNodes = 0;
        maxDepth = 0;
        root = nullptr;
    }

    ~KDTree() {
        root = nullptr;
    }

    Node* root;


    Node* insertRecursive(Node* currNode, Node& insertNode, unsigned int depth);
    Node* insert(Node insertNode);

    bool searchRecursive(Node *currNode, Node *insertNode, unsigned int depth);
    bool search(Node* searchNode);

    Node* remove(Node* removeNode);

    void insertStars(std::vector<Star> &stars);
    void print(unsigned int max);
    void print();

};

