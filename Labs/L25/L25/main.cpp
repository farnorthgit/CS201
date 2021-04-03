//  main.cpp
//  L25
//  Created by Mark Billingsley on 3/26/21.
//  (1) Create two datasets in two vector variables. The two vector variables should be the same size and have the same type, but they may contain different values. (Using initializer lists is the quickest way to do this.)
//  (2) Call mismatch on the two datasets, and get its return value: a pair holding two iterators.
//  (3) Using the return value of mismatch, figure out whether there is any mismatch between the two datasets. If there is a mismatch, then output the mismatched items (one from each dataset) that the algorithm found. If there is no mismatch, then say so
//  ** When you demonstrate your code, show that it correctly handles both datasets with mismatches and those without
//  EXTRA Modify your program from part 1 so that, if there is a mismatch, the code “fixes” it by storing the value from one dataset into the other, and then restarts, calling  mismatch again, etc., until there is no longer any mismatch

#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <vector>
using std::vector;
#include <algorithm>
using std::mismatch;
#include <string>
using std::string;
#include <utility>
using std::pair;
using std::make_pair;

int main() {
//  (1) Create two datasets in two vector variables. The two vector variables should be the same size and have the same type, but they may contain different values. (Using initializer lists is the quickest way to do this.)
    vector<string> v1 {"cat", "dog", "mouse", "horse", "rabbit"};
    vector<string> v2 {"cat", "dog", "turtle", "horse", "rabbit"};
    vector<string> v3 {"cat", "dog", "mouse", "horse", "rabbit"};
    vector<string> v4 {"clown", "dog", "liontamer", "magician", "trapezeartist"};


//  (2) Call mismatch on the two datasets, and get its return value: a pair holding two iterators.
    auto p = mismatch(v1.begin(), v1.end(), v2.begin());

//  (3) Using the return value of mismatch, figure out whether there is any mismatch between the two datasets. If there is a mismatch, then output the mismatched items (one from each dataset) that the algorithm found. If there is no mismatch, then say so
//  ** When you demonstrate your code, show that it correctly handles both datasets with mismatches
    cout << "For v1 and v2: ";
    if (p.first == v1.end())
        cout << "No mismatch." << endl << endl;
    else cout << *p.first << " does not equal " << *p.second << endl << endl;

//  ...and those without
    p = mismatch(v1.begin(), v1.end(), v3.begin());
    cout << "For v1 and v3: ";
    if (p.first == v1.end())
        cout << "No mismatch." << endl << endl;
    else cout << *p.first << " does not equal " << *p.second << endl << endl;

//  EXTRA Modify your program from part 1 so that, if there is a mismatch, the code “fixes” it by storing the value from one dataset into the other, and then restarts, calling  mismatch again, etc., until there is no longer any mismatch
    cout << "Comparing and fixing v4 against v1." << endl;
    while (true) {
        p = mismatch(v1.begin(), v1.end(), v4.begin());
        if (p.first != v1.end()) {
            cout << *p.first << " does not equal " << *p.second << ". ";
            cout << "I will now fix this." << endl;
            *p.second = *p.first;
        }
        else break;
    }
    cout << "v4 is now identical to v1." << endl;

    return 0;
}
