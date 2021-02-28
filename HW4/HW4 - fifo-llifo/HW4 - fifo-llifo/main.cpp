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

bool IsContainerEmpty (const vector<string> &container) {
    return container.empty();
}

void PrintContainer (const vector<string> &container) {
    for (auto n : container)
        cout << n;
}

void FifoPush (vector<string> &container, const string &item) {
    container.push_back(item);
}

void FifoPop (vector<string> &container, string &item) {
    int contsize;
    if (!IsContainerEmpty(container)) {
        contsize = container.size();
        cout << container.at(contsize-1) << " is being popped. ";
        container.pop_back();
        cout << "The remainder of container is : ";
        PrintContainer (container);
        cout << endl;
    }
    else cout << "Error!" << endl;
}

void LifoPush (vector<string> &container, const string &item) {
}

void LifoPop (vector<string> &container, string &item) {
}


bool TestFifo () {
    cout << "This is a test of FIFO." << endl;
    vector<string> container;
    string item;
    item = "A";
    FifoPush (container, item);
    item = "B";
    FifoPush (container, item);
    item = "C";
    FifoPush (container, item);
    item = "D";
    FifoPush (container, item);
    FifoPop (container, item);
    FifoPop (container, item);
    FifoPop (container, item);
    FifoPop (container, item);
    return true;
}

// bool TestLifo () {
// }

int main() {
    if (TestFifo()) cout << "Your test of FIFO was successful." << endl;
    else cout << "Your test of FIFO failed." << endl;
//    if (TestLifo()) cout << "Your test of LIFO was successful.";
//    else cout << "Your test of LIFO failed.";
    
    return 0;
}
