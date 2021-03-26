//  main.cpp
//  L20
//  Created by Mark Billingsley on 3/12/21.
//  Write a program that prints a table of the values of the cosine function, for angles from 0 to 180 degrees, at intervals of 5 degrees (so 0°, 5°, 10°, …, 180°). For each angle x°, the program should print the values of x and cos x° on a single line, separated by one or more blanks. Each cosine value should include exactly eight digits to the right of the decimal point. All decimal points (whether printed or not) should be aligned vertically.  Your program must format the output using appropriate C++ Standard Library stream manipulators. Your loop must use a compound assignment operator.

#include <iostream>
#include <iomanip>

int main() {
    double rad;
    for (int i = 0; i <= 180; i += 5) {
        rad = i * M_PI / 180;
        std::cout << std::setw(3) << i << std::setprecision(8) << std::fixed << std::setw(15) << cos(rad) << std::endl;
    }

    
    return 0;
}
