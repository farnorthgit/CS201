//  main.cpp
//  L14
//  Created by Mark Billingsley on 2/18/21.
//  Inputs a word from the user and then print it in shrinking form.  Do not use nested loops. Do not modify any internally stored string. Instead, use the substr member function.

#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::string;
#include "functionsL14.hpp"

int main() {
    string word;
    cout << "Enter a word: ";
    cin >> word;
    chopoffend (word);
    chopbothends (word);
    return 0;
}
