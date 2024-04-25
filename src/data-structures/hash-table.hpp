//
//  hash-table.hpp
//  data-structures-and-algorithms
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
    int getIndex(std::string item, std::vector<LinkedList<std::string>>* t);
    void resize();
public:
    HashTable();
    ~HashTable();
    void add(std::string item);
    bool contains(std::string item);
};

#include "hash-table.tpp"

#endif /* hash_table_hpp */
