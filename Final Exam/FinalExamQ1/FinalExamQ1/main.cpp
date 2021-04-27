//  main.cpp
//  FinalExamQ1
//  Created by Mark Billingsley on 4/26/21.

#include <iostream>
using std::cout;
using std::endl;
#include <map>
using std::map;

void printMap (map<std::string, int> &db) {
    for (const auto &[k, v] : db)
        cout << "Key is " << k << " and value is " << v << endl;
    cout << endl;
}

int main() {
    map<std::string, int> database {
        {"iguana", 7},
        {"lorikeet", 10},
        {"llama", 3}
    };

    cout << "This is what the database looks like to start with:" << endl;
    printMap(database);
// A. Create the record “flamingo” with your favorite integer
    database["flamingo"] = 5;
    cout << "a. Create the record “flamingo” with your favorite integer" << endl;
    printMap(database);
// B. Delete the record “llama” if it exists
    cout << "b. Delete the record “llama” if it exists" << endl;
    if (database.count("llama") != 0)
        database.erase("llama");
    else
        cout << "LLama is not present on list" << endl;
    printMap(database);
// C. Update the record “iguana” with your second favorite integer
    database["iguana"] = 8;
    cout << "c. Update the record “iguana” with your second favorite integer" << endl;
    printMap(database);
// D. Print the record “lorikeet” if it exists
    cout << "d. Print the record “lorikeet” if it exists" << endl;
    if (database.count("lorikeet") != 0)
        cout << database.at("lorikeet") << endl;
    else
        cout << "Not present on list" << endl;
    
    return 0;
}
