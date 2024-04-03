//
//  queue.hpp
//  data-structures-and-algorithms
//
//  Created by Benjamin Dixon on 4/2/24.
//

#ifndef queue_hpp
#define queue_hpp

#include <optional>
#include <string>

#include "dlinked-list.hpp"
#include "comparable-printable.hpp"

template <ComparableAndPrintable T>
class Queue {
private:
    DLinkedList<T>* ll = nullptr;
public:
    Queue();
    ~Queue();
    int getDepth();
    void enqueue(T element);
    std::optional<T> dequeue();
    // Enable `std::cout << queue;` syntax
    friend std::ostream& operator<<(std::ostream& os, Queue<T>& q){
        os << "Queue: depth(" << q.getDepth() << ")[" << *q.ll << "]";
        return os;
    }
};

#include "queue.tpp"

#endif /* queue_hpp */
