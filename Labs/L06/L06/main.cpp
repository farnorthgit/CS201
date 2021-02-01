//  main.cpp
//  L06
//  Created by Mark Billingsley on 1/31/21.
//  This program has a function that takes a string parameter. The function prints the string and its length in some neat, understandable manner.  The function is part of a program that calls the function with various strings of different lengths.

#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;
using std::cin;

// This function takes a string parameter. The function prints the string and its length in some neat, understandable manner.
void printstringandlength(string inputstring) {
    cout << "You entered " << inputstring << ", which is length " << inputstring.size() << endl;
}

// This program takes an input string and sends it to function printstringandlength.
int main() {
    string inputstring;
// This loop runs until EXIT is input.
    while (true) {
        cout << "Enter a string, or enter EXIT to quit: ";
        cin >> inputstring;
        if (inputstring == "EXIT")
            break;
        printstringandlength (inputstring);
    }
    return 0;
}
