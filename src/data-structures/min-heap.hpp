//
//  min-heap.hpp
//  data-structures-and-algorithms
//

#ifndef min_heap_hpp
#define min_heap_hpp

#include <vector>

#include "comparable-printable.hpp"

template <ComparableAndPrintable T>
class MinHeap {
private:
    int size = 0;
    std::vector<T> heap;
    int parent(int index);
    int leftChild(int index);
    int rightChild(int index);
public:
    MinHeap<T>();
    ~MinHeap();
    int getSize();
    void push(T elem);
    T peek();
    T pop();
    friend std::ostream& operator<<(std::ostream& os, MinHeap<T>& h) {
        std::cout << "MinHeap: size(" << h.getSize() << ")[ ";
        for (int i = 0; i < h.size; i++) {
            std::cout << h.heap[i] << " ";
        }
        std::cout << "]";
        return os;
    }
};

#include "min-heap.tpp"

#endif /* min_heap_hpp */
