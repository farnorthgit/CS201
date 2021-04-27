//  gendist.cpp
//  Project - quicksort
//  Created by Mark Billingsley on 4/15/21.
//  functoins to generate the three different types of distributions

#include "gendist.hpp"
#include <vector>
using std::vector;
#include <random>
using std::mt19937;
std::mt19937 seed(1);
using std::uniform_int_distribution;

// generate a normal distribution with stddev 250 and mean 500
void generatenorm(vector<int> &vv, int size) {
    std::normal_distribution<> normal_dist{500, 250};
    for (int n = 0; n < size; n++) {
        vv.push_back(std::round(normal_dist(seed)));
    }
}

// generate a uniform distribution between 0 and 1000
void generateuniform(vector<int> &vv, int size) {
    std::uniform_int_distribution<int> uniform_dist(0, 1000);
    for (int n = 0; n < size; n++) {
        vv.push_back(std::round(uniform_dist(seed)));
    }
}

// generate a rand distribution between 0 and 1000
void generaterand(vector<int> &vv, int size) {
    for (int n = 0; n < size; n++) {
        vv.push_back(std::rand()/((RAND_MAX + 1U)/(999)));
    }
}

