//
//  hash-table.hpp
//  data-structures-and-algorithms
//
//  Created by Benjamin Dixon on 4/9/24.
//

#ifndef hash_table_hpp
#define hash_table_hpp

#include <string>
#include <vector>

#include "linked-list.hpp"

class HashTable {
private:
    std::vector<LinkedList<std::string>>* table;
    int filled = 0;
    bool isFillFactorExceeded();
    int getHash(std::string item);
    void resize();
    void hashHelper(std::string item, std::vector<LinkedList<std::string>>* t);
public:
    HashTable();
    ~HashTable();
    void add(std::string item);
};

#include "hash-table.tpp"

#endif /* hash_table_hpp */
