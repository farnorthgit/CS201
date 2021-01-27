//  main.cpp
//  L04
//  Created by Mark Billingsley on 1/26/21.
//  print numbers up to 100, but buzz if %5 = 0 and fizz if %3 = 0

#include <iostream>
using std::cout;
using std::endl;

int main() {
    bool divisible;
    for (int i = 1; i < 101; i++) {
        divisible = false;
        if (i%3 == 0) {
            cout << "fizz ";
            divisible = true;}
        if (i%5 == 0) {
            cout << "buzz";
            divisible = true;}
        if (divisible == true) cout << endl;
            else cout << i << endl;
    }
    return 0;
}
