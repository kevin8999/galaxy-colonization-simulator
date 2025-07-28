#include "KDTree.h"
#include "Node.h"

#include <queue>
#include <set>

Node* KDTree::insertRecursive(Node* currNode, Node& insertNode, unsigned int depth) {
    if (currNode == nullptr)
        return new Node(insertNode.id, insertNode.position);

    unsigned int currDimension = depth % K;

    if (currNode->position[currDimension] < insertNode.position[currDimension]) {
        currNode->left = insertRecursive(currNode->left, insertNode, depth + 1);
    }
    else if (currNode->position[currDimension] >= insertNode.position[currDimension]) {
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

void KDTree::print(unsigned int max) {
    // Print the entire KD tree using BFS.
    // NOTE: Children are printed left to right.

    std::set<Node*> visited;
    std::queue<Node*> q;

    visited.insert(root);
    q.push(root);

    unsigned int count = 0;

    while (!q.empty()) {
        // Get the next node and process it
        Node* curr = q.front();
        curr->print();
        q.pop();

        if (curr->left != nullptr)
            q.push(curr->left);
        if (curr->right != nullptr)
            q.push(curr->right);

        count++;
        if (count > max)
            break;
    }
}
