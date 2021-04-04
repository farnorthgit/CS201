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
    cout << "__:__\n";
}

void printPuzzle (const map<string, bool> &answer) {
    for (const auto [k, v] : answer)
        if (v == false)
            cout << " _ ";
        else cout << " " << k << " ";
    
}


int main() {
    map<string, bool> guessed;
    map<string, bool> solution;
    solution["w"] = solution["a"] = solution["l"] = solution["r"] = solution["u"] = solution["s"] = false;
    int wrongguesses = 0;
    string currentguess;
    
    drawHangMan(wrongguesses);
    printPuzzle(solution);
    cout << "Guess a letter: ";
    cin >> currentguess;
    if (solution.count(currentguess) != 0) {
        solution[currentguess] = true;
        guessed[currentguess] = true;
    }
    
    
    return 0;
}
