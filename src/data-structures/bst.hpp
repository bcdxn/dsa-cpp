//
//  bst.hpp
//  data-structures-and-algorithms
//
//  Created by Benjamin Dixon on 4/2/24.
//

#ifndef bst_hpp
#define bst_hpp

#include <iostream>
#include <optional>

#include "comparable-printable.hpp"

template <ComparableAndPrintable T>
class BSTNode {
public:
    BSTNode<T>* pLeft = nullptr;
    BSTNode<T>* pRight = nullptr;
    T element;
    BSTNode<T>(T elem);
    ~BSTNode<T>();
};

template <ComparableAndPrintable T>
class BST {
private:
    int size;
    BSTNode<T>* insert(BSTNode<T>* root, T elem);
    BSTNode<T>* find(BSTNode<T>* root, T elem);
    BSTNode<T>* remove(BSTNode<T>* root, T elem);
    std::optional<T> findMax(BSTNode<T>* root);
    std::optional<T> findMin(BSTNode<T>* root);
public:
    BSTNode<T>* pRoot = nullptr;
    BST<T>();
    ~BST<T>();
    int getSize();
    void insert(T elem);
    bool find(T elem);
    void remove(T elem);
    std::optional<T> findMax();
    std::optional<T> findMin();
};

#include "bst.tpp"

#endif /* bst_hpp */
