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

// return the number of bulls
int bullcheck (const vector<char> solution, const vector<char> guess) {
    int numbulls = 0;
    for (int i = 0; i<=3; i++) {
        if (solution.at(i) == guess.at(i))
            numbulls++;
    }
    return numbulls;
}

// return the number of cows
int cowcheck (const vector<char> solution, const vector<char> guess) {
    int numcows = 0;
    for (int i = 0; i<=3; i++) {
        for (int j = 0; j<=3; j++) {
            if (i != j) {
                if (solution.at(i) == guess.at(j))
                    numcows++;
            }
        }
    }
    return numcows;
}


int main() {
// solution vector of four different integers 0 to 9.  solution is set to 1234
    vector<char> solution {'1', '2', '3', '4'};
// initialize guess vector of size 4
    vector<char> guess (4);
    int bulls;
    int cows;
// continuous for loop until guess correctly or enter negative number
    while (true) {
// output solution and break if enter negative number
        if (takeinput(guess)) {
            cout << "You entered a negative number. The solution is: ";
            for (auto n : solution)
               cout << n;
            cout << endl;
            break;
        }
// count the bulls; also if four bulls then contragulations and end program
        bulls = bullcheck (solution, guess);
        if (bulls == 4) {
            cout << "Congratulations you guessed correctly!" << endl;
            break;
        }
// count the cows
        cows = cowcheck (solution, guess);
// output the number of bulls and the number of cows
        cout << bulls << " bull(s) and " << cows << " cow(s)" << endl;
    }
    return 0;
}
