//
//  stack.cpp
//  data-structures-and-algorithms
//
//  Created by Benjamin Dixon on 4/2/24.
//

#include <iostream>
#include <optional>
#include <string>

#include "stack.hpp"

template <typename T>
Stack<T>::Stack() {
    ll = new LinkedList<T>;
}

template <typename T>
Stack<T>::~Stack() {
    std::cout << "Destructing Stack" << std::endl;
    delete ll;
}

template <typename T>
int Stack<T>::getHeight() {
    return ll->getSize();
}

template <typename T>
void Stack<T>::push(T element) {
    ll->addHead(element);
}

template <typename T>
std::optional<T> Stack<T>::pop() {
    return ll->removeHead();
}
