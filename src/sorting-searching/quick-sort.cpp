//
//  quick-sort.cpp
//  data-structures-and-algorithms
//

#include <random>
#include <vector>
#include <utility>

#include "quick-sort.hpp"

int getPivot(int start, int end) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(start, end);
    
    return distr(gen);
}

int partition(std::vector<int>* a, int start, int end) {
    // Get a pivot
    int pivot = getPivot(start, end);
    int pivotValue = a->at(pivot);
    
    // Move the pivot to the end of the array
    if (pivot != end) {
        std::swap(a->at(pivot), a->at(end));
    }
    
    // index i represents the first index in the array where
    // a value is greater than the pivot value
    int i = start;
    
    // Iterate through the array and ensure values less than
    // the pivot are to the left of all values greater than
    // the pivot
    for (int j = start; j < end; j++) {
        if (a->at(j) <= pivotValue) {
            std::swap(a->at(i), a->at(j));
            i++;
        }
    }
    
    // Swap the pivot to the index of the first element
    // larger than the pivot (tracked by i) -- | <p | >p | p | --> | <p | p | >p |
    std::swap(a->at(i), a->at(end));
    
    // Return the final resting index of the pivot allowing
    // us to split the array and quicksort each subarray on
    // either side of the pivot recursively
    return i;
}


void quickSort(std::vector<int>* a, int start, int end) {
    if (start < end) {
        // doing the work
        int pivot = partition(a, start, end);
        
        // recursive case
        quickSort(a, start, pivot - 1); // sort left of pivot
        quickSort(a, pivot + 1, end); // sort right of pivot
    }
    // else { base case - an array of length 1 or less is implicitly sorted }
}

std::vector<int> quickSort(std::vector<int> a) {
    quickSort(&a, 0, (int)a.size() - 1);
    
    return a;
}
