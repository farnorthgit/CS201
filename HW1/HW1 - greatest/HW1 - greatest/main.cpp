//
//  main.cpp
//  HW1 - greatest
//
//  Created by Mark Billingsley on 1/22/21.
/*  This program inputs positive integers from user until the use inputs a number that is negative or zero.  Then program prints the greatest positive integer. */

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main() {
    cout << "Enter a sequence of positive integers, ending with zero." << endl;
    cout << "I will print the greatest positive number entered." << endl;
    // userinput will collect input during each iteration
    int userinput = 0;
    // greatest initially set to 0; during each loop set to greater of current & userinput
    int greatest = 0;
    cout << "Enter a positive integer (0 to end): ";
    // run this loop as long as input is collected that it greater than zero
    while ((cin >> userinput) && (userinput > 0)) {
        // assign greatest the value in userinput if userinput is greater than greatest
        if (greatest < userinput)
            greatest = userinput;
        cout << "Enter a positive integer (0 to end): ";
    }
    cout << endl;
    // Error message if no positive integer entered
    if (greatest == 0)
        cout << "No positive integers entered." << endl;
    // else output greatest number
    else {cout << "The greatest number entered: " << greatest << endl;}
    return 0;
}
