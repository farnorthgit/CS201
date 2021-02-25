//  main.cpp
//  HW4 - tokenizer
//  Created by Mark Billingsley on 2/24/21.
//

#include <iostream>
using std::cout;
using std::endl;
#include <string>
using std::string;
#include "tokenizer.hpp"

int main() {
    string str;
    cout << "Please type in some text. When you are done, type \" End\", \"end\", or \"END\":" << endl;
    if (ReadLine(str)) {
        cout << "function returned positive" << endl;
        cout << str << endl;
    }
        else cout << "function returned negative";
    return 0;
}
