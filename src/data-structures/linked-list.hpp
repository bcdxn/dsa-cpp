//
//  linked-list.hpp
//  Data Structures and Algorithms
//
//  Created by Benjamin Dixon on 3/31/24.
//

#ifndef linked_list_hpp
#define linked_list_hpp

#include <optional>

#include "comparable-printable.hpp"

template <Printable T>
class LinkedListNode {
public:
    T element;
    LinkedListNode* pNext;
    LinkedListNode(T element);
    ~LinkedListNode();
};

template <Printable T>
class LinkedList {
private:
    int size;
    LinkedListNode<T>* reverseRecursive(LinkedListNode<T>* head);
public:
    LinkedListNode<T>* pHead;
    LinkedList<T>();
    ~LinkedList<T>();
    int getSize();
    void addHead(T elem);
    std::optional<T> removeHead();
    void reverse();
    void reverseRecursive();
};

template<Printable T>
std::ostream& operator<<(std::ostream& os, LinkedList<T> &ll);

#include "linked-list.tpp"

#endif /* linked_list_hpp */
