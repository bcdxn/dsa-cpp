//
//  avl-tree.hpp
//  data-structures-and-algorithms
//
//  Created by Benjamin Dixon on 4/6/24.
//

#ifndef avl_tree_hpp
#define avl_tree_hpp

#include <optional>

#include "comparable-printable.hpp"

template <ComparableAndPrintable T>
class AVLTreeNode {
private:
    int maxHeight(AVLTreeNode<T>* node);
public:
    T element;
    AVLTreeNode<T>* pLeft;
    AVLTreeNode<T>* pRight;
    AVLTreeNode(T element);
    ~AVLTreeNode();
    int maxHeight();
};

template <ComparableAndPrintable T>
class AVLTree {
private:
    int size = 0;
    AVLTreeNode<T>* insert(AVLTreeNode<T>* root, T elem);
    AVLTreeNode<T>* remove(AVLTreeNode<T>* root, T elem);
    int maxChildHeight(AVLTreeNode<T>* node);
    int getBalanceFactor(AVLTreeNode<T>* node);
    AVLTreeNode<T>* balance(AVLTreeNode<T>* root);
    std::optional<T> findMin(AVLTreeNode<T>* root);
    AVLTreeNode<T>* leftRotation(AVLTreeNode<T>* root);
    AVLTreeNode<T>* rightRotation(AVLTreeNode<T>* root);
    AVLTreeNode<T>* leftRightRotation(AVLTreeNode<T>* root);
    AVLTreeNode<T>* rightLeftRotation(AVLTreeNode<T>* root);
public:
    AVLTreeNode<T>* pRoot = nullptr;
    AVLTree<T>();
    ~AVLTree<T>();
    int getSize();
    void insert(T elem);
    void remove(T elem);
};

#include "avl-tree.tpp"

#endif /* avl_tree_hpp */
