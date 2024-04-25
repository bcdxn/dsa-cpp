//
//  stack.cpp
//  data-structures-and-algorithms
//

#include <iostream>
#include <optional>
#include <string>

#include "comparable-printable.hpp"
#include "stack.hpp"

template <Printable T>
Stack<T>::Stack() {
    ll = new LinkedList<T>;
}

template <Printable T>
Stack<T>::~Stack() {
    std::cout << "Destructing Stack" << std::endl;
    delete ll;
}

template <Printable T>
int Stack<T>::getHeight() {
    return ll->getSize();
}

template <Printable T>
void Stack<T>::push(T element) {
    ll->addHead(element);
}

template <Printable T>
std::optional<T> Stack<T>::pop() {
    return ll->removeHead();
}
