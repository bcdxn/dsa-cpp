//
//  linked-list.cpp
//  Data Structures and Algorithms
//
//  Created by Benjamin Dixon on 3/31/24.
//

#include <iostream>
#include <optional>

#include "linked-list.hpp"

template <typename T>
LinkedListNode<T>::LinkedListNode(T elem) : element(elem) {
    pNext = nullptr;
}

template <typename T>
LinkedListNode<T>::~LinkedListNode() {
    std::cout << "[DEBUG] " << "LinkedListNode(" << element << ") Destructor called\n";
    pNext = nullptr;
}

template <typename T>
LinkedList<T>::LinkedList() {
    pHead = nullptr;
    size = 0;
}

template <typename T>
LinkedList<T>::~LinkedList() {
    std::cout << "[DEBUG] " << "LinkedList Destructor called\n";
    // TODO
}

template <typename T>
int LinkedList<T>::getSize() {
    return size;
}

// Add a node to the beginning of the linked list
template <typename T>
void LinkedList<T>::addHead(T elem) {
    LinkedListNode<T>* newHead = new LinkedListNode<T>(elem);
    newHead->pNext = pHead;
    pHead = newHead;
    size++;
}

template <typename T>
std::optional<T> LinkedList<T>::removeHead() {
    // Get the current head (the node that will be removed)
    LinkedListNode<T>* tmp = pHead;
    // If head is already pointing to null, then there are no nodes to remove
    if (!pHead) {
        return {};
    }
    // Store the element in the node to be removed so we can return it to the caller
    int removed = tmp->element;
    // To remove a node we simply set the Head to the next node;
    pHead = pHead->pNext;
    // clean up the deleted node
    delete tmp;
    // decrement the size
    size--;
    // Return the removed element
    return removed;
}

// in-place reversal
// 30 -> 20 -> 10 -> null
// 10 -> 20 -> 30 -> null
template <typename T>
void LinkedList<T>::reverse() {
    // Start at the head
    LinkedListNode<T>* current = pHead;
    // Keep track of previous node so the next node can point to it
    LinkedListNode<T>* previous = nullptr;
    
    while (current) {
        // store next node
        LinkedListNode<T>* tmp = current->pNext;
        // process current node
        current->pNext = previous;
        pHead = current;
        // iterate
        previous = current;
        current = tmp;
    }
}

template <typename T>
LinkedListNode<T>* LinkedList<T>::reverseRecursive(LinkedListNode<T>* head) {
    // base case 1 (an empty list is sorted)
    if (!head) { return head; }
    // base case 2 (list of length 1 is sorted)
    if (!(head->pNext)) { return head; }
    
    // reverse everything to the next of the current node
    LinkedListNode<T>* newHead = reverseRecursive(head->pNext);
    // once we've returned from the recursive call everything
    // to the next of the current node is reversed; we simply
    // need to reverse the current node.
    head->pNext->pNext = head; // reverse current node
    // our current node becomes the tail of the reversed list
    head->pNext = nullptr;
    
    return newHead;
}

template <typename T>
void LinkedList<T>::reverseRecursive() {
    pHead = reverseRecursive(pHead);
}

// Override the '<<' operator so we can easily print the LinkedList
template <typename T>
std::ostream& operator<<(std::ostream& os, LinkedList<T> &ll) {
    using std::cout;
    
    LinkedListNode<T>* pNode = ll.pHead;
    
    cout << "ll: size("
        << ll.getSize()
        << ") head("
        << (ll.pHead ? ll.pHead->element : -1 )
        << ") [ ";
    
    while (pNode) {
        cout << pNode->element << " ";
        pNode = pNode->pNext;
    }
    
    cout << "]";
    
    return os;
}
