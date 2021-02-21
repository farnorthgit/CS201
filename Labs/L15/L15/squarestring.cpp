//
//  squarestring.cpp
//  L15
//
//  Created by Mark Billingsley on 2/21/21.
//

#include <iostream>
#include "squarestring.hpp"
#include <sstream>
using std::istringstream;
using std::cout;
using std::endl;

bool squarestring (std::string str, int &num) {
    istringstream instream(str);
    instream >> num;
    if (!instream)
        return false;
//    else {
//        cout << num*num << endl;
    num = num * num;
    return true;
//    }
}

