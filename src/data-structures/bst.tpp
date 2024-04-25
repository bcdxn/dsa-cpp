//
//  bst.cpp
//  data-structures-and-algorithms
//

#include <exception>
#include <iostream>
#include <optional>

#include "bst.hpp"
#include "comparable-printable.hpp"

template <ComparableAndPrintable T>
BSTNode<T>::BSTNode(T elem) : element(elem) {
    pLeft = nullptr;
    pRight = nullptr;
}

template <ComparableAndPrintable T>
BSTNode<T>::~BSTNode() {
    std::cout << "Destructing BSTNode(" << std::to_string(element) << ")" << std::endl;
}

template <ComparableAndPrintable T>
BST<T>::BST() {
    pRoot = nullptr;
    size = 0;
}

template <ComparableAndPrintable T>
BST<T>::~BST() {
    std::cout << "Destructing BST" << std::endl;
}

template <ComparableAndPrintable T>
void BST<T>::insert(T elem) {
    pRoot = insert(pRoot, elem);
}

template <ComparableAndPrintable T>
bool BST<T>::find(T elem) {
    if (find(pRoot, elem)) {
        return true;
    }
    
    return false;
}

template <ComparableAndPrintable T>
void BST<T>::remove(T elem) {
    pRoot = remove(pRoot, elem);
}

template <ComparableAndPrintable T>
std::optional<T> BST<T>::findMax() {
    return findMax(pRoot);
}

template <ComparableAndPrintable T>
std::optional<T> BST<T>::findMin() {
    return findMin(pRoot);
}

/* Private Recursive Helper Functions
 ----------------------------------------------------------------------------*/
template <ComparableAndPrintable T>
BSTNode<T>* BST<T>::insert(BSTNode<T>* root, T elem) {
    if (!root) {
        size++;
        return new BSTNode<T>(elem);
    }
    
    if (elem < root->element) {
        root->pLeft = insert(root->pLeft, elem);
    } else {
        root->pRight = insert(root->pRight, elem);
    }
    
    return root;
}

template <ComparableAndPrintable T>
BSTNode<T>* BST<T>::find(BSTNode<T>* root, T elem) {
    if (!root) {
        return root;
    }
    
    if (elem == root->element) {
        return root;
    } else if (elem < root->element) {
        return find(root->pLeft, elem);
    } else {
        return find(root->pRight, elem);
    }
}

template <ComparableAndPrintable T>
std::optional<T> BST<T>::findMax(BSTNode<T>* root) {
    if (!root) {
        return {};
    }
    
    if (root->pRight) {
        return findMax(root->pRight);
    }
    
    return root->element;
}

template <ComparableAndPrintable T>
std::optional<T> BST<T>::findMin(BSTNode<T>* root) {
    if (!root) {
        return {};
    }
    
    if (root->pLeft) {
        return findMin(root->pLeft);
    }
    
    return root->element;
}

template <ComparableAndPrintable T>
BSTNode<T>* BST<T>::remove(BSTNode<T>* root, T elem) {
    // If the element is not found there is nothing to do
    if (!root) {
        return root;
    }
    
    if (elem == root->element) {
        BSTNode<T>* newRoot = nullptr;
        if (root->pLeft && !root->pRight) {
            // the node has only a left child, promote it
            newRoot = root->pLeft;
        } else if (!root->pLeft && root->pRight) {
            // the node has only a right child, promote it
            newRoot = root->pRight;
        } else if (root->pLeft && root->pRight) {
            // the node has both a left and right child here we
            // have to replace the node with the largest element
            // in the left subtree (or we could have replaced
            // with the smallest element in the right subtree
            auto newRootElem = findMax(root->pLeft);
            if (!newRootElem.has_value()) {
                throw std::runtime_error("error finding maximum element in tree");
            }
            newRoot = new BSTNode<T>(newRootElem.value());
            // Remove the node we just promoted
            newRoot->pLeft = remove(root->pLeft, newRootElem.value());
            newRoot->pRight = root->pRight;
        } // else the node is a leaf node and be siply removed
        
        delete root;
        size--;
        return newRoot;
    }
    
    if (elem < root->element) {
        root->pLeft = remove(root->pLeft, elem);
    } else {
        root->pRight = remove(root->pRight, elem);
    }
    
    return root;
}
