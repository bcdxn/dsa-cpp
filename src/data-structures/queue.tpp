//
//  queue.cpp
//  data-structures-and-algorithms
//
//  Created by Benjamin Dixon on 4/2/24.
//


#include <iostream>
#include <optional>
#include <string>

#include "dlinked-list.hpp"
#include "queue.hpp"


template <typename T>
Queue<T>::Queue() {
    ll = new DLinkedList<T>();
}

template <typename T>
Queue<T>::~Queue() {
    std::cout << "[DEBUG]" << "Destroying queue\n";
}

template <typename T>
int Queue<T>::getDepth() {
    return ll->getSize();
}

template <typename T>
void Queue<T>::enqueue(T element) {
    ll->addHead(element);
}

template <typename T>
std::optional<T> Queue<T>::dequeue() {
    return ll->removeTail();
}

template <typename T>
std::string Queue<T>::toString() {
    std::string str = "";
    
    DLinkedListNode<T>* node = ll->pHead;
    
    while (node) {
        str += std::to_string(node->element) + " ";
        node = node->pNext;
    }
    
    return "Queue: depth(" + std::to_string(getDepth()) + ")[ " + str + "]";
}

template <typename T>
std::ostream& operator<<(std::ostream& os, Queue<T>& q) {
    os << q.toString();
    return os;
}
