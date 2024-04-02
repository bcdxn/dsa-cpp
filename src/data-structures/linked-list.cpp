//
//  linked-list.cpp
//  Data Structures and Algorithms
//
//  Created by Benjamin Dixon on 3/31/24.
//

#include <iostream>
#include <optional>

#include "linked-list.hpp"

LinkedListNode::LinkedListNode(int elem) : element(elem) {
    pNext = nullptr;
}

LinkedListNode::~LinkedListNode() {
    std::cout << "[DEBUG] " << "LinkedListNode(" << element << ") Destructor called\n";
    pNext = nullptr;
}

LinkedList::LinkedList() {
    pHead = nullptr;
    size = 0;
}

LinkedList::~LinkedList() {
    std::cout << "[DEBUG] " << "LinkedList Destructor called\n";
    // TODO
}

int LinkedList::getSize() {
    return size;
}

// Add a node to the beginning of the linked list
void LinkedList::addHead(int elem) {
    LinkedListNode* newHead = new LinkedListNode(elem);
    newHead->pNext = pHead;
    pHead = newHead;
    size++;
}

std::optional<int> LinkedList::removeHead() {
    // Get the current head (the node that will be removed)
    LinkedListNode* tmp = pHead;
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
void LinkedList::reverse() {
    // Start at the head
    LinkedListNode* current = pHead;
    // Keep track of previous node so the next node can point to it
    LinkedListNode* previous = nullptr;
    
    while (current) {
        // store next node
        LinkedListNode* tmp = current->pNext;
        // process current node
        current->pNext = previous;
        pHead = current;
        // iterate
        previous = current;
        current = tmp;
    }
}

LinkedListNode* LinkedList::reverseRecursive(LinkedListNode* head) {
    // base case 1 (an empty list is sorted)
    if (!head) { return head; }
    // base case 2 (list of length 1 is sorted)
    if (!(head->pNext)) { return head; }
    
    // reverse everything to the next of the current node
    LinkedListNode* newHead = reverseRecursive(head->pNext);
    // once we've returned from the recursive call everything
    // to the next of the current node is reversed; we simply
    // need to reverse the current node.
    head->pNext->pNext = head; // reverse current node
    // our current node becomes the tail of the reversed list
    head->pNext = nullptr;
    
    return newHead;
}

void LinkedList::reverseRecursive() {
    pHead = reverseRecursive(pHead);
}

// Override the '<<' operator so we can easily print the LinkedList
std::ostream& operator<<(std::ostream& os, LinkedList &ll) {
    using std::cout;
    
    LinkedListNode* pNode = ll.pHead;
    
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
