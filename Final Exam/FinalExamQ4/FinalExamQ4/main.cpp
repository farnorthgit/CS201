//  main.cpp
//  FinalExamQ4
//  Created by Mark Billingsley on 4/26/21.

#include <iostream>
#include <vector>
#include <random>
#include <algorithm>


int main() {
    std::vector<int> haystack;
    std::random_device rd;
    std::mt19937 g(rd());
    for (int i=1; i<=1'000'000; i++)
        haystack.push_back (g());
    std::shuffle (haystack.begin(), haystack.end(), g);
    int needle = rd();
// find uses a sequential search to check whether needle exists in haystack
    if (find(haystack.begin(), haystack.end(), needle) == haystack.end())
        std::cout << needle << " does not exist in haystack" << std::endl;
    else
        std::cout << needle << " was found!" << std::endl;
    
// "Now we will sort the array and use a faster search"
    std::sort(haystack.begin(), haystack.end());

// search for needle using binary search; this is possible now that array is sorted
    bool found = binary_search(haystack.begin(), haystack.end(), needle);
    if (found == true)
        std::cout << needle << " was found!" << std::endl;
    else
        std::cout << needle << " does not exist in haystack" << std::endl;
        
    
        
    return 0;
}
