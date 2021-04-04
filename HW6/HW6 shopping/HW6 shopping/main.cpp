//  main.cpp
//  HW6 shopping
//  Created by Mark Billingsley on 4/3/21.

#include <iostream>
using std::cout;
using std::endl;
#include <map>
using std::map;
#include <string>
using std::string;

struct Record {double unitprice; int units;};
map<string, Record> shopcart;
map<string, Record> inventory;

void printInventory (const map<string, Record> &localinv) {
    for (const auto &p : localinv) {
        cout << "Item: " << p.first << ", ";
        cout << "Price: $" << p.second.unitprice << "ea, ";
        cout << "Qty avail: " << p.second.units << endl;
    }
    cout << endl;
}

void printCartTotal (const map<string, Record> &localcart) {
    printInventory (localcart);
    double sum = 0;
    for (const auto &p : localcart) {
        sum = sum + (p.second.unitprice * p.second.units);
    }
    cout << "The total cost of the items in your shopping cart is $" << sum << "." << endl;
}

int main() {
    inventory["dolls"] = {14.99, 10};
    inventory["trains"] = {29.99, 10};
    inventory["balls"] = {7.99, 10};
    inventory["skis"] = {99.99, 10};
    inventory["books"] = {4.99, 10};
    
    shopcart["dolls"] = {0, 0};
    shopcart["trains"] = {0, 0};
    shopcart["balls"] = {0, 0};
    shopcart["skis"] = {0, 0};
    shopcart["books"] = {0, 0};

    printInventory (inventory);

    printCartTotal (shopcart);
    
    return 0;
}
