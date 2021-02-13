//  main.cpp
//  HW - boxer
//  Created by Mark Billingsley on 2/10/21.
//  Print box of user-specified size around user-specified message.

#include<iostream>
#include<string>
#include"buildbox.hpp"
using std::cin;
using std::cout;
using std::string;

int main() {
    int numlayers = 1;
    string message;
// run continously until triggering the break inside the while loop
    while (true) {
        cout << "Enter box size, or enter 0 to quit: ";
        cin >> numlayers;
// reprompt user to input box size until input is 0 or greater
        while (true) {
            if (numlayers < 0) {
                cout << "You did not enter a positive number, please try again: ";
                cin >> numlayers;
            }
            else break;
        }
// break out of while loop when user inputs box size 0
        if (numlayers == 0) break;
// input message
        cout << "Enter message: ";
        cin >> message;
// call buildbox function and send it the message and box size
        buildbox (message, numlayers);
    }
    return 0;
}
