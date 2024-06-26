//
//  queue.hpp
//  data-structures-and-algorithms
//

#ifndef queue_hpp
#define queue_hpp

#include <optional>
#include <string>

#include "comparable-printable.hpp"
#include "dlinked-list.hpp"

template <Printable T>
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
