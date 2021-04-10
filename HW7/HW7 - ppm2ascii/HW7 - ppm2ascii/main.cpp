//  main.cpp
//  HW7 - ppm2ascii
//  Created by Mark Billingsley on 4/9/21.
//

#include <iostream>
using std::cout;
using std::endl;
using std::string;
#include <fstream>
using std::ifstream;


int main() {
// open the file
    string infile = "parrot.ppm";
    ifstream fin(infile);
    if (!fin)
        cout << "Error opening " << infile << endl;
    else
        cout << "Opened " << infile << endl;

// read the magic number
    
    return 0;
}
