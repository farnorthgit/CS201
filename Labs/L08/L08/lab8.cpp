//
//  lab8.cpp
//  L08
//
//  Created by Mark Billingsley on 2/4/21.
//  Creating the two required functions in this .cpp file.  These functions are called (via header file) by the main program.

#include <stdio.h>
#include "intio.hpp"

// Function doInput calls function getInt (defined in files intio.hpp & intio.cpp) and return its return value.
int doInput() {
    return getInt();
}

// Function compute takes an integer parameter and return its square.
int compute(int n) {
    return n*n;
}

