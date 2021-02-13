#if 0
main.cpp
HW3 - kelvin
Created by Mark Billingsley on 2/12/21.
This program takes celsius input, and then outputs kelvin.
Here is a list of the errors that were corrected:
    Didn't include iostream library
    Hadn't declared use of std::cin and std::cout
    k was set up as type int, but it should've been double
    second line of ctok returned just type int, but it should've returned k
    cin line wasn't preceded with a prompt for user to enter a value
    variable d was undefined, but it should've been c anyhow
    ctok was called in the main program with "c" instead of variable c
    cout incorrectly started with a capital C
    /n should've had a backward slash instead of forward
    main program didn't end by returning any value
#endif

#include<iostream>

// this function takes the celsius temp value and returns a kelvin temp value
double ctok(double c)
{
#if 0
This check returns an error, but it still allows the program to output a negative
kelvin temp.  To perform the check inside the function and not return a negative
kelvin, then the function should be modified to return an extra parameter
such as a boolean that could be checked in main program to determine whether to
print the returned double value.
Output from this check is included with the homework but is commented out here
because there's another check used in the main program.
    if (c<-273.15)
        std::cout << "Error: The following output temperature cannot be reached." << std::endl;
#endif
    double k = c + 273.15;
    return k;
}

int main ()
{
    double c = 0;
    std::cout << "Enter temp in Celsius for me convert to Kelvin: ";
    std::cin >> c;
// This check was added to main program for case in which user input c is invalid
    if (c<-273.15)
        std::cout << "The temp you entered is invalid." << std::endl;
    else {
        double k = ctok(c);
        std::cout << k << '\n';
    }
#if 0
These two lines are only used with the check that's written in ctok function above.
    double k = ctok(c);
    std::cout << k << '\n';
#endif
    return 0;
}
