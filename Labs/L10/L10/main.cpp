//  main.cpp
//  L10
//  Created by Mark Billingsley on 2/8/21.
//  This main program sends an integer to a separate file that contains a functions which returns true if int % 3 = 0 else returns false.  This program does this for all numbers in the loop counter and prints the number if the return is true.

#include <iostream>
#include "isDiv3.hpp"
using std::cout;
using std::endl;

int main() {
    for (int i=1; i<40; i++) {
        if (isDiv3(i))
            cout << i << endl;
    }
    return 0;
}
