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
        cout << "Enter name (NoName to exit): ";
        cin >> name;
        cout << "Enter score (0 to exit): ";
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
void SearchNamePrintScore (const vector<string>&names, const vector<int>&scores) {
    bool nameexists = false;
    string nametofind;
    cout << "Enter a name to find: ";
    cin >> nametofind;
    for (int k=0; k<names.size(); k++) {
        if (nametofind == names.at(k)) {
            cout << "Corresponding score is: " << scores.at(k) << endl;
            nameexists = true;
            break;
        }
    }
    if (nameexists == false) cout << "name not found" << endl;
}

// function to search for a score and print the corresponding name or "score not found"
void SearchScorePrintName (const vector<string>&names, const vector<int>&scores) {
    bool scoreexists = false;
    int scoretofind;
    cout << "Enter a score to find: ";
    cin >> scoretofind;
    for (int m=0; m<scores.size(); m++) {
        if (scoretofind == scores.at(m)) {
            cout << "Corresponding name is: " << names.at(m) << endl;
            scoreexists = true;
            break;
        }
    }
    if (scoreexists == false) cout << "score not found" << endl;
}

// main program to test the functions and use them to meet homework requirements

    int main() {
        vector<string> names;
        vector<int> scores;
        InputNamesScores(names, scores);
        PrintNamesScores(names, scores);
        int x = 1;
        while (x) {
            cout << "Enter 1 to names/scores, 2 to print all names/scores, 3 to search for a name and print the corresponding score, 4 to search for a score and print the corresponding name, or 5 to quit" << endl;
            cin >> x;
            if (x == 5) break;
            switch (x) {
                case 1: InputNamesScores(names, scores);
                    break;
                case 2: PrintNamesScores(names, scores);
                    break;
                case 3: SearchNamePrintScore(names, scores);
                    break;
                case 4: SearchScorePrintName(names, scores);
                    break;
            }
        }
    return 0;
}
