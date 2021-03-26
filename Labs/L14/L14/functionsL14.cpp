//
//  functionsL14.cpp
//  L14
//
//  Created by Mark Billingsley on 2/18/21.
//

#include "functionsL14.hpp"
#include <iostream>
#include <string>
using std::cout;
using std::endl;

void chopoffend(std::string word) {
    for (int i = 0; i<word.size(); i++) {
        cout << word.substr(0, (word.size() - i)) << endl;
    }
}

void chopbothends(std::string word) {
    std::string blanks;
    for (int i = 0; i<=((word.size())/2); i++) {
        cout << blanks << word.substr(i, (word.size() - (i*2))) << endl;
        blanks.push_back(' ');
    }
}
