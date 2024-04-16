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

int HashTable::getIndex(std::string item, std::vector<LinkedList<std::string>>* t) {
    // Calculate Hash
    int hash = getHash(item);
    // Calculate index into table
    return hash % t->size();
}

bool HashTable::isFillFactorExceeded() {
    float ff = (float)filled / (float)table->size();
    
    return ff >= 0.5;
}

void HashTable::resize() {
    std::cout << "[DEBUG] " << "Resizing hashtable" << std::endl;
    
    int growthFactor = 2;
    int newSize = (int)table->size() * growthFactor;
    std::vector<LinkedList<std::string>>* newTable = new std::vector<LinkedList<std::string>>();
    newTable->resize(newSize);
    
    // For each item in the old table we must rehash and add to the new table
    for (int i = 0; i < table->size(); i++) {
        auto node = table->at(i).pHead;
        
        while (node) {
            // calculate index in table
            int index = getIndex(node->element, newTable);
            // Add item to the hash table
            newTable->at(index).addHead(node->element);
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
    int index = getIndex(item, table);
    // Add item to the hash table
    table->at(index).addHead(item);
    
    filled++;
}

bool HashTable::contains(std::string item) {
    int index = getIndex(item, table);
    
    return table->at(index).getSize() > 0;
}
