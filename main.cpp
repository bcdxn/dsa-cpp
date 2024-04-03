//
//  main.cpp
//  Data Structures and Algorithms
//
//  Created by Benjamin Dixon on 3/31/24.
//

#include <iostream>

////---------------------------------------------------------------------------------------
//// Standard Linked List Test Harness
////---------------------------------------------------------------------------------------
//#include "linked-list.hpp"
//
//int main(int argc, const char * argv[]) {
//    using std::cout;
//    
//    LinkedList<int> ll{};
//    cout << ll << '\n';
//    
//    cout << "---------------------------------------------------------------------------\n";
//    
//    for (int i = 1; i < 11; i++) {
//        ll.addHead(i * 10);
//        cout << ll << '\n';
//    }
//    
//    
//    cout << "---------------------------------------------------------------------------\n";
//    
//    for (int i = 0; i < 10; i++) {
//        std::optional<int> removed = ll.removeHead();
//        cout << "removed: " << (removed ? removed.value() : -1) << '\n';
//        cout << ll << '\n';
//    }
//    
//    cout << "---------------------------------------------------------------------------\n";
//    
//    std::optional<int> emptyRemoval = ll.removeHead();
//    
//    if (emptyRemoval) {
//        cout << "FAILED - removed: " << emptyRemoval.value() << '\n';
//    } else {
//        cout << "PASSED - list was empty\n";
//    }
//    
//    cout << ll << '\n';
//    
//    cout << "---------------------------------------------------------------------------\n";
//    
//    for (int i = 1; i < 11; i++) {
//        ll.addHead(i * 10);
//    }
//    
//    cout << ll << '\n';
//    cout << "Reversing the list:\n";
//    
//    ll.reverse();
//    cout << ll << '\n';
//    
//    cout << "---------------------------------------------------------------------------\n";
//    cout << "Reversing the list recursively:\n";
//    ll.reverseRecursive();
//    cout << ll << '\n';
//    
//    
//    
//    return 0;
//}


////---------------------------------------------------------------------------------------
//// Doubly Linked List Test Harness
////---------------------------------------------------------------------------------------
//#include "dlinked-list.hpp"
//
//int main(int argc, const char * argv[]) {
//    using std::cout;
//
//    DLinkedList<int> dll{};
//    cout << dll << '\n';
//
//    cout << "---------------------------------------------------------------------------\n";
//
//    for (int i = 1; i < 11; i++) {
//        dll.addHead(i * 10);
//        cout << dll << '\n';
//    }
//    
//    dll.printInReverse();
//    
//    cout << "---------------------------------------------------------------------------\n";
//
//    for (int i = 1; i < 11; i++) {
//        dll.addTail(i * 10);
//        cout << dll << '\n';
//    }
//    
//    cout << "---------------------------------------------------------------------------\n";
//    
//    for (int i = 0; i < 10; i++) {
//        dll.removeHead();
//        cout << dll << '\n';
//    }
//    
//    dll.printInReverse();
//    
//    cout << "---------------------------------------------------------------------------\n";
//    
//    for (int i = 0; i < 10; i++) {
//        dll.removeTail();
//        cout << dll << '\n';
//    }
//    
//    cout << "---------------------------------------------------------------------------\n";
//
//    std::optional<int> emptyRemoval = dll.removeHead();
//
//    if (emptyRemoval) {
//        cout << "FAILED - removed: " << emptyRemoval.value() << '\n';
//    } else {
//        cout << "PASSED - list was empty\n";
//    }
//
//    cout << dll << '\n';
//
//    cout << "---------------------------------------------------------------------------\n";
//
//    for (int i = 1; i < 6; i++) {
//        dll.addHead(i * 10);
//    }
//    
//    dll.printInReverse();
//
//    cout << dll << '\n';
//    cout << "Reversing the list:\n";
//
//    dll.reverse();
//    cout << dll << '\n';
//    
//    dll.printInReverse();
//    
//    cout << "---------------------------------------------------------------------------\n";
//    cout << "Reversing the list recursively:\n";
//    dll.reverseRecursive();
//    cout << dll << '\n';
//    cout << "---------------------------------------------------------------------------\n";
//    
//    dll.printInReverse();
//
//    return 0;
//}


////---------------------------------------------------------------------------------------
//// Queue Test Harness
////---------------------------------------------------------------------------------------
//#include "queue.hpp"
//
//
//int main(int argc, const char * argv[]) {
//    using std::cout;
//    
//    Queue<int> q{};
//    
//    for (int i = 0; i < 10; i++) {
//        cout << "enqueuing: " << i << std::endl;
//        q.enqueue(i);
//        cout << q << std::endl;
//    }
//    
//    cout << "---------------------------------------------------------------------------\n";
//
//    for (int i = 0; i < 10; i++) {
//        auto dequeued = q.dequeue();
//        cout << "dequeueing: " << (dequeued.has_value() ? dequeued.value() : -1) << std::endl;
//        cout << q << std::endl;
//    }
//    
//    return 0;
//}


//---------------------------------------------------------------------------------------
// Stack Test Harness
//---------------------------------------------------------------------------------------
#include "stack.hpp"

int main(int argc, const char * argv[]) {
    using std::cout;
    
    Stack<int> stk{};
    
    for (int i = 0; i < 10; i++) {
        cout << "pushing: " << i << std::endl;
        stk.push(i);
        cout << stk << std::endl;
    }
    
    cout << "---------------------------------------------------------------------------\n";

    for (int i = 0; i < 10; i++) {
        auto popped = stk.pop();
        cout << "popping: " << (popped.has_value() ? popped.value() : -1) << std::endl;
        cout << stk << std::endl;
    }
    
    return 0;
}

////---------------------------------------------------------------------------------------
//// Binary Search Tree Test Harness
////---------------------------------------------------------------------------------------
//#include "bst.hpp"
//
//int main(int argc, const char * argv[]) {
//    using std::cout;
//    
//    BST<int> bst{};
//    
//    return 0;
//}
