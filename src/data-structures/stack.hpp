//
//  stack.hpp
//  data-structures-and-algorithms
//
//  Created by Benjamin Dixon on 4/2/24.
//

#ifndef stack_hpp
#define stack_hpp

#include <iostream>
#include <optional>
#include <string>

#include "comparable-printable.hpp"
#include "linked-list.hpp"

template <Printable T>
class Stack {
private:
    LinkedList<T>* ll = nullptr;
public:
    Stack<T>();
    ~Stack<T>();
    int getHeight();
    void push(T element);
    std::optional<T> pop();
    // Enable `std::cout << queue;` syntax
    friend std::ostream& operator<<(std::ostream& os, Stack<T>& s) {
        std::cout << "Stack: height(" << s.getHeight() << ")[" << *s.ll << "]";
        return os;
    }
};


#include "stack.tpp"

#endif /* stack_hpp */
