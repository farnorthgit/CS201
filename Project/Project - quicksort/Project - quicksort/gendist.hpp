//
//  gendist.hpp
//  Project - quicksort
//
//  Created by Mark Billingsley on 4/15/21.
//

#ifndef gendist_hpp
#define gendist_hpp

#include <stdio.h>
#include <vector>
using std::vector;

void generatenorm(vector<int> &vv, int size);
void generateuniform(vector<int> &vv, int size);
void generaterand(vector<int> &vv, int size);

#endif /* gendist_hpp */
