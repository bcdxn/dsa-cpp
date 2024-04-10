//
//  hash-table.cpp
//  data-structures-and-algorithms
//
//  Created by Benjamin Dixon on 4/9/24.
//

#include <vector>
#include <iostream>
#include <string>

#include "hash-table.hpp"
#include "linked-list.hpp"



/* Private
---------------------------------------------------------------------------- */
int HashTable::getHash(std::string item) {
    // dbj2 hash
    double hash = 5381;
    
    for (int i = 0; i < item.size(); i++) {
        hash = (hash * 33) + item[i];
    }
    
    return hash;
}

bool HashTable::isFillFactorExceeded() {
    float ff = (float)filled / (float)table->size();
    
    return ff >= 0.5;
}

void HashTable::hashHelper(std::string item, std::vector<LinkedList<std::string>>* t) {
    // Calculate Hash
    int hash = getHash(item);
    // Calculate index into table
    int index = hash % t->size();
    // Add item to the hash table
    t->at(index).addHead(item);
}

void HashTable::resize() {
    int growthFactor = 2;
    int newSize = (int)table->size() * growthFactor;
    std::vector<LinkedList<std::string>>* newTable = new std::vector<LinkedList<std::string>>();
    newTable->resize(newSize);
    
    for (int i = 0; i < table->size(); i++) {
        auto node = table->at(i).pHead;
        
        while (node) {
            hashHelper(node->element, newTable);
            node = node->pNext;
        }
    }

    table = newTable;
}

/* Public
---------------------------------------------------------------------------- */
HashTable::HashTable() {
    std::cout << "[DEBUG] "<< "Creating a hash table" << std::endl;
    table->resize(2);
}


HashTable::~HashTable() {
    std::cout << "[DEBUG] " << "Destroying a hash table" << std::endl;
}

void HashTable::add(std::string item) {
    // Check fill factor and resize if needed
    if (isFillFactorExceeded()) {
        resize();
    }
    
    hashHelper(item, table);
    
    filled++;
}
