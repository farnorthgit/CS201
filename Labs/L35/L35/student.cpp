//
//  student.cpp
//  L35
//
//  Created by Mark Billingsley on 4/20/21.
//

#include "student.hpp"
#include <iostream>
using std::string;
using std::cout;
using std::endl;


Student::Student () : _name {"testcase"}, _id {1111} {}
Student::Student (string name) : _name {name}, _id {9999} {}
Student::Student (string name, int id) : _name{name}, _id{id} {}
void Student::printInfo () const {cout << _name << ", " << _id << endl;}


