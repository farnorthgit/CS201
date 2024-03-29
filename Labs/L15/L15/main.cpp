//  main.cpp
//  L15
//  Created by Mark Billingsley on 2/21/21.
//  Write a complete function that takes a string parameter and prints the square of the number contained in the string. If the string did not contain a number, you should print a suitable error message. Test your function by calling it with several interesting strings from main. Paste the following into a string vector: "69", "69a", "a69", "5.6", "    68", "\t11", "68 69", "0xA"
//  ADDITIONAL: Change your program so that your error checking is done in main(). Your function will have to return a boolean indicating whether it worked or not.

#include <iostream>
using std::cout;
using std::endl;
#include <vector>
using std::vector;
#include <string>
using std::string;
#include "squarestring.hpp"

int main() {
    int num = 0;
//initialized per hw instructions
    vector<string> v {"69", "69a", "a69", "5.6", "    68", "\t11", "68 69", "0xA"};
//range-based for loop
    for (auto n : v) {
//call function in source file and send it string n and num to be passed back
//also if return false then tell user the error message
        if (!squarestring(n, num))
            cout << "You did not input an integer." << endl;
//else output the square root
        else cout << num << endl;
    }
    return 0;
}
