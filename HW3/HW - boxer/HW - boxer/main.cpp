//  main.cpp
//  HW - boxer
//  Created by Mark Billingsley on 2/10/21.
//

#include <iostream>
#include <string>
#include "buildbox.hpp"
using std::cin;
using std::cout;
using std::string;

int main() {
    int numlayers = 1;
    string message;
    while (true) {
        cout << "Enter box size: ";
        cin >> numlayers;
        while (true) {
            if (numlayers < 0) {
                cout << "You did not enter a positive number, please try again: ";
                cin >> numlayers;
            }
            else break;
        }
        if (numlayers == 0) break;
        cout << "Enter message: ";
        cin >> message;
        buildbox (message, numlayers);
    }
    return 0;
}
