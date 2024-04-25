//
//  avl-tree.cpp
//  data-structures-and-algorithms
//

#include <iostream>

#include "avl-tree.hpp"

void runAVLTreeHarness() {

    AVLTree<int> t{};

    t.insert(5);
    t.insert(3);
    t.insert(10);
    t.insert(2);
    t.insert(7);
    t.insert(15);
    t.insert(17);
    
    std::cout << "wat" << std::endl;
    
    /*
         5
        / \
       3   10
      /   /  \
     2   7   15
               \
               17
    */
    
    t.remove(5); // causes a left rotation at node 15
    
    /*
         7
        / \
       3   15
      /   / \
     2   10  17
     
    */
    
    AVLTree<int> t2{};
    
    t2.insert(2);
    t2.insert(4);
    t2.insert(3); // causes a left-right rotation at node 15
    
    /*
         2             2                   3
          \             \                 / \
           4   ----->    3     ----->    2   4
          /               \
         3                 4
    */
    
    
    std::cout << "done" << std::endl;
}
