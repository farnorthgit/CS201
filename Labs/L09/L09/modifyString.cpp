//  modifyString.cpp
//  L09
//  Created by Mark Billingsley on 2/5/21.
//  cpp file to define function.  Converts int to string and appends it to end of passed string.  Returns size of string.

#include<iostream>
#include<string>
#include"modifyString.hpp"

int modifyString(std::string &referencedString, int n) {
    referencedString = referencedString + std::to_string(n);
    return referencedString.size();
}

