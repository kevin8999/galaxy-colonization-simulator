#include <cmath>
#include <iostream>
#include <queue>
#include <set>
#include <bits/stdc++.h>

#include "Node.h"
#include "Calculator.h"
#include "KDTree.h"
#include "Neighbor.h"


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

    if (root == nullptr) {
        std::cerr << "KDTree::print() : root is nullptr. Nothing to print.\n";
        return;
    }

    std::set<Node*> visited;
    std::queue<std::pair<Node*, unsigned int>> q;

    unsigned int numProcessed = 0;

    visited.insert(root);
    q.push({root, 0});

    while (!q.empty()) {
        // Get the next node and process it
        auto [curr, level] = q.front();
        q.pop();

        if (curr == nullptr) continue;

        std::cout << "Level: " << level << "\n";
        curr->print();
        std::cout << "\n";

        bool leftChildNotVisited = visited.find(curr->left) == visited.end();
        bool rightChildNotVisited = visited.find(curr->right) == visited.end();

        if (curr->left != nullptr && leftChildNotVisited) {
            q.push({curr->left, level + 1});
            visited.insert(curr->left);
        }
        if (curr->right != nullptr && rightChildNotVisited) {
            q.push({curr->right, level + 1});
            visited.insert(curr->right);
        }

        numProcessed++;
        if (numProcessed >= max)
            break;
    }
}

void KDTree::print() {
    // Print the entire tree using BFS
    print(numNodes);
}

Node* closest(Node* target, const std::vector<Node*>& nodes) {
    // Returns closest node given a vector of nodes
    if (target == nullptr) {
        std::cerr << "ERROR: Target node cannot be nullptr.";
        return nullptr;
    }

    Node* closestNode = nullptr;
    float closestDistance = INFINITY;

    for (Node* node : nodes) {
        if (node == nullptr) continue;

        float newDist = Calculator::calcDistance(target, node);

        if (newDist < closestDistance) {
            closestDistance = newDist;
            closestNode = node;
        }
    }

    return closestNode;
}

Node * KDTree::nearestNeighborRecursive(Node* top, Node* target, unsigned int depth) {
    // Finds the node closest to target

    if (top == nullptr)
        return nullptr;
    if (target == nullptr) {
        std::cerr << "Cannot find nearest neighbor using nullptr target node." << "\n";
        return nullptr;
    }

    unsigned int dimension = depth % K;

    // Pick which node to traverse in KDTree
    Node* nearBranch;
    Node* farBranch;

    if (target->position[dimension] < top->position[dimension]) {
        nearBranch = top->left;
        farBranch  = top->right;
    }
    else {
        nearBranch = top->right;
        farBranch  = top->left;
    }

    Node* nearNode = nearestNeighborRecursive(nearBranch, target, depth + 1);  // Find closest node in rest of KDTree

    // Get all candidates (top and nearNode) and figure out which one is closest
    std::vector<Node*> candidates;
    candidates.push_back(top);
    if (nearNode != nullptr) candidates.push_back(nearNode);

    Node* closestNode = closest(target, candidates);

    //std::cout << "Closest Node (with nearNode):" << "\n";
    //closestNode->print();

    // Compare the distance between target and closest node to its normal
    float distance = Calculator::calcDistance(target, closestNode);
    float distanceNormal = std::abs(target->position[dimension] - top->position[dimension]);

    // Check farBranch to see if it has a node closer than closestNode (on nearBranch)
    if (distance >= distanceNormal) {
        Node* farNode = nearestNeighborRecursive(farBranch, target, depth + 1);

        candidates.pop_back();              // candidates = {closestNode}
        if (farNode != nullptr) {
            candidates.push_back(farNode);  // candidates = {closestNode, farNode}

            closestNode = closest(target, candidates);
            //std::cout << "Closest Node (with farNode):" << "\n";
            //closestNode->print();
        }
    }

    return closestNode;
}

Node* KDTree::nearestNeighbor(Node* target) {
    return nearestNeighborRecursive(root, target, 0);
}

Node* KDTree::knnRecursive(Node* curr, Node* target, unsigned int depth,
                            std::priority_queue<Neighbor>& heap, unsigned int& numNodes) {
    // Finds the K closest nodes to target

    if (curr == nullptr)
        return nullptr;
    if (target == nullptr) {
        std::cerr << "KDTree::knnRecursive(): Cannot find nearest neighbor using nullptr target node." << "\n";
        return nullptr;
    }

    unsigned int dimension = depth % K;

    // Pick which node to traverse in KDTree
    Node* nearBranch;
    Node* farBranch;

    if (target->position[dimension] < curr->position[dimension]) {
        nearBranch = curr->left;
        farBranch  = curr->right;
    }
    else {
        nearBranch = curr->right;
        farBranch  = curr->left;
    }

    // Calculate distance for nodes in near branch
    knnRecursive(nearBranch, target, depth + 1, heap, numNodes);

    Neighbor currNeighbor(target, curr);

    if (heap.size() < numNodes) {
        // Push closestNode and curr if there's enough room in heap
        heap.push(currNeighbor);
    }
    else if (currNeighbor.distance < heap.top().distance) {
        // If max heap is full but distance is less than maximum in max-heap
        heap.pop();
        heap.push(currNeighbor);
    }

    // Check to see if plane is closer to target than curr
    float distanceToPlane = std::abs(target->position[dimension] - curr->position[dimension]);

    // Check farBranch
    if (heap.size() < numNodes || distanceToPlane < heap.top().distance) {
        knnRecursive(farBranch, target, depth + 1, heap, numNodes);
    }

    return curr;
}

std::vector<Node*> KDTree::knn(Node* target, unsigned int& numNodes) {
    std::priority_queue<Neighbor> heap;
    knnRecursive(root, target, 0, heap, numNodes);

    std::vector<Node*> result;
    while (!heap.empty()) {
        result.push_back(heap.top().node);
        heap.pop();
    }

    // Reverse `result` so that it is in ascending order (shortest to longest distance)
    std::reverse(result.begin(), result.end());

    return result;
}
