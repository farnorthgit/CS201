//  main.cpp
//  Project - quicksort
//  Created by Mark Billingsley on 4/9/21.
//  Implement quicksort, try it on different vectors
//  Try a different optimization of quicksort and compare times
//  I don't know who came up with the quicksort algorithm (actually it was Hoare), but I'm really impressed.  This is complicated.

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
#include "sortalgorithms.hpp"

// function to check whether my sort was correct
void checkCorrectSort(const vector<int> &v) {
    vector<int> vcheck = v;
    sort(vcheck.begin(), vcheck.end());
    if (!equal(v.begin(), v.end(), vcheck.begin()))
        cout << "Your algorithm DID NOT correctly sort the data!" << endl;
}

int main() {
    vector<int> vv;
    vector<float> vtimes;
    clock_t timer;

// for quicksortlast, sort each type of distribution 8 times and output the average time
    cout << "QUICKSORT STARTING WITH LAST ELEMENT AS THE PIVOT" << endl;
    for (auto i = 0; i <= 5; i++) {
        for (auto j = 0; j <= 7; j++) {
            if (i == 0) generatenorm(vv, 100'000);
            if (i == 1) generateuniform(vv, 100'000);
            if (i == 2) generaterand(vv, 100'000);
            if (i == 3) generatenorm(vv, 1'000'000);
            if (i == 4) generateuniform(vv, 1'000'000);
            if (i == 5) generaterand(vv, 1'000'000);
            timer = clock();
            quickSortLast(vv, 0, vv.size()-1);
            timer = clock() - timer;
            vtimes.push_back((float) timer / CLOCKS_PER_SEC);
            checkCorrectSort(vv);
            vv.clear();
        }
        cout << (accumulate(vtimes.begin(), vtimes.end(), 0.00) / vtimes.size());
        cout << " = average time to sort ";
        if (i == 0) cout << "NORMAL distribution @ 100k elements." << endl;
        if (i == 1) cout << "UNIFORM distribution @ 100k elements." << endl;
        if (i == 2) cout << "RAND distribution @ 100k elements." << endl;
        if (i == 3) cout << "NORMAL distribution @ 1MM elements." << endl;
        if (i == 4) cout << "UNIFORM distribution @ 1MM elements." << endl;
        if (i == 5) cout << "RAND distribution @ 1MM elements." << endl;
        vtimes.clear();
    }

// for quicksortmedian, sort each type of distribution 8 times and output the average time
        cout << endl << "QUICKSORT STARTING WITH MEDIAN OF 3 AS THE PIVOT" << endl;
        for (auto i = 0; i <= 5; i++) {
            for (auto j = 0; j <= 7; j++) {
                if (i == 0) generatenorm(vv, 100'000);
                if (i == 1) generateuniform(vv, 100'000);
                if (i == 2) generaterand(vv, 100'000);
                if (i == 3) generatenorm(vv, 1'000'000);
                if (i == 4) generateuniform(vv, 1'000'000);
                if (i == 5) generaterand(vv, 1'000'000);
                timer = clock();
                quickSortMedian(vv, 0, vv.size());
                timer = clock() - timer;
                vtimes.push_back((float) timer / CLOCKS_PER_SEC);
                checkCorrectSort(vv);
                vv.clear();
            }
            cout << (accumulate(vtimes.begin(), vtimes.end(), 0.00) / vtimes.size());
            cout << " = average time to sort ";
            if (i == 0) cout << "NORMAL distribution @ 100k elements." << endl;
            if (i == 1) cout << "UNIFORM distribution @ 100k elements." << endl;
            if (i == 2) cout << "RAND distribution @ 100k elements." << endl;
            if (i == 3) cout << "NORMAL distribution @ 1MM elements." << endl;
            if (i == 4) cout << "UNIFORM distribution @ 1MM elements." << endl;
            if (i == 5) cout << "RAND distribution @ 1MM elements." << endl;
            vtimes.clear();
        }

// for quicksort starting with pivot selected using Rand function, sort each type of distribution 8 times and output the average time
    cout << endl << "QUICKSORT STARTING WITH RANDOM PIVOT" << endl;
    for (auto i = 0; i <= 5; i++) {
        for (auto j = 0; j <= 7; j++) {
            if (i == 0) generatenorm(vv, 100'000);
            if (i == 1) generateuniform(vv, 100'000);
            if (i == 2) generaterand(vv, 100'000);
            if (i == 3) generatenorm(vv, 1'000'000);
            if (i == 4) generateuniform(vv, 1'000'000);
            if (i == 5) generaterand(vv, 1'000'000);
            timer = clock();
            quickSortRand(vv, 0, vv.size()-1);
            timer = clock() - timer;
            vtimes.push_back((float) timer / CLOCKS_PER_SEC);
            checkCorrectSort(vv);
            vv.clear();
        }
        cout << (accumulate(vtimes.begin(), vtimes.end(), 0.00) / vtimes.size());
        cout << " = average time to sort ";
        if (i == 0) cout << "NORMAL distribution @ 100k elements." << endl;
        if (i == 1) cout << "UNIFORM distribution @ 100k elements." << endl;
        if (i == 2) cout << "RAND distribution @ 100k elements." << endl;
        if (i == 3) cout << "NORMAL distribution @ 1MM elements." << endl;
        if (i == 4) cout << "UNIFORM distribution @ 1MM elements." << endl;
        if (i == 5) cout << "RAND distribution @ 1MM elements." << endl;
        vtimes.clear();
    }
    
    cout << endl;
}

