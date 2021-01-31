//
//  main.cpp
//  HW2 - names
//
//  Created by Mark Billingsley on 1/30/21.
//  input names via a function, search the names, prints the names, and performs one other function on the list of names

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using std::vector;
using std::string;
using std::cout;
using std::cin;

// using the program provided in the homework and making it a function
void Inputnames(vector<string>&names) {
    for (int i=0; i<10; i++) {
        string name;
        cout << "Please enter a name: ";
        getline(cin, name);
        names.push_back(name);
    }
}

// testing whether the Inputnames function works
int main() {
    vector<string> names;
    Inputnames(names);
    cout << "Hello, World!\n";
    return 0;
}
