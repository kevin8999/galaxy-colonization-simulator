#include <cmath>
#include <iostream>
#include <queue>
#include <set>
#include <bits/stdc++.h>

#include "Node.h"
#include "Calculator.h"
#include "KDTree.h"


Node* KDTree::insertRecursive(Node* currNode, Node& insertNode, unsigned int depth) {
    if (currNode == nullptr)
        return new Node(insertNode.id, insertNode.position);

    unsigned int currDimension = depth % K;

    if (insertNode.position[currDimension] < currNode->position[currDimension]) {
        currNode->left = insertRecursive(currNode->left, insertNode, depth + 1);
    }
    else {
        currNode->right = insertRecursive(currNode->right, insertNode, depth + 1);
    }

    return currNode;
}


Node* KDTree::insert(Node insertNode) {
    root = insertRecursive(root, insertNode, 0);
    numNodes++;
    return root;
}


bool KDTree::searchRecursive(Node* currNode, Node* searchNode, unsigned int depth) {
    if (searchNode == nullptr)
        return false;

    // If values in each dimension match, return true
    // Two nodes are equal if the value contained in each dimension is the same.
    if (currNode == searchNode)
        return true;

    // Otherwise, search in next subtree
    unsigned int currDimension = depth % K;
    if (currNode->position[currDimension] < searchNode->position[currDimension]) {
        return searchRecursive(currNode->left, searchNode, depth + 1);
    }
    else {
        return searchRecursive(currNode->right, searchNode, depth + 1);
    }
}



bool KDTree::search(Node* searchNode) {
    // Return true if successfully found, otherwise, return false
    return searchRecursive(root, searchNode, 0);
}


void KDTree::insertStars(std::vector<Star>& stars) {
    // Insert stars into KD tree

    for (int i = 0; i < stars.size(); ++i) {
        Node node(stars[i]);
        insert(node);
    }
}

void KDTree::insertNodes(std::vector<Node>& nodes) {
    // Insert nodes into KD tree

    for (const Node& node : nodes) {
        insert(node);
    }
}

void KDTree::print(unsigned int max) {
    // Print the entire KD tree using BFS.
    // NOTE: Children are printed left to right.

    std::set<Node*> visited;
    std::queue<std::pair<Node*, unsigned int>> q;

    unsigned int numProcessed = 0;

    visited.insert(root);
    q.push({root, 0});

    while (!q.empty()) {
        // Get the next node and process it
        auto [curr, level] = q.front();
        std::cout << "Level: " << level << "\n";
        curr->print();
        std::cout << "\n";
        q.pop();

        if (curr->left != nullptr)
            q.push({curr->left, level + 1});
        if (curr->right != nullptr)
            q.push({curr->right, level + 1});

        numProcessed++;
        if (numProcessed > max)
            break;
    }
}

void KDTree::print() {
    // Print the entire tree using BFS
    print(numNodes);
}
