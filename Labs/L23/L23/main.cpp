//  main.cpp
//  L23
//  Created by Mark Billingsley on 3/25/21.
//  (1a) Create an empty map. You may choose the types of the keys and associated values.  Add some keys and associated values—at least five key-value pairs—to the dataset stored in the map. (Do not add them to the dataset with the keys in ascending order.)
//  (1b) Use a loop to print out all of the key-value pairs in the map, in some understandable, neat-looking form.
//  (2) Modify your program so that after all the key-value pairs are added, one of the keys is removed from the container before proceeding with the rest of the program.
//  (3) Modify your program so that, instead of printing all the key-value pairs, it inputs a key from the user. If the key is not present in the container, then it tells the user this. If the key is present, then it prints the associated value.

#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <map>
using std::map;
#include <string>
using std::string;

int main() {
    map <string, string> citystate {
        {"Fairbanks", "Alaska"},
        {"Portland", "Oregon"},
        {"Washington", "D.C."},
        {"Palm Beach", "Florida"},
        {"Jackson", "Mississippi"},
        {"Pinedale", "Wyoming"}
    };
    
    cout << "Here is the map BEFORE deletion." << endl;
    for (const auto & [k, v] : citystate) {
        cout << "The key is " << k << " and the value is " << v << endl;
    }
    
    citystate.erase("Pinedale");

    cout << endl << "Here is the map AFTER deletion." << endl;
    for (const auto & [k, v] : citystate) {
        cout << "The key is " << k << " and the value is " << v << endl;
    }
    
    cout << endl << "Enter a key for which you'd like the associated value: ";
    string input;
    cin >> input;
    if (citystate.count(input) != 0)
        cout << "The associated value is \"" << citystate.at(input) << "\"" << endl;
    else
        cout << "\"" << input << "\"" << " is not a key that is included in this map" << endl;

    return 0;
}
