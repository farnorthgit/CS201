//  main.cpp
//  L07
//  Created by Mark Billingsley on 2/3/21.
//  Source file that I wrote that inputs three integers using three calls to getInt. The program then prints the three integers in an aligned column using three calls to  putInt.

#include <iostream>
using std::cout;
using std::endl;
#include "intio.hpp"

int main() {
    cout << "Type an integer: ";
    int x = getInt();
    cout << "Type an integer: ";
    int y = getInt();
    cout << "Type an integer: ";
    int z = getInt();
    putInt(x, 10);
    cout << endl;
    putInt(y, 10);
    cout << endl;
    putInt(z, 10);
    cout << endl;

// Additional program #2: This program keeps inputting numbers (using getInt) until the user types the number zero. It then prints the sum of all the numbers (using putInt)
    cout << "Program #2 (Additional program): input integers; input 0 to quit; the prorgam will output the sum." << endl;
    int sum = 0;
    int userinput = getInt();
    while (userinput != 0) {
        sum = sum + userinput;
        userinput = getInt();
    }
    cout << "The final sum, in right justified format, is:" << endl;
    putInt(sum, 10);
    cout << endl;

// Additional program #3: This program is the same as additional program #2 except that, instead of printing the sum of all the numbers, it prints the smallest number entered other than the zero.
    cout << "Program #3 (Additional program): input integers; input 0 to quit; the program will output the smallest number other than 0." << endl;
    userinput = getInt();
    int lowestinput = userinput;
    while (userinput != 0) {
        if (userinput < lowestinput)
            lowestinput = userinput;
        userinput = getInt();
    }
    cout << "The lowest number input, in right justified format, is:" << endl;
    putInt(lowestinput, 10);
    cout << endl;

    return 0;
}


