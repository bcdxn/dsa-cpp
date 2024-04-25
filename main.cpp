//
//  main.cpp
//  Data Structures and Algorithms
//

#include <iostream>
#include <vector>

#include <harnesses/linked-list.h>
#include <harnesses/dlinked-list.h>
#include <harnesses/queue.h>
#include <harnesses/stack.h>
#include <harnesses/bst.h>
#include <harnesses/avl-tree.h>
#include <harnesses/hash-table.h>
#include <harnesses/min-heap.h>
#include "sorting-searching/bubble-sort.hpp"
#include "sorting-searching/insertion-sort.hpp"
#include "sorting-searching/merge-sort.hpp"
#include "sorting-searching/quick-sort.hpp"

int main() {
//    runLinkedListHarness();
//    runDLinkedListHarness();
//    runQueueHarness();
//    runStackHarness();
//    runBstHarness();
//    runAVLTreeHarness();
//    runHashTableHarness();
//    runMinHeapHarness();
    
    std::vector<int> arry = {8, 4, 5, 9, 10, 100, 50, 43, 12};
    
//    std::vector<int> sorted = bubbleSort(arry);
//    std::vector<int> sorted = insertionSort(arry);
//    std::vector<int> sorted = mergeSort(arry);
    std::vector<int> sorted = quickSort(arry);
    
    
    std::cout << "[ ";
    for (int i = 0; i < sorted.size(); i++) {
        std::cout << sorted[i] << " ";
    }
    std::cout << "]" << std::endl;
    
    return 0;
}


