//  main.cpp
//  L11
//  Created by Mark Billingsley on 2/11/21.
//  Lab 11 to input a string of characters and output its lowercase letters.

#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <string>
using std::string;

int main() {
    string word;
    cout << "Enter a word: ";
    cin >> word;
    for (int i=0; i<word.size(); i++) {
        if ((word[i]>='a') && (word[i]<='z'))
            cout << word[i];
    }
    cout << endl;
    return 0;
}
