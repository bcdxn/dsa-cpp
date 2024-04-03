//
//  stack.hpp
//  data-structures-and-algorithms
//
//  Created by Benjamin Dixon on 4/2/24.
//

#ifndef stack_hpp
#define stack_hpp

#include <optional>
#include <string>

#include "linked-list.hpp"

template <typename T>
class Stack {
private:
    LinkedList<T>* ll = nullptr;
public:
    Stack<T>();
    ~Stack<T>();
    int getHeight();
    std::string toString();
    void push(T element);
    std::optional<T> pop();
};

template <typename T>
std::ostream& operator<<(std::ostream& os, Stack<T>& s);

#include "stack.tpp"

#endif /* stack_hpp */
