//  main.cpp
//  L21
//  Created by Mark Billingsley on 3/21/21.

#include <iostream>
#include <string>
#include "truncstruct.hpp"

int main() {
//  Input a  string from the user, pass it to function trunc8 which is declared and defined in the provided truncstruct files, and print the results.
    std::string userinput;
    StringInfo fnoutput;
    std::cout << "LAB21 STEP 1" << std::endl << "Please enter a string: ";
    std::cin >> userinput;
    fnoutput = trunc8(userinput);
    std::cout << fnoutput.str << fnoutput.len << std::endl;

//  inputs a  string  and an  int from the user, passes both to function  trunc, and prints the results
    size_t size;
    std::cout << std::endl << "LAB21 STEP 2" << std::endl << "Please enter a string: ";
    std::cin >> userinput;
    std::cout << "Please enter a length: ";
    std::cin >> size;
    fnoutput = trunc(StringInfo {userinput, size});
    std::cout << fnoutput.str << fnoutput.len << std::endl << std::endl;
    return 0;


}
