//  main.cpp
//  L09
//  Created by Mark Billingsley on 2/5/21.
//  Program calls modifyString function external file by the same name 3 times -- adding an extra number each time.

#include<iostream>
#include<string>
#include "modifyString.hpp"
using std::cout;
using std::endl;
using std::string;

int main () {
    string stringInMain = "Hello";
    cout << "length: " << modifyString(stringInMain, 0) << endl;
    cout << "stringInMain: " << stringInMain << endl;
    cout << "length: " << modifyString(stringInMain, 1) << endl;
    cout << "stringInMain: " << stringInMain << endl;
    cout << "length: " << modifyString(stringInMain, 2) << endl;
    cout << "stringInMain: " << stringInMain << endl;
}
