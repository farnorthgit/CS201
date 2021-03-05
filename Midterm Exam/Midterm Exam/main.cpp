//  main.cpp
//  Midterm Exam
//  Created by Mark Billingsley on 3/3/21.
//  Answers to questions for CS201 spring 2021 mideterm exam.

#include <iostream>
using std::cout;
using std:: endl;
#include <vector>
using std::vector;
#include <string>
using std::string;

// QUESTION 7: takes a vector of floats and returns the sum of all elements in the vector
float sumVector (const vector<float> &floatlist) {
    float sum = 0;
// cycle through floatlist to add them all together in sum and then return sum
    for (auto n : floatlist)
        sum = sum + n;
    return sum;
}

// QUESTION 8: takes a vector of ints and returns true if vector is sorted else false
bool isSorted (const vector<int> &intlist) {
// cycle through vector elements starting at index 1 and comparing to previous
    for (int j = 1; j < intlist.size(); j++) {
        if (intlist[j] < intlist[j-1])
// return false if out of order
            return false;
    }
// ...else return true
    return true;
}

// QUESTION 10: takes a string and prints all substrings in that string
void PrintSubStrings(const string str) {
    int strsize = str.size();
// increment length from 1 to size of string
    for (int length = 1; length <= strsize; length++) {
// set starting point
        for (int start = 0; start <= strsize - length; start++) {
// set end point
            int end = start + length - 1;
// cycle through from start to end to print each char
            for (int i = start; i <= end; i++)
                cout << str[i];
            cout << endl;
        }
    }
}


int main() {
// QUESTION 1
    int i = -32;
    while (i < 1899) {
        cout << i << " ";
        i+=3;
    }
    cout << endl;

// CALL TO FUNCTION FOR QUESTION 7
    vector<float> floatgroup {1.02, 0.02, 4, 100.005};
    cout << sumVector(floatgroup);
    cout << endl;
    
// CALL TO FUNCTION FOR QUESTION 8
    vector<int> intgroup {1, 2, 3, 4, 5};
    if (isSorted(intgroup))
        cout << "true";
    else cout << "false";
    cout << endl;
    
// CALL TO FUNCTION FOR QUESTION 10
    PrintSubStrings("abcd");


    return 0;
}
