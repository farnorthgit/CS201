//  main.cpp
//  L12
//  Created by Mark Billingsley on 2/13/21.
//  cpp source code file containing getUserStrings function that's called by main program

#include <iostream>
#include <string>
#include "userInput.hpp"

void getUserStrings(std::vector<std::string> & words) {
    std::string input;
    while (true) {
        std::cin >> input;
        if (input == "end")
            break;
        words.push_back(input);
    }
}

