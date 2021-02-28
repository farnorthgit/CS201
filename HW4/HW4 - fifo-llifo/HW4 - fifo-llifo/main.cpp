//  main.cpp
//  HW4 - fifo-llifo
//  Created by Mark Billingsley on 2/26/21.
//  This program demonsrates FIFO and LIFO

#include <iostream>
using std::cout;
using std::endl;
#include <vector>
using std::vector;
#include <string>
using std::string;

// this function checks whether vector is empty and returns bool accordingly
bool IsContainerEmpty (const vector<string> &container) {
    return container.empty();
}

// this function prints all vector contents
void PrintContainer (const vector<string> &container) {
    cout << "Container now consists of: ";
// range-based for loop cycles through container to print all contents
    for (auto n : container)
        cout << n;
    cout << endl;
}

// this function pushes item onto back of vector
void LifoPush (vector<string> &container, const string &item) {
    container.push_back(item);
}

// this function prints current vector contents, tells you want it's going to pop,
// pops the vector's last item, and then prints current vector contents
void LifoPop (vector<string> &container, string &item) {
    int contsize;
// first confirm container is not empty
    if (!IsContainerEmpty(container)) {
// then print entire container contents
        PrintContainer (container);
        contsize = container.size();
// then tell user what is being popped
        cout << container.at(contsize-1) << " is being popped. " << endl;
// then pop that item
        container.pop_back();
// then tell user what is left in container
        PrintContainer (container);
        cout << "-------" << endl;
    }
// print error if container is empty
    else cout << "Error!" << endl;
}

// this function pushes item onto back of vector
void FifoPush (vector<string> &container, const string &item) {
    container.push_back(item);
}

// this function prints current vector contents, tells you want it's going to pop,
// pops the vector's first item, and then prints current vector's new contents
void FifoPop (vector<string> &container, string &item) {
    int contsize;
// first confirm container is not empty
    if (!IsContainerEmpty(container)) {
// then print entire container contents
        PrintContainer (container);
        contsize = container.size();
// then tell user what is being popped
        cout << container.at(0) << " is being popped. " << endl;
// then pop that item
        container.erase(container.begin() + 0);
// then tell user what is left in container
        PrintContainer (container);
        cout << "-------" << endl;
    }
// print error if container is empty
    else cout << "Error!" << endl;
}

// function to test fifo
bool TestFifo () {
    cout << "This is a test of FIFO." << endl;
    vector<string> container;
    container.clear();
    string item;
// successively push A then B then C then D
    item = "A";
    FifoPush (container, item);
    item = "B";
    FifoPush (container, item);
    item = "C";
    FifoPush (container, item);
    item = "D";
    FifoPush (container, item);
// then pop off 4 items
    FifoPop (container, item);
    FifoPop (container, item);
    FifoPop (container, item);
    FifoPop (container, item);
    return true;
}

// function to test lifo
bool TestLifo () {
    cout << "This is a test of LIFO." << endl;
    vector<string> container;
    container.clear();
    string item;
// successively push A then B then C then D
    item = "A";
    LifoPush (container, item);
    item = "B";
    LifoPush (container, item);
    item = "C";
    LifoPush (container, item);
    item = "D";
    LifoPush (container, item);
// then pop off 4 items
    LifoPop (container, item);
    LifoPop (container, item);
    LifoPop (container, item);
    LifoPop (container, item);
    return true;
}

int main() {
    if (TestFifo()) cout << "Your test of FIFO was successful." << endl << endl;
    else cout << "Your test of FIFO failed." << endl << endl;
    if (TestLifo()) cout << "Your test of LIFO was successful." << endl;
    else cout << "Your test of LIFO failed." << endl;
    
    return 0;
}
