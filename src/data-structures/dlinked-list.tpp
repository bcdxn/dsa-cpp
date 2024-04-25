//
//  dlinked-list.cpp
//  Data Structures and Algorithms
//

#include <iostream>
#include <optional>

#include "dlinked-list.hpp"

template <Printable T>
DLinkedListNode<T>::DLinkedListNode(T elem): element(elem) {
    pNext = nullptr;
    pPrev = nullptr;
}

template <Printable T>
DLinkedListNode<T>::~DLinkedListNode() {
    std::cout << "[DEBUG] " << "DLinkedListNode(" << element << ") Destructor called\n";
    // TODO
}

template <Printable T>
DLinkedList<T>::DLinkedList() {
    pHead = nullptr;
    pTail = nullptr;
    size = 0;
}

template <Printable T>
DLinkedList<T>::~DLinkedList() {
    std::cout << "[DEBUG] " << "DLinkedList Destructor called\n";
    // TODO
}

template <Printable T>
int DLinkedList<T>::getSize() {
    return size;
}

// Add an element at the head of the list
template <Printable T>
void DLinkedList<T>::addHead(T elem) {
    if (!pHead) {
        pHead = new DLinkedListNode<T>(elem);
        pTail = pHead;
    } else {
        DLinkedListNode<T>* tmp = pHead;
        pHead = new DLinkedListNode(elem);
        pHead->pNext = tmp;
        tmp->pPrev = pHead;
    }
    
    size++;
}

// Add an element at the end of the list
template <Printable T>
void DLinkedList<T>::addTail(T elem) {
    if (!pTail) {
        // If the list is empty, adding to the head and tail are equivalent
        addHead(elem);
    } else {
        DLinkedListNode<T>* tmp = pTail;
        pTail = new DLinkedListNode(elem);
        pTail->pPrev = tmp;
        tmp->pNext = pTail;
        size++;
    }
}

// Remove an element from the beginning of the list
template <Printable T>
std::optional<T> DLinkedList<T>::removeHead() {
    if (!pHead) {
        // The list is empty so we can return
        return {};
    }
    
    // The list is not empty so we can remove the head and return its element
    
    // store the element at the current head so that it can be returned
    T element = pHead->element;
    
    DLinkedListNode<T>* tmp = pHead;
    pHead = pHead->pNext;
    size--;
    
    if (pHead) {
        // If we removed the last element, pHead will now be a nullptr
        pHead->pPrev = nullptr;
    }
    
    if (size <= 1) {
        // when we're down to a single node (or less) pHead and pTail
        // point to the same element
        pTail = pHead;
    }
    
    delete tmp;
    
    return element;
}

// Remove an element from the end of the list
template <Printable T>
std::optional<T> DLinkedList<T>::removeTail() {
    if (!pTail) {
        // The list is empty so we can return
        return {};
    }
    
    T element = pTail->element;
    DLinkedListNode<T>* tmp = pTail;
    pTail = pTail->pPrev;
    size--;
    
    
    if (pTail) {
        // If we removed the last element, pTail will now be a nullptr
        pTail->pNext = nullptr;
    }
    
    if (size <= 1) {
        // when we're down to a single node (or less) pHead and pTail
        // point to the same element
        pHead = pTail;
    }
    
    
    delete tmp;
    
    return element;
}

template <Printable T>
void DLinkedList<T>::reverse() {
    DLinkedListNode<T>* current = pHead;
    
    pTail = pHead; // we know the current head will become the tail
    
    while (current) {
        // store
        DLinkedListNode<T>* tmp = current->pNext;
        // process
        current->pNext = current->pPrev;
        current->pPrev = tmp;
        pHead = current;
        // iterate
        current = tmp;
    }
}

template <Printable T>
DLinkedListNode<T>* DLinkedList<T>::reverseRecursive(DLinkedListNode<T>* head) {
    // base case 1 (an empty list is sorted)
    if (!head) { return head; }
    // base case 2 (a list of size 1 is sorted)
    if (!(head->pNext)) {
        // we need to clear the pPrev pointer since this node becomes the new head
        head->pPrev = nullptr;
        return head;
    }
    
    // reverse everything to the nezt of the current node
    DLinkedListNode<T>* newHead = reverseRecursive(head->pNext);
    head->pNext->pNext = head; // reverse current node
    head->pPrev = head->pNext;
    // The current node becomes the tail
    head->pNext = nullptr;
    pTail = head;
    
    return newHead;
}

template <Printable T>
void DLinkedList<T>::reverseRecursive() {
    pHead = reverseRecursive(pHead);
}

template <Printable T>
void DLinkedList<T>::printInReverse() {
    using std::cout;
    
    cout << "---------------------------------------------------------------------------\n";
    cout << "ensure we can still traverse from tail to head\n";
    
    DLinkedListNode<T>* node = pTail;
    
    while (node) {
        cout << node->element << " ";
        node = node->pPrev;
    }
    cout << '\n';
}

template <Printable T>
std::ostream& operator<<(std::ostream& os, DLinkedList<T>& dll) {
    using std::cout;
    
    DLinkedListNode<T>* pNode = dll.pHead;
    
    cout << "dll: size("
        << dll.getSize()
        << ") head("
        << (dll.pHead ? dll.pHead->element : -1 )
        << ") tail("
        << (dll.pTail ? dll.pTail->element : -1 )
        << ") [";
    
    while (pNode) {
        cout << pNode->element << " ";
        pNode = pNode->pNext;
    }
    
    cout << "]";
    
    return os;
}
