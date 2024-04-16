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
    
    std::cout << "contains 'hi': " << ht.contains("hi") << std::endl;
    std::cout << "contains 'hello': " << ht.contains("hello") << std::endl;
    std::cout << "contains 'wat': " << ht.contains("wat") << std::endl;
}
