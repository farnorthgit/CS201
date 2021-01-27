//
//  main.cpp
//  L03
//
//  Created by Mark Billingsley on 1/25/21.
//  Lab 3 assignment - 2 required and 1 additional

#include <iostream>
using std::cout;
using std::endl;

int main() {
// this is the program to print 1 - 20
    int i = 1;
    while (i < 21) {
        cout << i << " ";
        i++;
    }
    cout << endl;

// this is the program to print a 60 x 10 box
    i = 1;
    int j;
    while (i < 11) {
        j = 1;
        while (j < 61) {
            cout << "*";
            j++;
        }
        cout << endl;
        i++;
    }
    cout << endl;
    
// this is the program to print a 60 x 10 box with alternating characters
    i = 1;
    j = 1;
    while (i < 11) {
        j = 1;
        while (j < 61) {
            if (j%2 == 0) cout << "*";
            if (j%2 != 0) cout << "%";
            j++;
        }
        cout << endl;
        i++;
    }
    cout << endl;
    
    return 0;
}
