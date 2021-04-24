// sandwich.cpp
// Glenn G. Chappell
// 16 Apr 2018
//
// For CS 201 Spring 2018
// Sandwich Toppings - Passing Flags in an int

#include <iostream>
using std::cout;
using std::endl;
using std::cin;


void testfunction(unsigned number) {
    if (number == 1)
        cout << " 1";
    else if (number == 3)
        cout << " 3";
    if (number == 5)
        cout << " 5";
    if (number == 15)
        cout << " 15";
    cout << endl;
}


void flag (unsigned a) {
    cout << endl << "New flag" <<  endl;
    if (a & 1) cout << "Your number is odd" << endl;
    if (a | 2) cout << "This could be a function" << endl;
    if ((a & 15) == 15) cout << "This is a rare output" << endl;
}

// Main Program
// Call function "sandwich" to specify sandwiches with various
// combinations of toppings.
int main()
{
    cout << "Test #1" << endl;
    testfunction(1 | 2); // 0011 = 3
    cout << endl;

    cout << "Test #2" << endl;
    testfunction(1 | 1); // 0001 = 1
    cout << endl;

    cout << "Test #3" << endl;
    testfunction(1 | 4); // 0101 = 5
    cout << endl;

    cout << "Test #4" << endl;
    testfunction(1 | 2 | 4 | 8); // 1111 = 15
    cout << endl;

    cout << "Test #4" << endl;
    testfunction(1 | 5); // 0101 = 5
    cout << endl;

    flag(33);
    flag(8796);
    flag(127);
    
    // Wait for user
    cout << "PRESS ENTER to quit ";
    while (cin.get() != '\n') ;
}
