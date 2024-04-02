//
//  dlinked-list.cpp
//  Data Structures and Algorithms
//
//  Created by Benjamin Dixon on 3/31/24.
//

#include <iostream>
#include <optional>

#include "dlinked-list.hpp"

DLinkedListNode::DLinkedListNode(int elem): element(elem) {
    pNext = nullptr;
    pPrev = nullptr;
}

DLinkedListNode::~DLinkedListNode() {
    std::cout << "[DEBUG] " << "DLinkedListNode(" << element << ") Destructor called\n";
    // TODO
}

DLinkedList::DLinkedList() {
    pHead = nullptr;
    pTail = nullptr;
    size = 0;
}

DLinkedList::~DLinkedList() {
    std::cout << "[DEBUG] " << "DLinkedList Destructor called\n";
    // TODO
}

int DLinkedList::getSize() {
    return size;
}

// Add an element at the head of the list
void DLinkedList::addHead(int elem) {
    if (!pHead) {
        pHead = new DLinkedListNode(elem);
        pTail = pHead;
    } else {
        DLinkedListNode* tmp = pHead;
        pHead = new DLinkedListNode(elem);
        pHead->pNext = tmp;
        tmp->pPrev = pHead;
    }
    
    size++;
}

// Add an element at the end of the list
void DLinkedList::addTail(int elem) {
    if (!pTail) {
        // If the list is empty, adding to the head and tail are equivalent
        addHead(elem);
    } else {
        DLinkedListNode* tmp = pTail;
        pTail = new DLinkedListNode(elem);
        pTail->pPrev = tmp;
        tmp->pNext = pTail;
        size++;
    }
}

// Remove an element from the beginning of the list
std::optional<int> DLinkedList::removeHead() {
    if (!pHead) {
        // The list is empty so we can return
        return {};
    }
    
    // The list is not empty so we can remove the head and return its element
    
    // store the element at the current head so that it can be returned
    int element = pHead->element;
    
    DLinkedListNode* tmp = pHead;
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
std::optional<int> DLinkedList::removeTail() {
    if (!pTail) {
        // The list is empty so we can return
        return {};
    }
    
    int element = pTail->element;
    DLinkedListNode* tmp = pTail;
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


void DLinkedList::reverse() {
    DLinkedListNode* current = pHead;
    DLinkedListNode* previous = nullptr;
    
    while (current) {
        // store next
        DLinkedListNode* tmp = current->pNext;
        // process node
        current->pNext = previous;
        pHead = current;
        current->pPrev = nullptr;
        
        if (previous) {
            previous->pPrev = current;
        } else {
            pTail = current;
        }
        
        // iterate
        previous = current;
        current = tmp;
    }
    return;
}

DLinkedListNode* DLinkedList::reverseRecursive(DLinkedListNode* head) {
    // base case 1 (an empty list is sorted)
    if (!head) { return head; }
    // base case 2 (a list of size 1 is sorted)
    if (!(head->pNext)) {
        // we need to clear the pPrev pointer since this node becomes the new head
        head->pPrev = nullptr;
        return head;
    }
    
    // reverse everything to the nezt of the current node
    DLinkedListNode* newHead = reverseRecursive(head->pNext);
    head->pNext->pNext = head; // reverse current node
    head->pPrev = head->pNext;
    // The current node becomes the tail
    head->pNext = nullptr;
    pTail = head;
    
    return newHead;
}

void DLinkedList::reverseRecursive() {
    pHead = reverseRecursive(pHead);
}

void DLinkedList::printInReverse() {
    using std::cout;
    
    cout << "---------------------------------------------------------------------------\n";
    cout << "ensure we can still traverse from tail to head\n";
    
    DLinkedListNode* node = pTail;
    
    while (node) {
        cout << node->element << " ";
        node = node->pPrev;
    }
    cout << '\n';
}

std::ostream& operator<<(std::ostream& os, DLinkedList& dll) {
    using std::cout;
    
    DLinkedListNode* pNode = dll.pHead;
    
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
