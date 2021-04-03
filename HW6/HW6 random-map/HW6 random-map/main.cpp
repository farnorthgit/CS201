//  main.cpp
//  HW6 random-map
//  Created by Mark Billingsley on 4/2/21.

#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <random>
#include <cmath>

// Seed with a real random value, if available
std::random_device r;
std::default_random_engine e1(r());
// all this is needed for normal random number generation
std::uniform_int_distribution<int> uniform_dist_for_mean(1, 6);
int mean = uniform_dist_for_mean(e1);
std::seed_seq seed2{r(), r(), r(), r(), r(), r(), r(), r()};
std::mt19937 e2(seed2);
std::normal_distribution<> normal_dist(mean, 2);
// this is needed for rand number generation


//  int RandomBetweenU(intfirst,intlast) returns a uniform random number between first and last, inclusively (e.g. 1 and 6 returns numbers between 1 and 6).
int RandomBetweenU(int first,int last) {
    std::uniform_int_distribution<int> uniform_dist(first, last);
    return std::round(uniform_dist(e1));
}



//  int RandomBetweenN(intfirst,intlast) which returns a normally distributed random number between first and last, inclusively (e.g. 1 and 6 returns numbers between 1 and 6).
int RandomBetweenN(int first,int last) {
    return std::round(normal_dist(e2));
}

//  int RandomBetween(intfirst,intlast) which returns numbers using the rand() function from the C standard library <stdlib.h>
int RandomBetween(int first,int last) {
    int size = last - first + 1;
    return (first + std::rand()/((RAND_MAX + 1u)/size));
}

//  void PrintDistribution(conststd::map<int,int>&numbers) which prints a list (similar to the sample code above) of the random numbers clearly showing they are normally or uniformly distributed -- or distributed using the rand function
void PrintDistribution(const std::map<int,int>&numbers) {
    for (auto p : numbers) {
        std::cout << std::fixed << std::setprecision(1) << std::setw(2)
                  << p.first << ' ' << std::string(p.second/200, '*') << '\n';
    }
}

int main() {
 
// Generate a normal distribution.  Use the <random> header and std::map<int,int> to simulate a histogram
    std::map<int, int> histnormal;
    for (int n = 0; n < 10000; ++n) {
        ++histnormal[RandomBetweenN(1, 6)];
    }

// Generate a uniform distribution.  Use the <random> header and std::map<int,int> to simulate a histogram
    std::map<int, int> histuniform;
    for (int n = 0; n < 10000; n++) {
        ++histuniform[RandomBetweenU(1, 12)];
    }

// Generate a rand distribution.  Use the <random> header and std::map<int,int> to simulate a histogram
        std::map<int, int> histrand;
        for (int n = 0; n < 10000; n++) {
            ++histrand[RandomBetween(1, 6)];
        }

    
//  Compare all three random number generators and print their histogram
    std::cout << "Randomly-chosen mean: " << mean << '\n';
    std::cout << "Normal distribution around " << mean << ":\n";
    PrintDistribution(histnormal);
    std::cout << std::endl;

    std::cout << "Uniform distribution:\n";
    PrintDistribution(histuniform);
    std::cout << std::endl;

    std::cout << "Rand distribution:\n";
    PrintDistribution(histrand);
    std::cout << std::endl;

    
    return 0;
}
