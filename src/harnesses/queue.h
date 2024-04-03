//
//  queue.cpp
//  data-structures-and-algorithms
//
//  Created by Benjamin Dixon on 4/3/24.
//

//---------------------------------------------------------------------------------------
// Queue Test Harness
//---------------------------------------------------------------------------------------
#include "queue.hpp"

void runQueueHarness() {
    using std::cout;
    
    Queue<int> q{};
    
    for (int i = 0; i < 10; i++) {
        cout << "enqueuing: " << i << std::endl;
        q.enqueue(i);
        cout << q << std::endl;
    }
    
    cout << "---------------------------------------------------------------------------\n";

    for (int i = 0; i < 10; i++) {
        auto dequeued = q.dequeue();
        cout << "dequeueing: " << (dequeued.has_value() ? dequeued.value() : -1) << std::endl;
        cout << q << std::endl;
    }
}
