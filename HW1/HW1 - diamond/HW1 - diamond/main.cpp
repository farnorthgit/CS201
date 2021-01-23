//
//  main.cpp
//  HW1 - diamond
//
//  Created by Mark Billingsley on 1/21/21.
//

// including iostream and standard cout cin and endl
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main() {
    int size = 0;
    // first just gather the input to determine diamond size
    cout << "Enter diamond size: ";
    cin >> size;
    // add an empty line to separate input line from diamond
    cout << endl;
    // then deal with situation where input is not a positive integer
    if (size <= 0)
        cout << "You did not enter a positive integer" << endl;
    // in case of actual integer, print the diamond
    else {
        // this loop builds the top half of the diamond including the middle row
        int toploopstotal = size;
        int spaces = size - 1;
        int pounds = size;
        for (int toploopscnt = 1; toploopscnt <= toploopstotal; toploopscnt++) {
            for (int i = 1; i <= spaces; i++)
                cout << " ";
            for (int j = size - 1; j < pounds; j++)
                cout << "#";
            cout << endl;
            // decrease spaces and increase pounds each time through the loop
            spaces = spaces - 1;
            pounds = pounds + 2;
        }

        // this loop build the bottom half of the diamond not including the middle row
        int btmloopstotal = size - 1;
        // must downsize plus take away the increment made at the end of prior for loop
        spaces = spaces + 2;
        pounds = pounds - 4;
        for (int btmloopscnt = 0; btmloopscnt < btmloopstotal; btmloopscnt++) {
            for (int i = 1; i <= spaces; i++)
                cout << " ";
            for (int j = size - 1; j < pounds; j++)
                cout << "#";
            cout << endl;
            // increase spaces and decrease pounds each time through the loop
            spaces = spaces + 1;
            pounds = pounds - 2;

        }
    }
    cout << endl;
    return 0;
}
