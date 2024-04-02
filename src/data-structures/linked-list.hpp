//
//  linked-list.hpp
//  Data Structures and Algorithms
//
//  Created by Benjamin Dixon on 3/31/24.
//

#ifndef linked_list_hpp
#define linked_list_hpp

#include <stdio.h>
#include <optional>

class LinkedListNode {
public:
    int element;
    LinkedListNode* pNext;
    LinkedListNode(int element);
    ~LinkedListNode();
};

class LinkedList {
private:
    int size;
    LinkedListNode* reverseRecursive(LinkedListNode* head);
public:
    LinkedListNode* pHead;
    LinkedList();
    ~LinkedList();
    int getSize();
    void addHead(int elem);
    std::optional<int> removeHead();
    void reverse();
    void reverseRecursive();
};

std::ostream& operator<<(std::ostream& os, LinkedList &ll);

#endif /* linked_list_hpp */
