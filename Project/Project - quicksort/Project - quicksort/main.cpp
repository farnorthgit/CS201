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
#include <cmath>
#include <numeric>
using std::accumulate;
#include <iomanip>
#include <stdio.h>
#include <time.h>
#include "gendist.hpp"

int count;

// function to check whether my sort was correct
void checkCorrectSort(const vector<int> v) {
    vector<int> vcheck = v;
    sort(vcheck.begin(), vcheck.end());
    if (equal(v.begin(), v.end(), vcheck.begin()))
        cout << "Your algorithm correctly sorted the data" << endl;
    else
        cout << "Your algorithm DID NOT correctly sort the data!" << endl;
}

// function to swap values of a and b
void swap(int &a, int &b) {
    int t = a;
    a = b;
    b = t;
}

int partitionMedian(vector<int> &vv, int low, int high) {
    int x = vv[low];
    int y = vv[(high-low)/2+low];
    int z = vv[high-1];
    int i = low-1;
    int j = high;
    if (y>x && y<z || y>z && y<x ) x=y;
    else if (z>x && z<y || z>y && z<x ) x=z;
    while (1) {
        do {j--;count++;}
        while (vv[j] > x);
        do {i++;count++;}
        while (vv[i] < x);
        if (i < j)
            swap(vv[i],vv[j]);
        else
            return j+1;
    }
}

void quickSortMedian(vector<int> &vv, int low, int high) {
    count++;
    if (high-low < 2) return;
    int pi = partitionMedian(vv, low, high);
    quickSortMedian(vv, low, pi);
    quickSortMedian(vv, pi, high);
}

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

void sortAndCheck(vector<int> testvv) {
}

int main() {
    vector<int> vv;
    for (auto i = 0; i < 6; i++) {
        vector<float> vtimes;
        for (auto j = 0; j < 10; j++) {
            if (i == 0) generatenorm(vv, 100'000);
            if (i == 1) generateuniform(vv, 100'000);
            if (i == 2) generaterand(vv, 100'000);
            if (i == 3) generatenorm(vv, 1'000'000);
            if (i == 4) generateuniform(vv, 1'000'000);
            if (i == 5) generaterand(vv, 1'000'000);
            vverify = vv;
            clock_t timer = clock();
            quickSortLast(vv, 0, vv.size()-1);
            timer = clock() - timer;
            vtimes.push_back((float) timer / CLOCKS_PER_SEC);
            checkCorrectSort(vv);
        }
        cout << (accumulate(vtimes.begin(), vtimes.end(), 0) / vtimes.size());
        cout << " is average time to run quicksortlast on a ";
        if (i == 0) cout << " small normal distribution." << endl;
        if (i == 1) cout << " small uniform distribution." << endl;
        if (i == 2) cout << " small rand distribution." << endl;
        if (i == 3) cout << " large normal distribution." << endl;
        if (i == 4) cout << " large uniform distribution." << endl;
        if (i == 5) cout << " large rand distribution." << endl;
        }

    }



// sort and check each distribution
    cout << "Sort and check a NORMAL distribution:" << endl;
//    sortAndCheck(vnormlarge);
    cout << "Sort and check a UNIFORM distribution:" << endl;
    sortAndCheck(vuniformlarge);
    cout << "Sort and check a RAND distribution:" << endl;
    sortAndCheck(vrandlarge);

    cout << endl << "now checking median of 3 sort" << endl;
    quickSortMedian(vnorm, 0, vnorm.size());
    checkCorrectSort(vnorm);

    return 0;
}
