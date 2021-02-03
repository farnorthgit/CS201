//  main.cpp
//  HW2 - names
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
using std::endl;

// using the program provided in the homework and making it a function
void Inputnames(vector<string>&names) {
    for (int i=0; i<10; i++) {
        string name;
        cout << "Please enter a name: ";
        getline(cin, name);
        names.push_back(name);
    }
}

// creating a function that returns a bool value to indicate whether a name exists in the list as determined by a search of the list;
bool DoesNameExist(const string &nameToFind, const vector<string> &names) {
    for (int j=0; j<names.size(); j++) {
        if (nameToFind == names.at(j)) {
            return true;
            break;
        }
    }
    return false;
}

// this function takes the list of names and prints them out
void PrintNames(const vector<string>&names) {
    cout << "This is the list of names that were entered." << endl;
    for (int k=0; k<names.size(); k++)
        cout << names.at(k) << endl;
}

// this function prints the number of characters in each string of the vector
void PrintStringLength(const vector<string>&names) {
    string name;
    for (int m=0; m<names.size(); m++) {
        name = names.at(m);
        cout << names.at(m) << " is " << name.length() << " characters long" << endl;
    }
}

// testing whether the Inputnames, DoesNameExist, and PrintNames functions works
int main() {
    vector<string> names;
    Inputnames(names);
    string nameToFind;
    cout << "Please enter name to find: ";
    cin >> nameToFind;
    if (DoesNameExist(nameToFind, names) == true)
        cout << "Yes this name is on the list." << endl;
    else cout << "No this name is not on the list." << endl;
    PrintNames(names);
    PrintStringLength(names);
    return 0;
}
