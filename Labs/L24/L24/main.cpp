//  main.cpp
//  L24
//  Created by Mark Billingsley on 3/25/21.
//  (1a) Create an unsorted dataset in a vector. Give the dataset at least 10 items with various values. I suggest using an intializer list.
//  (1b) Print the contents of the vector.
//  (1c) Call all of the following algorithms on the vector as a whole: sort the whole vector, reverse the whole vector, and fill a subset of the vector.
//  (1d) Print the type of sort you used and contents of the vector for each algorithm.
//  (2) Modify your program from part 1 to input starting and ending indices from the user. The function you call to modify the dataset should only modify items within the range described by the two indices.
//  (3) Modify your program so that it calls rotate, instead of whatever function you called before.

#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <vector>
using std::vector;
#include <string>
using std::string;
#include <algorithm>
using std::sort;


int main() {
//  Create an unsorted dataset in a vector. Give the dataset at least 10 items with various values. I suggest using an intializer list.
    vector<string> v {"cat", "dog", "mouse", "fish", "snake", "rabbit", "bird", "ferret", "hamster", "chicken", "turtle", "lizard"};

//  Print the contents of the vector.
    for (const auto & p : v)
        cout << p << " ";
    
//  sort the whole vector; print the algorithm used and the resulting vector contents
    sort (v.begin(), v.end());
    cout << endl << endl << "This is the vector after SORT: " << endl;
    for (const auto & p : v)
        cout << p << " ";

//  reverse the whole vector; print the algorithm used and the resulting vector contents
    reverse (v.begin(), v.end());
    cout << endl << endl << "This is the vector after REVERSE: " << endl;
    for (const auto & p : v)
        cout << p << " ";

// fill a subset of the vector; print the algorithm used and the resulting vector contents
    fill (v.begin()+2, v.end()-2, "died!");
    cout << endl << endl << "This is the vector after FILL with \"died!\" from begin+2 to end-2: " << endl;
    for (const auto & p : v)
        cout << p << " ";
    cout << endl << endl;

//  initialize a new vector
    vector<string> v1 {"cat", "dog", "mouse", "fish", "snake", "rabbit", "bird", "ferret", "hamster", "chicken", "turtle", "lizard"};

//  Print the contents of the vector.
    cout << "Starting over with the same initial vector contents: " << endl;
    for (const auto & p : v1)
        cout << p << " ";
    cout << endl;

// Modify your program from part 1 to input starting and ending indices from the user. The function you call to modify the dataset should only modify items within the range described by the two indices.
    int iterstart;
    int iterend;
    cout << endl << "Enter starting index for FILL: ";
    cin >> iterstart;
    cout << "Enter ending index for FILL: ";
    cin >> iterend;
    fill (v1.begin()+iterstart, v1.begin()+iterend, "died!");
    cout << "This is the vector after FILL from specified begin to end: " << endl;
    for (const auto & p : v1)
        cout << p << " ";
    cout << endl << endl;

// Modify your program so that it calls rotate, instead of whatever function you called before.
    rotate (v1.begin(), v1.begin() + 1, v1.end());
    cout << "This is the vector after ROTATE 1 to the left: " << endl;
    for (const auto & p : v1)
        cout << p << " ";


    return 0;
}
