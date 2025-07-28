#include "KDTree.h"
#include "Node.h"
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


template<typename T>
T* KDTree<T>::insert(T* insertNode) {
    if (root == nullptr)
        root = insertNode;
}
