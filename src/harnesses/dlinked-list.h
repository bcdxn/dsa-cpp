//
//  dlinked-list.cpp
//  data-structures-and-algorithms
//
//  Created by Benjamin Dixon on 4/3/24.
//

//---------------------------------------------------------------------------------------
// Doubly Linked List Test Harness
//---------------------------------------------------------------------------------------
#include "dlinked-list.hpp"

void runDLinkedListHarness() {
    using std::cout;

    DLinkedList<int> dll{};
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
    
    cout << "---------------------------------------------------------------------------\n";
    cout << "Reversing the list recursively:\n";
    dll.reverseRecursive();
    cout << dll << '\n';
    cout << "---------------------------------------------------------------------------\n";
    
    dll.printInReverse();
}
