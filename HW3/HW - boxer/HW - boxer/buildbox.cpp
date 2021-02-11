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

void buildbox(std::string statement, int boxsize) {
    for (int i=0; i<boxsize; i++) {
        for (int j=0; j<(statement.size() + 2 + (2*boxsize)); j++)
            cout << "*";
        cout << endl;
    }
    
}
