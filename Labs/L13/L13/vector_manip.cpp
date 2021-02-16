//  main.cpp
//  L13
//  Created by Mark Billingsley on 2/15/21.
//  Creates function to change first letter in each item in array to ch.

#include<iostream>
using std::cout;
#include<vector>
#include<string>
#include "vector_manip.hpp"

void firstLetterChange(std::vector<std::string> & strVec, const char & c) {
    for (auto i : strVec){
        for (int j=0; j<=i.size(); j++) {
            if (j == 0) cout << "x";
                else cout << i[j];
        }
        cout << " ";
    }
}

void addUserStrings(std::vector<std::string> & strVec, const std::string sentinel) {
    std::string input;
    while (true) {
        std::cin >> input;
        if (input == sentinel)
            break;
        strVec.push_back(input);
    }
}
