//  squarestring.cpp
//  L15
//  Created by Mark Billingsley on 2/21/21.
//  Source file containing squarestring function.

#include <iostream>
using std::cout;
using std::endl;
#include <sstream>
using std::istringstream;
#include "squarestring.hpp"

//function that returns a boolean value, receives a string and passed int num by reference
bool squarestring (std::string str, int &num) {
    istringstream instream(str);
    instream >> num;
//returns false if string did not contain an integer
    if (!instream)
        return false;
//else returns a square of the integer
    num = num * num;
    return true;
}

