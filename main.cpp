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
//    LinkedList ll{};
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


//---------------------------------------------------------------------------------------
// Doubly Linked List Test Harness
//---------------------------------------------------------------------------------------
#include "dlinked-list.hpp"

int main(int argc, const char * argv[]) {
    using std::cout;

    DLinkedList dll{};
    cout << dll << '\n';

    cout << "---------------------------------------------------------------------------\n";

    for (int i = 1; i < 11; i++) {
        dll.addHead(i * 10);
        cout << dll << '\n';
    }
    
    dll.printInReverse();
    
    cout << "---------------------------------------------------------------------------\n";

    for (int i = 1; i < 11; i++) {
        dll.addTail(i * 10);
        cout << dll << '\n';
    }
    
    cout << "---------------------------------------------------------------------------\n";
    
    for (int i = 0; i < 10; i++) {
        dll.removeHead();
        cout << dll << '\n';
    }
    
    dll.printInReverse();
    
    cout << "---------------------------------------------------------------------------\n";
    
    for (int i = 0; i < 10; i++) {
        dll.removeTail();
        cout << dll << '\n';
    }
    
    cout << "---------------------------------------------------------------------------\n";

    std::optional<int> emptyRemoval = dll.removeHead();

    if (emptyRemoval) {
        cout << "FAILED - removed: " << emptyRemoval.value() << '\n';
    } else {
        cout << "PASSED - list was empty\n";
    }

    cout << dll << '\n';

    cout << "---------------------------------------------------------------------------\n";

    for (int i = 1; i < 6; i++) {
        dll.addHead(i * 10);
    }
    
    dll.printInReverse();

    cout << dll << '\n';
    cout << "Reversing the list:\n";

    dll.reverse();
    cout << dll << '\n';
    
    dll.printInReverse();
    
    cout << '\n';
    
    cout << "---------------------------------------------------------------------------\n";
    cout << "Reversing the list recursively:\n";
    dll.reverseRecursive();
    cout << dll << '\n';
    cout << "---------------------------------------------------------------------------\n";


    return 0;
}

