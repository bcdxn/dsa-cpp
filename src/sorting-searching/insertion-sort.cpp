//
//  insertion-sort.cpp
//  data-structures-and-algorithms
//

#include <vector>
#include <utility>

#include "insertion-sort.hpp"

/*
 Best: O(N) - when the array is already sorted
 Average: O(N^2)
 Worst: O(N^2)
 
 adaptive - works well when the data is sorted or nearly sorted
 in place - O(1) additional memory required
 online alogrithm - sorting occurs as data is received (streamed)

 1. Iterate over each item comparing to its neighbor
 2. If they are out of order, swap the out of order element
    in reverse to find its place in the sorted array
 */
std::vector<int> insertionSort(std::vector<int> a) {
    for (int i = 0; i < a.size() - 1; i++) {
        if (a[i] > a[i + 1]) {
            std::swap(a[i], a[i + 1]);
            // iterate back through the array that has been sorted
            // so far and find the correct insertion point
            for (int j = i; j > 0; j--) {
                if (a[j] < a[j - 1]) {
                    std::swap(a[j - 1], a[j]);
                } else {
                    // we've found the final insertion point
                    break;
                }
            }
            
        }
    }
    
    return a;
}
