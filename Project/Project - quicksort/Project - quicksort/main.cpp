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
#include <iomanip>
#include <random>
using std::mt19937;
std::mt19937 seed(1);
using std::uniform_int_distribution;
#include <stdio.h>
#include <time.h>

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
    clock_t timer = clock();
    quickSortLast(testvv, 0, testvv.size()-1);
    timer = clock() - timer;
    cout << "Sorted in approx " << (float) timer / CLOCKS_PER_SEC << " second." << endl;
    checkCorrectSort(testvv);
    cout << endl;
}

int main() {
// GENERATE THE 6 RANDOM DISTRIBUTIONS OF DIFFERENT TYPES AND SIZES
// generate a small normal distribution with stddev 250 and mean 500
    vector<int> vnormsmall;
    std::normal_distribution<> normal_dist{500, 250};
    for (int n = 0; n < 100'000; n++) {
        vnormsmall.push_back(std::round(normal_dist(seed)));
    }
// generate a small uniform distribution between 0 and 1000
    vector<int> vuniformsmall;
    std::uniform_int_distribution<int> uniform_dist(0, 1000);
    for (int n = 0; n < 100'000; n++) {
        vuniformsmall.push_back(std::round(uniform_dist(seed)));
    }
// generate a small rand distribution between 0 and 1000
    vector<int> vrandsmall;
    for (int n = 0; n < 100'000; n++) {
        vrandsmall.push_back(std::rand()/((RAND_MAX + 1U)/(999)));
    }
// generate a large normal distribution with stddev 250 and mean 500
    vector<int> vnormlarge;
    for (int n = 0; n < 1'000'000; n++) {
        vnormlarge.push_back(std::round(normal_dist(seed)));
    }
// generate a large uniform distribution between 0 and 1000
    vector<int> vuniformlarge;
    for (int n = 0; n < 1'000'000; n++) {
        vuniformlarge.push_back(std::round(uniform_dist(seed)));
    }
// generate a large rand distribution between 0 and 1000
    vector<int> vrandlarge;
    for (int n = 0; n < 1'000'000; n++) {
        vrandlarge.push_back(std::rand()/((RAND_MAX + 1U)/(999)));
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
