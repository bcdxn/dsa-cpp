//
//  bst.cpp
//  data-structures-and-algorithms
//
//  Created by Benjamin Dixon on 4/2/24.
//

#include <iostream>

#include "bst.hpp"

template <ComparableAndPrintable T>
BSTNode<T>::BSTNode() {}

template <ComparableAndPrintable T>
BSTNode<T>::~BSTNode() {
    std::cout << "Destructing BSTNode(" << std::to_string(element) << ")" << std::endl;
}

template <ComparableAndPrintable T>
BST<T>::BST() {}

template <ComparableAndPrintable T>
BST<T>::~BST() {
    std::cout << "Destructing BST" << std::endl;
}
