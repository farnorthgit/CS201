//  sortalgorithms.cpp
//  Project - quicksort
//  Created by Mark Billingsley on 4/15/21.
//  sort algorithm + corresponding partition algorithm for each of
//      quicksort starting with last as pivot
//      quicksort starting with pivot selected using median of 3
//      quicksort starting with pivot selected using Rand function

#include <vector>
using std::vector;
#include "sortalgorithms.hpp"

// function to swap values of a and b
void swap(int &a, int &b) {
    int t = a;
    a = b;
    b = t;
}

// partition function for median of 3 algorithm
int partitionMedian(vector<int> &vv, int low, int high) {
    int x = vv[low];
    int y = vv[(high-low)/2+low];
    int z = vv[high-1];
    int i = low-1;
    int j = high;
// give x the pivot value
    if (y>x && y<z || y>z && y<x) x=y;
    else if (z>x && z<y || z>y && z<x ) x=z;
// find items to swap based on comparison to x
    while (1) {
// cycle down from high as long as value is > x
        do {j--;}
        while (vv[j] > x);
// cycle up from low as long as value is < x
        do {i++;}
        while (vv[i] < x);
// then swap
        if (i < j)
            swap(vv[i],vv[j]);
// and return pivot location
        else
            return j+1;
    }
}

// quicksort algorithm using median of 3
void quickSortMedian(vector<int> &vv, int low, int high) {
// done if...
    if (high-low < 2) return;
// find median of 3 partition
    int pi = partitionMedian(vv, low, high);
// recursively sort the lower half
    quickSortMedian(vv, low, pi);
// recursively sort the upper half
    quickSortMedian(vv, pi, high);
}

// partition function that starts with the last element
int partitionLast (vector<int> &vv, int low, int high) {
// select pivot as rightmost element
    int pivot = vv[high];
    int i = low-1;
// cycle through each element of vector to compare against pivot
    for (int j = low; j < high; j++) {
// if element [j] is smaller than pivot then shift it one spot to the left
        if (vv[j] <= pivot) {
            i++;
            swap(vv[i], vv[j]);
        }
    }
// swap to put pivot (last element) in its correct location
    swap(vv[i+1], vv[high]);
// return location of partitionLast
    return (i+1);
}

// quicksort algorithm based on partitionLast
void quickSortLast (vector<int> &vv, int low, int high) {
    if (low < high) {
// find pivot such that leftward is less than and rightward is greater than
        int pi = partitionLast (vv, low, high);
// recursive call for elements left of pivot
        quickSortLast (vv, low, pi-1);
// recusrive call for elements right of pivot
        quickSortLast (vv, pi+1, high);
    }
}

// set partition as a value selected using the Rand function
int partitionRand (vector<int> &vv, int low, int high) {
    int random = low + rand()%(high-low + 1);
    swap (vv[random] , vv[low]);
    int pivot = vv[low];
    int i = (low + 1);
    for(int j = low + 1; j <= high ; j++) {
        if (vv[j] < pivot) {
            swap (vv[i], vv[j]);
            i += 1;
        }
    }
// put the pivot element in its proper place.
    swap (vv[low], vv[i-1]);
    return i-1;
}

void quickSortRand (vector<int> &vv, int low, int high) {
    if (low < high) {
// partition the array
        int pivot = partitionRand(vv, low, high);
//sort the sub arrays independently
        quickSortRand(vv, low, pivot - 1);
        quickSortRand(vv, pivot + 1, high);
    }
}
