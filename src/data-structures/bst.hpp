//
//  bst.hpp
//  data-structures-and-algorithms
//
//  Created by Benjamin Dixon on 4/2/24.
//

#ifndef bst_hpp
#define bst_hpp

#include <iostream>

#include "comparable-printable.hpp"

template <ComparableAndPrintable T>
class BSTNode {
public:
    BSTNode<T>* pLeft = nullptr;
    BSTNode<T>* pRight = nullptr;
    T element;
    BSTNode<T>();
    ~BSTNode<T>();
};

template <ComparableAndPrintable T>
class BST {
public:
    BSTNode<T>* pRoot = nullptr;
    BST<T>();
    ~BST<T>();
//    insert(T elem);
};

#include "bst.tpp"

#endif /* bst_hpp */
