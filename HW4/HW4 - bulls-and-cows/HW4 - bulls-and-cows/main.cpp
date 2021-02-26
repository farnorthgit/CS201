//  main.cpp
//  HW4 - bulls-and-cows
//  Created by Mark Billingsley on 2/25/21.
//  User's task is to discover the numbers by repeated guesses.  Negative input causes program to output the solution.

#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <vector>
using std::vector;
#include <string>
using std::getline;

// take input and return true if input includes a negative number;
bool takeinput (vector<char> &guess) {
    cout << "Guess 4 positive integers (0-9), or enter a negative number to exit: ";
    for (int i = 0; i<=3; i++) {
        cin >> guess[i];
        if (guess[i] == '-')
            return true;
    }
    return false;
}

int main() {
// solution vector of four different integers 0 to 9
    vector<char> solution {'1', '2', '3', '4'};
    vector<char> guess (4);
    if (takeinput(guess)) {
        cout << "You entered a negative number. The solution is: ";
        for (auto n : solution)
           cout << n;
        cout << endl;
//        break;
    }
    
    return 0;
}
