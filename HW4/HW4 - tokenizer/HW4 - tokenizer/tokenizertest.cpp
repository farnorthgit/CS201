//  main.cpp
//  HW4 - tokenizer
//  Created by Mark Billingsley on 2/24/21.
//  Create a tokenizer program to read in lines of text, convert to vector of tokens of type string,
//    and then analyze and print token types

#include <iostream>
using std::cout;
using std::endl;
#include <string>
using std::string;
#include <vector>
using std::vector;
#include "tokenizer.hpp"

int main() {
    string str;
    vector<string> tokens;
    cout << "Please type in some text. When you are done, type \" End\", \"end\", or \"END\":" << endl;
// repeatedly collect lines of text until hit break, which occurs when user enters end or End or END
    while (true) {
// call readline to gather input
        ReadLine(str);
// then call stringtotokens function to place each element of str into vector tokens
        int test = (StringToTokensWS(str, tokens)) - 1;
        if ((tokens.at(test) == "End") ||
            (tokens.at(test) == "end") ||
            (tokens.at(test) == "END"))
            break;
    }
// after done collecting lines of text and converting to tokens, analyze all the tokens
    AnalyzeTokens (tokens);
    return 0;
}
