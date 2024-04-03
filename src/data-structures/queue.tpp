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


template <ComparableAndPrintable T>
Queue<T>::Queue() {
    ll = new DLinkedList<T>();
}

template <ComparableAndPrintable T>
Queue<T>::~Queue() {
    std::cout << "[DEBUG]" << "Destroying queue\n";
}

template <ComparableAndPrintable T>
int Queue<T>::getDepth() {
    return ll->getSize();
}

template <ComparableAndPrintable T>
void Queue<T>::enqueue(T element) {
    ll->addHead(element);
}

template <ComparableAndPrintable T>
std::optional<T> Queue<T>::dequeue() {
    return ll->removeTail();
}

