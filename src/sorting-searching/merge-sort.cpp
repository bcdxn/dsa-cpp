//
//  merge-sort.cpp
//  data-structures-and-algorithms
//
//  Created by Benjamin Dixon on 4/22/24.
//

#include <cmath>
#include <vector>

#include "merge-sort.hpp"

/*
 Worst: O(N*log(N))
 Average: O(N*log(N))
 Best: O(N*log(N))
 
 recursively split the array into two and merge the sorted sub arrays
 */
std::vector<int> merge(std::vector<int> a, std::vector<int> b) {
    std::vector<int> sorted = std::vector<int>(a.size() + b.size());
    
    int aIndex = 0;
    int bIndex = 0;
    
    for (int i = 0; i < sorted.size(); i++) {
        
        if (aIndex < a.size() && bIndex < b.size()) {
            if (a[aIndex] < b[bIndex]) {
                sorted[i] = a[aIndex];
                aIndex++;
            } else {
                sorted[i] = b[bIndex];
                bIndex++;
            }
        } else if (aIndex < a.size()) {
            sorted[i] = a[aIndex];
            aIndex++;
        } else {
            sorted[i] = b[bIndex];
            bIndex++;
        }
    }
    
    return sorted;
}

std::vector<int> mergeSort(std::vector<int> a) {
    // base case
    if (a.size() < 2) {
        return a;
    }
    
    // recursive call
    std::vector<int> left = std::vector<int>(a.begin(), a.begin() + (a.size() / 2));
    std::vector<int> right = std::vector<int>(a.begin() + (a.size() / 2), a.end());
    
    return merge(mergeSort(left), mergeSort(right));
}



