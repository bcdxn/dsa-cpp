//
//  stack.h
//  data-structures-and-algorithms
//
//  Created by Benjamin Dixon on 4/3/24.
//

//---------------------------------------------------------------------------------------
// Stack Test Harness
//---------------------------------------------------------------------------------------
#include "stack.hpp"

void runStackHarness() {
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
}
