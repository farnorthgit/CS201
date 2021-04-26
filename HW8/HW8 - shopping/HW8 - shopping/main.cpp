//  main.cpp
//  HW8 shopping
//  Created by Mark Billingsley on 4/25/21.
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
// HW8: added this so I could include setprecision
#include <iomanip>
#include <sstream>
// HW8: input inventory from file, and output receipt
#include <fstream>
using std::ifstream;
using std::ofstream;

// setup structure
struct Record {double unitprice; int units;};

// function to print entire inventory with prices
void printInventory (const map<string, Record> &localinv) {
    for (const auto &p : localinv) {
// HW8: setprecision and fixed and setw - to line up words and numbers and 2 decimal points
        cout << "Item: ";
        cout << std::setw(6) << p.first;
        cout << ", Price: $";
        cout << std::setw(5) << std::fixed << std::setprecision(2) << p.second.unitprice;
        cout << "ea, Qty: ";
        cout << p.second.units << endl;
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
        getline (cin, itemtoadd);
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
    bool nonemptycart = false;
// HW8: avoid endless loop if choose to remove but nothing in cart to remove
    for (const auto &n : localcart) {
        if (n.second.units != 0) {
            nonemptycart = true;
            break;
        }
    }
//  loop until user chooses to remove from cart an item that actually exists in qty>0
    string itemtoremove;
    while (nonemptycart) {
        cout << "Which item would you like to remove? ";
        getline (cin, itemtoremove);
        if (localcart.count(itemtoremove) != 1)
            cout << "Item does not exist in shopping cart.  Chose a different item." << endl;
        else if (localcart.at(itemtoremove).units == 0)
            cout << "You don't have any " << itemtoremove << " in your cart." << endl;
            else break;
    }
//  loop until user chooses an item quantity that is available
    int qtytoremove;
    while (nonemptycart) {
        cout << "How many " << itemtoremove << " would you like to remove from cart? ";
        cin >> qtytoremove;
        if (localcart.at(itemtoremove).units >= qtytoremove)
            break;
        cout << "You've don't have that many " << itemtoremove << " in cart.  Try again." << endl;
    }
//  modify shopping cart and inventory accordingly
    while (nonemptycart) {
    localinv.at(itemtoremove).units = localinv.at(itemtoremove).units + qtytoremove;
    localcart.at(itemtoremove).units = localcart.at(itemtoremove).units - qtytoremove;
    cout << "Done: " << qtytoremove << " " << itemtoremove << " removed from your cart." << endl;
        break;
    }
    if (nonemptycart == false)
        cout << "Unable to remove an item because your cart is empty." << endl;
}

int main() {
    map<string, Record> shopcart;
    map<string, Record> inventory;

// HW8 input name of file that contains inventory, open it, and load it into this program
    string invfile;
// HW8 input name of file
    cout << "Input name of file that contains inventory: ";
    getline (cin, invfile);
// HW8 open file or produce error
    ifstream fin(invfile);
    if (!fin) {
        cout << "Error opening " << invfile << endl;
        exit(1);
    }
    cout << "Opened " << invfile << endl;
// HW8 input from file the inventory along with unit price and number of units
    string itemname;
    double up;
    int uu;
    while (true) {
        fin >> itemname >> up >> uu;
        if (!fin) {
            if (fin.eof()) {
                cout << "Reached end of file" << endl;
                break;
            }
            cout << "Error reading stream" << endl;
            exit(4);
        }
        inventory[itemname] = {up, uu};
        shopcart[itemname] = {up, 0};
    }

// while loop and switch to let user shop (add/remove/view cart) for as long as they'd like
    string userinput;
    int x;
    while (true) {
        cout << "--------------------------\n" << "CURRENT INVENTORY:" << endl;
        printInventory (inventory);
        cout << "Enter 0, 1, 2, or 3 to select the corresponding option:\n\t1 to review cart and total cost,\n\t2 to add to cart,\n\t3 to remove from cart, or\n\t0 to quit\nMake Selection: ";
        std::getline (cin, userinput);
        cout << endl;
// HW8: error checking for non-numeral
        if ((userinput != "0")
                && (userinput != "1")
                && (userinput != "2")
                && (userinput != "3"))
            x = 100;
        else x = stoi(userinput);
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
            default:
                cout << "That's not an option, try again." << endl;
                break;
        }
    }
    
    cout << endl;
// open or create "receipt" file and print receipt to it
    ofstream fout("receipt.txt");
    for (const auto &p : shopcart) {
        fout << "Item: ";
        fout << std::setw(6) << p.first;
        fout << ", Price: $";
        fout << std::setw(5) << std::fixed << std::setprecision(2) << p.second.unitprice;
        fout << "ea, Qty: ";
        fout << p.second.units << endl;
    }
    fout << endl;
    vector<double> sum;
    for (const auto &p : shopcart) {sum.push_back(p.second.unitprice * p.second.units);}
    double fullsum = accumulate(sum.begin(), sum.end(), 0.00);
    fout << "The total cost of the items in your shopping cart is $" << fullsum << "." << endl << endl;

    return 0;
}
