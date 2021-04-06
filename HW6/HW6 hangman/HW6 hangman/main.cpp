//
//  main.cpp
//  HW6 hangman
//
//  Created by Mark Billingsley on 4/3/21.
//

#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <map>
using std::map;
#include <string>
using std::string;
#include <vector>
using std::vector;
#include <utility>
using std::pair;
using std::make_pair;
#include <algorithm>
using std::for_each;
using std::find;

// drawHangMan prints the hangman with body depending on # of incorrect guesses
void drawHangMan (int x) {
    cout << "   _____\n";
    cout << "  :     :\n";
    switch (x) {
        case 0:
            cout << "  :\n";
            cout << "  :\n";
            cout << "  :\n";
            cout << "  :\n";
            break;
        case 1:
            cout << "  :     O\n";
            cout << "  :\n";
            cout << "  :\n";
            cout << "  :\n";
            break;
        case 2:
            cout << "  :     O\n";
            cout << "  :     :\n";
            cout << "  :     :\n";
            cout << "  :\n";
            break;
        case 3:
            cout << "  :     O\n";
            cout << "  :    \\:\n";
            cout << "  :     :\n";
            cout << "  :\n";
            break;
        case 4:
            cout << "  :     O\n";
            cout << "  :    \\:/\n";
            cout << "  :     :\n";
            cout << "  :\n";
            break;
        case 5:
            cout << "  :     O\n";
            cout << "  :    \\:/\n";
            cout << "  :     :\n";
            cout << "  :    /\n";
            break;
        case 6:
            cout << "  :     O\n";
            cout << "  :    \\:/\n";
            cout << "  :     :\n";
            cout << "  :    / \\\n";
            break;
        case 7:
            cout << "  :   _ O\n";
            cout << "  :    \\:/\n";
            cout << "  :     :\n";
            cout << "  :    / \\\n";
            break;
        case 8:
            cout << "  :   _ O _\n";
            cout << "  :    \\:/\n";
            cout << "  :     :\n";
            cout << "  :    / \\\n";
            break;
        case 9:
            cout << "  :   _ O _\n";
            cout << "  :    \\:/\n";
            cout << "  :     :\n";
            cout << "  :   _/ \\\n";
            break;
        case 10:
            cout << "  :   _ O _\n";
            cout << "  :    \\:/\n";
            cout << "  :     :\n";
            cout << "  :   _/ \\_\n";
            break;
    }
    cout << "  :\n";
    cout << "__:__" << endl << endl;
}

int main() {
// INITIATE VARIABLES
// guessed holds the letters guessed - regardless of whether right or wrong
    map<string, bool> guessed;
// solution holds the puzzle solution
    string solution = "walrus";
// puzzle starts with underscores that'll get replaced by letters once they're guessed
    string puzzle = "______";
// wrongguesses counts the number of incorrect guesses
    int wrongguesses = 0;
// currentguess holds the user's current guess
    string currentguess;

// PROGRAM BODY
// infinite loop with breaks upon solving of making 10 incorrect guesses
    while (true) {
// start each loop by printing current status of puzzle
        cout << endl << puzzle << endl <<  endl;
// then check if puzzle is complete, ie the user has won
        if (find(puzzle.begin(), puzzle.end(), '_') == puzzle.end()) {
            cout << "You won!" << endl;
            break;
        }
// then print out the current status of the hangman
        drawHangMan(wrongguesses);
// then check if wrongguesses = 10 in which case user has lost
        if (wrongguesses == 10) {
            cout << "You've lost :(" << endl;
            break;
        }
// then collect user's current guess
        cout << "Guess a letter (lower case only): ";
        cin >> currentguess;
        char currentguesschar = currentguess[0]; // also save it as a char for use below
// then check if this letter has already been guessed and if so loop back up
        if (guessed.count(currentguess) != 0)
            cout << "You've already guessed this letter.  Try again." << endl;
// ... and if not then...
        else {
// add letter to list of guesses
            guessed[currentguess] = true;
// initiate counter for if/when need to update puzzle based on guess
            int counter = 0;
// initiate bool to keep track of whether currentguess exists in solution
            bool exists = false;
            for_each (solution.begin(), solution.end(), [&] (auto n) {
                if (currentguesschar == n) {
                    puzzle.replace(counter, 1, currentguess);
                    exists = true;
                }
                counter++;
            });
            if (exists == false) wrongguesses++;
        }
    }
}
