//
//  queue.cpp
//  data-structures-and-algorithms
//
//  Created by Benjamin Dixon on 4/2/24.
//


#include <iostream>
#include <optional>
#include <string>

#include "comparable-printable.hpp"
#include "dlinked-list.hpp"
#include "queue.hpp"


template <Printable T>
Queue<T>::Queue() {
    ll = new DLinkedList<T>();
}

template <Printable T>
Queue<T>::~Queue() {
    std::cout << "[DEBUG]" << "Destroying queue\n";
}

template <Printable T>
int Queue<T>::getDepth() {
    return ll->getSize();
}

template <Printable T>
void Queue<T>::enqueue(T element) {
    ll->addHead(element);
}

template <Printable T>
std::optional<T> Queue<T>::dequeue() {
    return ll->removeTail();
}

