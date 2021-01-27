//
//  main.cpp
//  HW1 - mileskm
//
//  Created by Mark Billingsley on 1/23/21.
//  This program takes user input number of miles and outputs the equivalent number of km.

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main() {
    // define userinput as float type to allow user to enter non-integers
    int userinput = 0;
    // prompt user to input number of miles
    cout << "Enter miles: ";
    // accept number of miles into userinput variable
    cin >> userinput;
    // print the equivalent number of km
    cout << userinput * 1.609 << endl;
    return 0;
}
