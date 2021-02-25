//
//  tokenizer.cpp
//  HW4 - tokenizer
//
//  Created by Mark Billingsley on 2/24/21.
//

#include "tokenizer.hpp"
#include <iostream>
using std::cin;
#include <string>
using std::string;
using std::getline;
#include <sstream>
using std::istringstream;
#include <vector>
using std::vector;

bool ReadLine (string &str) {
    getline(cin, str);
    if (str == "")
        return false;
    return true;
}

unsigned StringToTokensWS (const string &input, vector <string> &tokens) {
    istringstream instream(input);
    string nextstring;
    while (instream >> nextstring) {
        tokens.push_back(nextstring);
    }
    if (nextstring != "End" &&
        nextstring != "end" &&
        nextstring !=  "END") {
        tokens.push_back("");
    }
    return tokens.size();
}







// void AnalyzeTokens (const std::vector<std::string> &tokens);
