//
//  main.cpp
//  L05
//
//  Created by Mark Billingsley on 1/27/21.
//

#include <iostream>
using std::cout;
using std::endl;
using std::cin;

int main() {
    cout << "This version uses a switch statement." << endl;
    int x = 1;
    while (x) {
        cout << "Enter 1, 2, or 3; or enter 0 to quit. ";
        cin >> x;
        if (x == 0) break;
        switch (x) {
            case 1: cout << "1 gets gold" << endl;
                break;
            case 2: cout << "2 gets silver" << endl;
                break;
            case 3: cout << "3 gets bronze" << endl;
                break;
        }
    }
    cout << endl << "This version uses if-else-if statements." << endl;
    x = 1;
    while (x) {
        cout << "Enter 1, 2, or 3; or enter 0 to quit. ";
        cin >> x;
        if (x == 0) break;
        if (x == 1) cout << "1 gets gold" << endl;
        else if (x == 2) cout << "2 gets silver" << endl;
        else if (x == 3) cout << "3 gets bronze" << endl;
        }
    cout << endl;
    return 0;
}
