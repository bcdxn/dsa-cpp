//
//  linked-list.cpp
//  data-structures-and-algorithms
//
//  Created by Benjamin Dixon on 4/3/24.
//

#include <iostream>

//---------------------------------------------------------------------------------------
// Standard Linked List Test Harness
//---------------------------------------------------------------------------------------
#include "linked-list.hpp"

void runLinkedListHarness() {
    using std::cout;

    LinkedList<int> ll{};
    cout << ll << '\n';

    cout << "---------------------------------------------------------------------------\n";

    for (int i = 1; i < 11; i++) {
        ll.addHead(i * 10);
        cout << ll << '\n';
    }


    cout << "---------------------------------------------------------------------------\n";

    for (int i = 0; i < 10; i++) {
        std::optional<int> removed = ll.removeHead();
        cout << "removed: " << (removed ? removed.value() : -1) << '\n';
        cout << ll << '\n';
    }

    cout << "---------------------------------------------------------------------------\n";

    std::optional<int> emptyRemoval = ll.removeHead();

    if (emptyRemoval) {
        cout << "FAILED - removed: " << emptyRemoval.value() << '\n';
    } else {
        cout << "PASSED - list was empty\n";
    }

    cout << ll << '\n';

    cout << "---------------------------------------------------------------------------\n";

    for (int i = 1; i < 11; i++) {
        ll.addHead(i * 10);
    }

    cout << ll << '\n';
    cout << "Reversing the list:\n";

    ll.reverse();
    cout << ll << '\n';

    cout << "---------------------------------------------------------------------------\n";
    cout << "Reversing the list recursively:\n";
    ll.reverseRecursive();
    cout << ll << '\n';
}
