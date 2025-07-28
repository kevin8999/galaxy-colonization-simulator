#include "KDTree.h"

template<typename T>
T* KDTree<T>::insert(T* insertNode) {
    if (root == nullptr)
        root = insertNode;
}
