//  main.cpp
//  HW3 - collatz
//  Created by Mark Billingsley on 2/11/21.
//  Print collatz function for any positive integer.

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main() {
    int x;
// run continously until triggering the break inside the while loop
    while (true) {
        cout << "Input a positive integer, or enter 0 to quit: ";
        cin >> x;
// reprompt user to input number until input is 0 or greater
        while (true) {
            if (x < 0) {
                cout << "You did not enter a valid option." << endl;
                cout << "Input a positive integer, or enter 0 to quit: ";
                cin >> x;
            }
            else break;
        }
// break out of while loop when user inputs box size 0
        if (x == 0) break;
// output the current number in the collatz sequence and calculate the next number
        while (x>1) {
            cout << x << " ";
            if (x%2 == 0)
                x = x/2;
            else x = 3 * x + 1;
        }
// output the final integer, ie 1, in the collatz function
        cout << "1" << endl;
    }
            return 0;
}
