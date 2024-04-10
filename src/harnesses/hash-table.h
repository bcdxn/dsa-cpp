//
//  hash-table.cpp
//  data-structures-and-algorithms
//
//  Created by Benjamin Dixon on 4/9/24.
//

#include <iostream>
#include <string>

#include "hash-table.hpp"

void runHashTableHarness() {
    HashTable ht{};
    std::cout << "adding 'hello'" << std::endl;
    
    ht.add("hello");
    ht.add("hi");
}
