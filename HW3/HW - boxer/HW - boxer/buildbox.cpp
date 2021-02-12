//  buildbox.cpp
//  HW - boxer
//  Created by Mark Billingsley on 2/10/21.
//  Source code file called by main program.  Two functions at top that are called by the buildbox function at the bottom.

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
// print line above and below message that has asterisks on sides but spaces in middle
void linewithspaces (std::string word, int size) {
    for (int k=0; k<size; k++)
        cout << "*";
    for (int m=0; m<(word.size() + 2); m++)
        cout << " ";
    for (int n=0; n<size; n++)
        cout << "*";
    cout << endl;
}

// function called by main program
void buildbox(std::string statement, int boxsize) {
// call function above to print top rows
    ribbon(statement, boxsize);
// call function above to print line above message
    linewithspaces(statement, boxsize);
// print the line with the message
    for (int p=0; p<boxsize; p++)
        cout << "*";
    cout << " " << statement << " ";
    for (int q=0; q<boxsize; q++)
        cout << "*";
    cout << endl;
// call function above to print line below message
        linewithspaces(statement, boxsize);
// call function above to print bottom rows
        ribbon(statement, boxsize);
}
