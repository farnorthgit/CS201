//  main.cpp
//  HW2 - Scores
//  Created by Mark Billingsley on 2/3/21.
//  This program accepts names and scores into corresponding vectors until NoName 0 is entered.  It terminates with an error if a name is entered twice.  It writes out all the name/score pairs on their own lines.  Then it gives the user the option to (1) add names/scores, (2) print the names/scores, (3) search for a name and print the corresponding score or "name not found," and (4) search for a score and print the corresponding name or "score not found."

#include <iostream>
#include <vector>
#include <string>
using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::endl;

// function to input names and scores, exit when NoName 0 is input, and re-prompt when repeat name is input
void InputNamesScores(vector<string>&names, vector<int>&scores) {
    string name = " ";
    int score = 0;
    bool exists = false;
    while (true) {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter score: ";
        cin >> score;
        if (name == "NoName") {
            if (score == 0)
                break;
        }
        exists = false;
        for (int i=0; i<names.size(); i++) {
            if (name == names.at(i)) {
                cout << "This name has already been entered.  Enter a new name." << endl;
                exists = true;
                break;
            }
        }
        if (exists == false) {
            names.push_back(name);
            scores.push_back(score);
        }
    }
}

// function to print all names and scores
void PrintNamesScores(const vector<string>&names, const vector<int>&scores) {
//    cout << "This is a list of names that were entered: " << endl;
    for (int j=0; j<names.size(); j++) {
        cout << names.at(j) << " " << scores.at(j) << endl;
    }
}
    
// function to search for a name and print the corresponding score or "name not found"

// function to search for a score and print the corresponding name or "score not found"

// main program to test the functions and use them to meet homework requirements

    int main() {
    vector<string> names;
    vector<int> scores;
    InputNamesScores(names, scores);
    PrintNamesScores(names, scores);
    return 0;
}
