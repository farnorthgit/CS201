//  main.cpp
//  HW6 shopping
//  Created by Mark Billingsley on 4/3/21.
//  Program to create an inventory and an empty shopping cart.  Let user add and remove items from inventory/to cart.  Calculate total cost of items in shopping cart.

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

// setup structure
struct Record {double unitprice; int units;};

// function to print entire inventory with prices
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
        cout << "How many " << itemtoadd << " would you like to add to cart? ";
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

// function to remove items from cart
void removeFromCart (map<string, Record> &localinv, map<string, Record> &localcart) {
//  loop until user chooses to remove from cart an item that actually exists in qty>0
    string itemtoremove;
    while (true) {
        cout << "Which item would you like to remove? ";
        cin >> itemtoremove;
        if (localcart.count(itemtoremove) != 1)
            cout << "Item does not exist in shopping cart.  Chose a different item." << endl;
        else if (localcart.at(itemtoremove).units == 0)
            cout << "You don't have any " << itemtoremove << " in your cart." << endl;
            else break;
    }
//  loop until user chooses an item quantity that is available
    int qtytoremove;
    while (true) {
        cout << "How many " << itemtoremove << " would you like to remove from cart? ";
        cin >> qtytoremove;
        if (localcart.at(itemtoremove).units >= qtytoremove)
            break;
        cout << "You've don't have that many " << itemtoremove << " in cart.  Try again." << endl;
    }
//  modify shopping cart and inventory accordingly
    localinv.at(itemtoremove).units = localinv.at(itemtoremove).units + qtytoremove;
    localcart.at(itemtoremove).units = localcart.at(itemtoremove).units - qtytoremove;
    cout << "Done: " << qtytoremove << " " << itemtoremove << " removed from your cart." << endl;
}

int main() {
    map<string, Record> shopcart;
    map<string, Record> inventory;

    // initiate variables
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

// while loop and switch to let user shop (add/remove/view cart) for as long as they'd like
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
            case 3:
                removeFromCart (inventory, shopcart);
                break;
        }
    }
    
    
    cout << endl;
    return 0;
}
