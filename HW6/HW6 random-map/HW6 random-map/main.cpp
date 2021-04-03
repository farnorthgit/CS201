//  main.cpp
//  HW6 random-map
//  Created by Mark Billingsley on 4/2/21.

#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <random>
#include <cmath>

int main() {
    // Seed with a real random value, if available
    std::random_device r;
 
    // Choose a random mean between 1 and 6
    std::default_random_engine e1(r());
    std::uniform_int_distribution<int> uniform_dist(1, 6);
    int mean = uniform_dist(e1);
    std::cout << "Randomly-chosen mean: " << mean << '\n';
 
    // Generate a normal distribution around that mean
    std::seed_seq seed2{r(), r(), r(), r(), r(), r(), r(), r()};
    std::mt19937 e2(seed2);
    std::normal_distribution<> normal_dist(mean, 2);
 
    std::map<int, int> histnormal;
    for (int n = 0; n < 10000; ++n) {
        ++histnormal[std::round(normal_dist(e2))];
    }
    std::cout << "Normal distribution around " << mean << ":\n";
    for (auto p : histnormal) {
        std::cout << std::fixed << std::setprecision(1) << std::setw(2)
                  << p.first << ' ' << std::string(p.second/200, '*') << '\n';
    }
    std::cout << std::endl;
    
//  Generate a uniform distribution between 1 and 6, and print its histogram
    std::map<int, int> histuniform;
    for (int n = 0; n < 10000; n++) {
        ++histuniform[std::round(uniform_dist(e1))];
    }
    std::cout << "Uniform distribution:\n";
    for (auto p : histuniform) {
        std::cout << std::fixed << std::setprecision(1) << std::setw(2)
                  << p.first << ' ' << std::string(p.second/200, '*') << '\n';
    }

    return 0;
}
