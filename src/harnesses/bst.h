//
//  bst.cpp
//  data-structures-and-algorithms
//

//---------------------------------------------------------------------------------------
// Binary Search Tree Test Harness
//---------------------------------------------------------------------------------------
#include "bst.hpp"

void runBstHarness() {
    using std::cout;
    
    BST<int> bst{};
    
    bst.insert(10);
    bst.insert(5);
    bst.insert(15);
    bst.insert(7);
    
    cout << "find(10): " << bst.find(10) << std::endl;
    cout << "find(7): " << bst.find(7) << std::endl;
    cout << "find(5): " << bst.find(5) << std::endl;
    cout << "find(100): " << bst.find(100) << std::endl;
    cout << "find(6): " << bst.find(6) << std::endl;
    
    bst.insert(2);
    bst.insert(4);
    bst.insert(1);
    
    cout << "find(4): " << bst.find(4) << std::endl;
    
    cout << "find(5): " << bst.find(5) << std::endl;
    
    cout << "remove(5): " << std::endl;
    bst.remove(5);
    cout << "find(5): " << bst.find(5) << std::endl;
    
    auto max = bst.findMax();
    auto min = bst.findMin();
    
    cout << "findMax: " << (max ? max.value() : -1) << std::endl;
    cout << "findMin: " << (min ? min.value() : -1) << std::endl;
}
