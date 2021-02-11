//
//  buildbox.cpp
//  HW - boxer
//
//  Created by Mark Billingsley on 2/10/21.
//

#include<iostream>
#include"buildbox.hpp"
using std::cout;
using std::endl;

// function called by buildbox function below
// print the top rows full of asterisks
void ribbon (std::string word, int size) {
    for (int i=0; i<size; i++) {
        for (int j=0; j<(word.size() + 2 + (2*size)); j++)
            cout << "*";
        cout << endl;
    }
}

// function called by buildbox function below
// print line above message that has asterisks on sides but spaces in middle
void linewithspaces (std::string word, int size) {
    for (int k=0; k<size; k++)
        cout << "*";
    for (int m=0; m<(word.size() + 2); m++)
        cout << " ";
    for (int k=0; k<size; k++)
        cout << "*";
    cout << endl;
}

// function called by main program
void buildbox(std::string statement, int boxsize) {
    ribbon(statement, boxsize);
    linewithspaces(statement, boxsize);
#if 0
// print the line with the message
    for (int k=0; k<boxsize; k++)
        cout << "*";
    for (int m=0; m<(statement.size() + 2); m++)
        cout << " ";
    for (int k=0; k<boxsize; k++)
        cout << "*";
    cout << endl;
#endif
}
