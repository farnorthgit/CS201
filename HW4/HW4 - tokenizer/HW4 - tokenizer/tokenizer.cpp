//
//  tokenizer.cpp
//  HW4 - tokenizer
//
//  Created by Mark Billingsley on 2/24/21.
//

#include <iostream>
using std::cin;
#include <string>
using std::getline;
#include "tokenizer.hpp"

bool ReadLine (std::string &str) {
    getline(cin, str);
    if (str == "")
        return false;
    return true;
}






// unsigned StringToTokensWS (const std::string &input, std::vector <std::string> &tokens);
// void AnalyzeTokens (const std::vector<std::string> &tokens);
