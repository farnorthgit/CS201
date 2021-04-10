//  main.cpp
//  Project - quicksort
//  Created by Mark Billingsley on 4/9/21.
//  Implement quicksort, try it on different vectors
//  Try a different optimization of quicksort and compare times
//  I don't know who came up with the quicksort algorithm (actually it was Hoare), but I'm really impressed.  This is complicated.  It's complex enough that I can basically onl follow it by stepping a data set through the algorithm with a pencil and paper.

#include <iostream>
using std::cout;
using std::endl;
#include <vector>
using std::vector;


// function to print the vector
void printVector (vector<int> vv) {
    for (auto n : vv)
        cout << n << " ";
    cout << endl;
}

// function to swap values of a and b
void swap (int &a, int &b) {
    int t = a;
    a = b;
    b = t;
}

int partition (vector<int> &vv, int low, int high) {
// SELECT PIVOT AS RIGHTMOST ELEMENT *** CHANGE HERE TO EXPERIMENT W PIVOT OPTIMIZATIONS
    int pivot = vv[high];
// index of first element
    int i = low-1;
// cycle through each element of vestor to compare against pivot
    for (int j = low; j < high; j++) {
        printVector(vv);
// if element [j] is smaller than pivot then shift it one spot to the left
        if (vv[j] <= pivot) {
            i++;
            swap(vv[i], vv[j]);
        }
    }
    swap(vv[i+1], vv[high]);
    return (i+1);
}

void quickSort (vector<int> &vv, int low, int high) {
    if (low < high) {
// find pivot such that leftward is less than and rightward is greater than
        int pi = partition (vv, low, high);
// recursive call for elements left of pivot
        quickSort (vv, low, pi-1);
// recusrive call for elements right of pivot
        quickSort (vv, pi+1, high);
    }
}


int main() {
    vector<int> vv {8, 7, 6, 1, 0, 9, 2};
    cout << "Unsorted vector: ";
    printVector(vv);
    quickSort(vv, 0, vv.size()-1);
    cout << "Sorted vector: ";
    printVector(vv);
    return 0;
}
