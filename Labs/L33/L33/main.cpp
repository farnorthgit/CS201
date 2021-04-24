//  main.cpp
//  L33
//  Created by Mark Billingsley on 4/17/21.
//  program containing a class definition
//      The class has a public member function that prints something
//  program creates an object of the class and call the member function on it
//  the class has at least two data members of different types
//  ...and matching "setter" and "getter" public member functions
//      The setter member function takes a parameter to set the value of the data member
//      The getter member function return the data member
//          Create a "toString" function to print your objects.


//  (1) Create two objects of the class.
//  (2) Use the first member function to set the data members in these two objects to different values.
//  (3) Use the second member function to print the data members in these two objects, demonstrating that two different values are stored.

#include <iostream>
using std::string;
using std::cout;
using std::to_string;
using std::endl;

class Gods {
public:
    void setName(string name) {_name = name;}
    string getName() const {return _name;}
    void setAge(int age) {_age = age;}
    int getAge() const {return _age;}
    string toString() const {return "{ " + getName() + ", " + to_string(getAge()) + " }";}
private:
    string _name;
    int _age;
};

int main() {
    Gods christianity;
    Gods islamism;
    christianity.setName("Jesus");
    christianity.setAge(2000);
    islamism.setName("Muhammad");
    islamism.setAge(1400);
    cout << christianity.toString() << endl;
    cout << islamism.toString() << endl;
    return 0;
}
