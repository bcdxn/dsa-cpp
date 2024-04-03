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
std::string Stack<T>::toString() {
    std::string str = "";
    LinkedListNode<T>* node = ll->pHead;
    
    while (node) {
        str += std::to_string(node->element) + " ";
        node = node->pNext;
    }
    
    return "Stack: height(" + std::to_string(getHeight()) + ")[ " + str + "]";
}

template <typename T>
void Stack<T>::push(T element) {
    ll->addHead(element);
}

template <typename T>
std::optional<T> Stack<T>::pop() {
    return ll->removeHead();
}

template <typename T>
std::ostream& operator<<(std::ostream& os, Stack<T>& s) {
    os << s.toString();
    return os;
}
