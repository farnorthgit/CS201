//  main.cpp
//  HW4 - tokenizer
//  Created by Mark Billingsley on 2/24/21.
//

#include <iostream>
using std::cout;
using std::endl;
#include <string>
using std::string;
#include <vector>
using std::vector;
#include "tokenizer.hpp"

int main() {
// repeat this until hit break, which occurs when user enter "end"
    while (true) {
// this section has the initial prompt and then the call to readline to gather input
        string str;
        cout << "Please type in some text. When you are done, type \" End\", \"end\", or \"END\":" << endl;
        if (ReadLine(str)) {
            cout << "function returned positive" << endl;
            cout << str << endl;
        }
            else cout << "function returned negative";
// this section calls stringtotokens to place each element of str into vector tokens
        vector<string> tokens;
        cout << StringToTokensWS(str, tokens) << endl;
        for (auto n : tokens) {
            cout << n << endl;
        }
        int test = tokens.size();
        if (tokens.at(test-1) == "End" ||
            tokens.at(test-1) == "end" ||
            tokens.at(test-1) == "END")
            break;
    }
    return 0;
}
