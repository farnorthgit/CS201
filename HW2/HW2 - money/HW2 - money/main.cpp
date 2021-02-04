//  main.cpp
//  HW2 - money
//  Created by Mark Billingsley on 2/3/21.
//  This program prompts the user to enter some number of each US coin.  Then it outputs what was entered as well as the total number both in terms of cents and dollars.

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main() {
    double pen = 0, nic = 0, dim = 0, qua = 0, dol = 0;
// first take in all the input
    cout << "How many pennies do you have? ";
    cin >> pen;
    cout << "How many nickels do you have? ";
    cin >> nic;
    cout << "How many dimes do you have? ";
    cin >> dim;
    cout << "How many quarters do you have? ";
    cin >> qua;
    cout << "How many dollar coins do you have? ";
    cin >> dol;
// then output what was input
    cout << "You have " << pen;
    if (pen == 1)
        cout << " penny." << endl;
    else cout << " pennies." << endl;

    cout << "You have " << nic;
    if (nic == 1)
        cout << " nickel." << endl;
    else cout << " nickels." << endl;

    cout << "You have " << dim;
    if (dim == 1)
        cout << " dime." << endl;
    else cout << " dimes." << endl;

    cout << "You have " << qua;
    if (qua == 1)
        cout << " quarter." << endl;
    else cout << " quarters." << endl;

    cout << "You have " << dol;
    if (dol == 1)
        cout << " dollar coin." << endl;
    else cout << " dollar coins." << endl;

// then output the total amount in cents and that same number in dollars
    double totalcents = pen + (nic*5) + (dim*10) + (qua*25) + (dol*100);
    cout << "The value of your coins is " << totalcents << " cents." << endl;
    double totaldollars = totalcents/100;
    cout << "The value of your coins is $" << totaldollars << endl;
    return 0;
}
