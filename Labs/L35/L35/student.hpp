//
//  student.hpp
//  L35
//
//  Created by Mark Billingsley on 4/20/21.
//

#ifndef student_hpp
#define student_hpp

#include <stdio.h>
#include <iostream>
using std::string;
using std::cout;
using std::endl;

class Student {
public:
    Student ();
    Student (string name);
    Student (string name, int id);
    void printInfo () const;
private:
    string _name;
    int _id;
};

#endif /* student_hpp */
