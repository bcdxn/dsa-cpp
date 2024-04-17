//
//  min-heap.cpp
//  data-structures-and-algorithms
//
//  Created by Benjamin Dixon on 4/16/24.
//

#include <iostream>
#include <string>

#include "min-heap.hpp"

void runMinHeapHarness() {
    using std::cout;
    
    cout << "---------------------------------------------------------------------------\n";
    cout << "Running MinHeap test harness\n";
    
    MinHeap<int> h{};
    h.push(10);
    h.push(15);
    h.push(20);
    
    cout << h << std::endl;
    
    h.push(5);
    
    cout << h << std::endl;
    
    h.pop();
    
    cout << h << std::endl;
    
    h.push(4);
    h.push(100);
    h.push(16);
    
    cout << h << std::endl;
    
    while (h.getSize() > 0) {
        h.pop();
        cout << h << std::endl;
    }
}
