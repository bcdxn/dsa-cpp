//
//  min-heap.cpp
//  data-structures-and-algorithms
//
//  Created by Benjamin Dixon on 4/16/24.
//

#include <iostream>
#include <vector>

#include "min-heap.hpp"
#include "comparable-printable.hpp"

/* Public
---------------------------------------------------------------------------- */
template <ComparableAndPrintable T>
MinHeap<T>::MinHeap() {
    std::cout << "[DEBUG] "<< "Creating a min heap" << std::endl;
    heap = std::vector<T>(10);
}

template <ComparableAndPrintable T>
MinHeap<T>::~MinHeap() {
    std::cout << "[DEBUG] "<< "Destroying min heap" << std::endl;
}

template <ComparableAndPrintable T>
int MinHeap<T>::getSize() {
    return size;
}

template <ComparableAndPrintable T>
void MinHeap<T>::push(T elem) {
    // check if we nee to resize the underlying vector
    if (size == heap.size()) {
        heap.resize(size * 2);
    }
    int insertIndex = size;
    // Add element to end of array
    heap[size] = elem;
    size++;
    
    int parentIndex = parent(insertIndex);
    
    while (parentIndex >= 0 && heap[insertIndex] < heap[parentIndex]) {
        // swap
        T tmp = heap[parentIndex];
        heap[parentIndex] = heap[insertIndex];
        heap[insertIndex] = tmp;
        insertIndex = parentIndex;
        parentIndex = parent(insertIndex);
    }
}

template <ComparableAndPrintable T>
T MinHeap<T>::peek() {
    return heap[0];
}

template <ComparableAndPrintable T>
T MinHeap<T>::pop() {
    int currentIndex = 0;
    T elem = heap[currentIndex];
    
    if (size > 0) {
        // Move last child to root
        heap[currentIndex] = heap[size - 1];
        heap[size - 1] = NULL;
        size--;

        T lIndex = leftChild(currentIndex);
        T rIndex = rightChild(currentIndex);
        
        while (
           (lIndex < size && heap[currentIndex] > heap[lIndex]) ||
           (rIndex < size && heap[currentIndex] > heap[rIndex])
        ) {
            int smallerChildIndex = lIndex;
            if (rIndex < size && heap[rIndex] < heap[lIndex]) {
                smallerChildIndex = rIndex;
            }
            // Swap curent node with smaller child
            T tmp = heap[smallerChildIndex];
            heap[smallerChildIndex] = heap[currentIndex];
            heap[currentIndex] = tmp;
            // iterate
            currentIndex = smallerChildIndex;
            lIndex = leftChild(currentIndex);
            rIndex = rightChild(currentIndex);
        }
    }
    
    return elem;
}

/* Private
---------------------------------------------------------------------------- */
template <ComparableAndPrintable T>
int MinHeap<T>::parent(int index) {
    return (index - 1) / 2;
}

template <ComparableAndPrintable T>
int MinHeap<T>::leftChild(int index) {
    return (index * 2) + 1;
}

template <ComparableAndPrintable T>
int MinHeap<T>::rightChild(int index) {
    return (index * 2) + 2;
}
