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

class DLinkedListNode {
public:
    DLinkedListNode* pNext;
    DLinkedListNode* pPrev;
    int element;
    DLinkedListNode(int elem);
    ~DLinkedListNode();
};

class DLinkedList {
private:
    int size;
    DLinkedListNode* reverseRecursive(DLinkedListNode* head);
public:
    DLinkedListNode* pHead;
    DLinkedListNode* pTail;
    DLinkedList();
    ~DLinkedList();
    int getSize();
    void addHead(int elem);
    void addTail(int elem);
    std::optional<int> removeHead();
    std::optional<int> removeTail();
    void reverse();
    void reverseRecursive();
    void printInReverse();
};

std::ostream& operator<<(std::ostream& os, DLinkedList& dll);

#endif /* dlinked_list_hpp */
