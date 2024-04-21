//
//  bubble-sort.cpp
//  data-structures-and-algorithms
//
//  Created by Benjamin Dixon on 4/21/24.
//

#include <vector>
#include <utility>

#include "bubble-sort.hpp"

/*
 Best: O(N) -- the array is already sorted
 Average: O(N^2)
 Worst: O(N^2)
 
 1. Visit each item in the array from start to end
 2. Compare neighboring items and swap if they are out of order
 3. Repeat from beginning of array until the array is sorted
 */
std::vector<int> bubbleSort(std::vector<int> a) {
    
    bool swapped = true;
    
    while (swapped) {
        swapped = false;
        
        for (int i = 0; i < a.size() - 1; i++) {
            if (a[i] > a[i + 1]) {
                std::swap(a[i], a[i + 1]);
                swapped = true;
            }
        }
    }
    
    return a;
}
