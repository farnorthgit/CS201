//  main.cpp
//  L04
//  Created by Mark Billingsley on 1/26/21.
//  print numbers up to 100, but buzz if %5 = 0 and fizz if %3 = 0

#include <iostream>
using std::cout;
using std::endl;

int main() {
    // divisible is bool variable to capture whether to print number after doing mod checks
    bool divisible;
    // for loop for all numbers up to 100
    for (int i = 1; i < 101; i++) {
        // reset divisible to false at start of each loop
        divisible = false;
        // if divisible by 3 then print fizz and divisible = true
        if (i%3 == 0) {
            cout << "fizz ";
            divisible = true;}
        // if divisible by 5 then print buzz and divisible = true
        if (i%5 == 0) {
            cout << "buzz";
            divisible = true;}
        // if divisible then go to next line, else print the number and go to next line
        if (divisible == true) cout << endl;
            else cout << i << endl;
    }
    return 0;
}
