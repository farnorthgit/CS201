//  tokenizer.cpp
//  HW4 - tokenizer
//  Created by Mark Billingsley on 2/24/21.
//  Source code file containing readline, stringtotoken, and analyzetoken functions.

#include "tokenizer.hpp"
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <string>
using std::string;
using std::getline;
#include <sstream>
using std::istringstream;
#include <vector>
using std::vector;

// this function gets and entire line from keyboard, saves it in str, returns false if line is empty else true
bool ReadLine (string &str) {
    getline(cin, str);
    if (str == "")
        return false;
    return true;
}

// this function takes the input line, breaks it into strings divided by whitespaces,
// saves each into a vector token element, and adds a blank space at end if last word isnt "end"
// finally this function returns the current size of the token vector
unsigned StringToTokensWS (const string &input, vector <string> &tokens) {
// convert input into istringstream instream
    istringstream instream(input);
    string nextstring;
// sequentially read strings from instream into nextstring, and push nextstring onto tokens
    while (instream >> nextstring) {
        tokens.push_back(nextstring);
    }
// add blank space if last token is not End end END
    if (nextstring != "End" &&
        nextstring != "end" &&
        nextstring !=  "END") {
        tokens.push_back("");
    }
// return token size
    return tokens.size();
}

// this function analyzes each token, prints out its type, and prints the token itself in quotation marks
void AnalyzeTokens (const std::vector<std::string> &tokens) {
// set up enum state to track token type
    enum state {none, integer, identifier, string, whitespace, other};
    state s;
    int stringsize;
// range-based for loop lets me cycle thru each element of the vector
    for (auto n : tokens) {
        s = none;
// check whether token is whitespace
        if (n.empty())
            s = whitespace;
// check whether token is a string and if so modify token to print per homework requirement
        stringsize = n.size();
        if ((n[0] == '"') && (n[stringsize-1] == '"') && (s == none)) {
            s = string;
            n = n.substr(0,(stringsize-1));
            n = "\\" + n + "\\\"";
        }
// check whether token is an identifier
        if (((isalpha(n[0])) || (n[0] == '_')) && (s == none)) {
            bool identifiercheck = true;
            for (int i = 1; i<stringsize; i++) {
                if ((!isalpha(n[i])) && (!isdigit(n[i])) && (n[i] != '_'))
                    identifiercheck = false;
            }
            if (identifiercheck)
                s = identifier;
        }
// check whether token is an integer
        if ((isdigit(n[0])) && (s == none)) {
            bool digitcheck = true;
            for (int i = 1; i<stringsize; i++) {
                if (!isdigit(n[i]))
                    digitcheck = false;
            }
            if (digitcheck)
                s = integer;
        }
// assign type "other" if token doesnt fit any of the above types
        if (s == none)
            s = other;
// print type and token
        switch (s) {
            case integer:
                cout << "[integer] \t\t \"" << n << "\"" << endl;
                break;
            case identifier:
                cout << "[identifier] \t \"" << n << "\"" << endl;
                break;
            case string:
                cout << "[string] \t\t \"" << n << "\"" << endl;
                break;
            case whitespace:
                cout << "[whitespace] \t \"" << n << "\"" << endl;
                break;
            case other:
                cout << "[other] \t\t \"" << n << "\"" << endl;
                break;
        }
    }
}
