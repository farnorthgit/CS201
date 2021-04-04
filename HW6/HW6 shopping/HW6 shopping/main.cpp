//  main.cpp
//  HW6 shopping
//  Created by Mark Billingsley on 4/3/21.

#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <map>
using std::map;
#include <string>
using std::string;
#include <vector>
using std::vector;
#include <numeric>
using std::accumulate;

struct Record {double unitprice; int units;};
map<string, Record> shopcart;
map<string, Record> inventory;

void printInventory (const map<string, Record> &localinv) {
    for (const auto &p : localinv) {
        cout << "Item: " << p.first << ", ";
        cout << "Price: $" << p.second.unitprice << "ea, ";
        cout << "Qty: " << p.second.units << endl;
    }
    cout << endl;
}

// function to print cart contents and total cost
void printCartTotal (const map<string, Record> &localcart) {
    printInventory (localcart);
    vector<double> sum;
    for (const auto &p : localcart) {
        sum.push_back(p.second.unitprice * p.second.units);
    }
    double fullsum = accumulate(sum.begin(), sum.end(), 0.00);
    cout << "The total cost of the items in your shopping cart is $" << fullsum << "." << endl << endl;
}

// function to add items to cart
void addToCart (map<string, Record> &localinv, map<string, Record> &localcart) {
//  loop until user chooses to add to cart an item that actually exists
    string itemtoadd;
    while (true) {
        cout << "Which item would you like to add? ";
        cin >> itemtoadd;
        if (localinv.count(itemtoadd) == 1) break;
        cout << "Item does not exist in inventory.  Chose a different item." << endl;
    }
//  loop until user chooses an item quantity that is available
    int qtytoadd;
    while (true) {
        cout << "How much of " << itemtoadd << " would you like to add to cart? ";
        cin >> qtytoadd;
        if (localinv.at(itemtoadd).units >= qtytoadd)
            break;
        cout << "You've requested an amount that exceeds inventory.  Try again." << endl;
    }
//  modify shopping cart and inventory accordingly
    localinv.at(itemtoadd).units = localinv.at(itemtoadd).units - qtytoadd;
    localcart.at(itemtoadd).units = localcart.at(itemtoadd).units + qtytoadd;
    cout << "Done: " << qtytoadd << " " << itemtoadd << " added to your cart." << endl;
}

int main() {
    inventory["dolls"] = {14.99, 10};
    inventory["trains"] = {29.99, 10};
    inventory["balls"] = {7.99, 10};
    inventory["skis"] = {99.99, 10};
    inventory["books"] = {4.99, 10};
    
    shopcart["dolls"] = {14.99, 0};
    shopcart["trains"] = {29.99, 0};
    shopcart["balls"] = {7.99, 0};
    shopcart["skis"] = {99.99, 0};
    shopcart["books"] = {4.99, 0};

    int x;
    while (true) {
        cout << "--------------------------\n" << "CURRENT INVENTORY:" << endl;
        printInventory (inventory);
        cout << "Enter 1 to review cart and total cost,\n\t2 to add to cart,\n\t3 to remove from cart, or\n\t0 to quit\nMake Selection: ";
        cin >> x;
        cout << endl;
        if (x == 0) break;
        switch (x) {
            case 1:
                cout << "SHOPPING CART CONTENTS AND TOTAL COST:" << endl;
                printCartTotal (shopcart);
                break;
            case 2:
                addToCart (inventory, shopcart);
                break;
        }
    }
    
    
    cout << endl;
    return 0;
}
