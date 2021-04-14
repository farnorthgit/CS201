//  main.cpp
//  HW7 - caesar cypher
//  Created by Mark Billingsley on 4/13/21.
//  Program that repeatedly inputs a line of text and an integer used as the shift. It should apply the Caesar Cypher with that shift to the text and output the result. There should be some way for the user to end the program and proper error handling should be done.

#include <iostream>
using std::cout;
using std::endl;
using std::cin;
using std::string;

int main() {
// introductory message
    cout << "This program encrypt/decrypt an input string based on an input integer." << endl << endl;
// infinite loop until user enters 0
    while (true) {
// loop until valid input or user enters 0 to quit
        string input;
        do {
            cout << "Input string (or enter the number 0 to quit): ";
            getline (cin, input);
            if (input == "0")
                return 0;
        } while (input == "");
// loop until valid integer is entered
        string shift;
        do {
            cout << "Input a positive integer to use as the shift size: ";
            getline (cin, shift);
// cycle through each element of string to check whether a digit
            bool digitcheck = true;
            for (auto i = 0; i < shift.size(); i++) {
                if (!isdigit(shift[i])) {
                    digitcheck = false;
                    break;
                }
            }
// turn string shift into an int if digitcheck is true
            if (digitcheck)
                
// loop back if not an integer or int is less than 0
        } while ((!digitcheck) || (shift < 0));
// turn shift string into an int
// reduce the shift in case it exceeds 26
        shift = shift % 26;
// cycle through each character in the string
        for (auto n : input) {
// if uppercase, then shift, wrap if > Z, and print
            if (n >= 65 && n <= 90) {
                if ((shift + n) > 90)
                    shift -= 26;
                n += shift;
                cout << n;
            }
// else if lowercase, then shift, wrap if > z, and print
            else if (n >= 97 && n <= 122) {
                if ((shift + n) > 122)
                    shift -= 26;
                n += shift;
                cout << n;
            }
// else just print the char
            else cout << n;
        }
        cout << endl << endl;
    }
}
