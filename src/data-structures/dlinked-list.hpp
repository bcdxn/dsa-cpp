//
//  dlinked-list.hpp
//  Data Structures and Algorithms
//
//  Created by Benjamin Dixon on 3/31/24.
//

#ifndef dlinked_list_hpp
#define dlinked_list_hpp

#include <iostream>
#include <optional>

#include "comparable-printable.hpp"

template <Printable T>
class DLinkedListNode {
public:
    DLinkedListNode<T>* pNext;
    DLinkedListNode<T>* pPrev;
    T element;
    DLinkedListNode(T elem);
    ~DLinkedListNode();
};

template <Printable T>
class DLinkedList {
private:
    int size;
    DLinkedListNode<T>* reverseRecursive(DLinkedListNode<T>* head);
public:
    DLinkedListNode<T>* pHead;
    DLinkedListNode<T>* pTail;
    DLinkedList<T>();
    ~DLinkedList<T>();
    int getSize();
    void addHead(T elem);
    void addTail(T elem);
    std::optional<T> removeHead();
    std::optional<T> removeTail();
    void reverse();
    void reverseRecursive();
    void printInReverse();
};

template <Printable T>
std::ostream& operator<<(std::ostream& os, DLinkedList<T>& dll);

#include "dlinked-list.tpp"

#endif /* dlinked_list_hpp */
