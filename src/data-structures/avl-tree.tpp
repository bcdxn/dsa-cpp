//
//  avl-tree.cpp
//  data-structures-and-algorithms
//
//  Created by Benjamin Dixon on 4/6/24.
//

#include <algorithm>
#include <exception>
#include <iostream>
#include <optional>

#include "avl-tree.hpp"
#include "comparable-printable.hpp"

/* AVLTreeNode private methods
---------------------------------------------------------------------------- */

template <ComparableAndPrintable T>
int AVLTreeNode<T>::maxHeight(AVLTreeNode<T>* node) {
    if (node) {
        return 1 + std::max(maxHeight(node->pLeft), maxHeight(node->pRight));
    }
    
    return 0;
}

/* AVLTreeNode public methods
---------------------------------------------------------------------------- */

template <ComparableAndPrintable T>
AVLTreeNode<T>::AVLTreeNode(T element) : element(element) {
    pLeft = nullptr;
    pRight = nullptr;
}

template <ComparableAndPrintable T>
AVLTreeNode<T>::~AVLTreeNode() {
    std::cout << "Destroying AVL Tree" << std::endl;
}

template <ComparableAndPrintable T>
int AVLTreeNode<T>::maxHeight() {
    return maxHeight(this);
}

/* AVLTree private methods
---------------------------------------------------------------------------- */

template <ComparableAndPrintable T>
AVLTreeNode<T>* AVLTree<T>::insert(AVLTreeNode<T>* root, T elem) {
    if (!root) {
        size++;
        return new AVLTreeNode<T>(elem);
    }
    
    if (elem < root->element) {
        root->pLeft = insert(root->pLeft, elem);
    } else {
        root->pRight = insert(root->pRight, elem);
    }
    
    root = balance(root);
    
    return root;
}

template <ComparableAndPrintable T>
AVLTreeNode<T>* AVLTree<T>::remove(AVLTreeNode<T>* root, T elem) {
    if (!root) {
        // The item was not found
        return root;
    }
    
    if (elem < root->element) {
        root->pLeft = remove(root->pLeft, elem);
    } else if (elem > root->element) {
        root->pRight = remove(root->pRight, elem);
    } else {
        AVLTreeNode<T>* node = nullptr;
        // we've found the element to remove
        if (root->pLeft && root->pRight) {
            // we must promote the smallest element in the right subtree
            auto promotedElement = findMin(root->pRight);
            
            if (!promotedElement.has_value()) {
                throw std::runtime_error("invalid AVL tree");
            }
            
            node = new AVLTreeNode(promotedElement.value());
            node->pLeft = root->pLeft;
            size++;
            node->pRight = remove(root->pRight, promotedElement.value());
        } else if (root->pLeft) {
            // we can simply promote pLeft
            node = root->pLeft;
        } else if (root->pRight) {
            // we can simply promote pRight
            node = root->pRight;
        } // else no children; simply remove the node
            
        delete root;
        size--;
        root = node;
    }
    
    root = balance(root);
    
    return root;
}

template <ComparableAndPrintable T>
std::optional<T> AVLTree<T>::findMin(AVLTreeNode<T>* root) {
    if (!root) {
        // tree is empty
        return {};
    }
    
    if (root->pLeft) {
        // There are smaller elements in the subtree; recurse
        return findMin(root->pLeft);
    }
    // We're at the smallest element in the tree; return it
    return root->element;
}

template <ComparableAndPrintable T>
int AVLTree<T>::getBalanceFactor(AVLTreeNode<T>* node) {
    if (node) {
        if (node->pLeft && node->pRight) {
            return node->pRight->maxHeight() - node->pLeft->maxHeight();
        } else if (node->pLeft) {
            return 0 - node->pLeft->maxHeight();
        } else if (node->pRight) {
            return node->pRight->maxHeight();
        }
    }
    
    return 0;
}

/*
 left rotation
    1. right child becomes new root
    2. left child of new root is assigned to the right child of the old root
    3. previous root becomes the new root's left child
 */
template <ComparableAndPrintable T>
AVLTreeNode<T>* AVLTree<T>::leftRotation(AVLTreeNode<T>* root) {
    AVLTreeNode<T>* newRoot = root->pRight;
    
    root->pRight = newRoot->pLeft;
    newRoot->pLeft = root;
    
    return newRoot;
}

/*
 right rotation:
    1. left child becomes new root
    2. right child of new root is assigned to the left child of the old root
    3. previous root becomes the new root's right child
 */
template <ComparableAndPrintable T>
AVLTreeNode<T>* AVLTree<T>::rightRotation(AVLTreeNode<T>* root) {
    AVLTreeNode<T>* newRoot = root->pLeft;
    
    root->pLeft = newRoot->pRight;
    newRoot->pRight = root;
    
    return newRoot;
}

template <ComparableAndPrintable T>
AVLTreeNode<T>* AVLTree<T>::leftRightRotation(AVLTreeNode<T>* root) {
    root->pRight = rightRotation(root->pRight);
    return leftRotation(root);
}

template <ComparableAndPrintable T>
AVLTreeNode<T>* AVLTree<T>::rightLeftRotation(AVLTreeNode<T>* root) {
    root->pLeft = leftRotation(root->pLeft);
    return rightRotation(root);
}

template <ComparableAndPrintable T>
AVLTreeNode<T>* AVLTree<T>::balance(AVLTreeNode<T>* root) {
    int bFactor = getBalanceFactor(root);
    
    if (bFactor < -1) {
        // left heavy subtree
        if (getBalanceFactor(root->pLeft) > 0) {
            // right-left rotation
            root = rightLeftRotation(root);
        } else {
            // right rotation
            root = rightRotation(root);
        }
    } else if (bFactor > 1) {
        // right heavy subree
        if (getBalanceFactor(root->pRight) < 0) {
            // left-right rotation
            root = leftRightRotation(root);
        } else {
            // left-rotation
            root = leftRotation(root);
        }
    }
    // else our subtree is considered balanced
    
    return root;
}

/* AVLTree public methods
---------------------------------------------------------------------------- */

template <ComparableAndPrintable T>
AVLTree<T>::AVLTree() {
    pRoot = nullptr;
    size = 0;
}

template <ComparableAndPrintable T>
AVLTree<T>::~AVLTree() {
    std::cout << "Destroying AVL Tree" << std::endl;
}

template <ComparableAndPrintable T>
int AVLTree<T>::getSize() {
    return size;
}

template <ComparableAndPrintable T>
void AVLTree<T>::insert(T elem) {
    pRoot = insert(pRoot, elem);
}

template <ComparableAndPrintable T>
void AVLTree<T>::remove(T elem) {
    pRoot = remove(pRoot, elem);
}
