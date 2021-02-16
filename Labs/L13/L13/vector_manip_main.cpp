/**
 * @file     vector_manip_main.cpp
 * @author   Student Name
 * @version  Jan 21, 2019
 * John Quan 
 *
 * Declare a vector of strings, initialize it using an initializer
 * list (braces-based initialization), and print it—neatly—using
 * a range-based for-loop.
 */

#include <iostream>
#include <vector>
using std::vector;
using std::string;
using std::cout;

#include "vector_manip.hpp"

int main() {

	std::cout << "-------------------Required--------------------------"
    << std::endl;
	//TODO Declare a vector of strings named "words"
    vector<string> words {"I", "am", "the", "eggman.", "I", "am", "the", "eggman.", "I", "am", "the", "walrus!"};
    
	//TODO REQUIRED Print original words with a range-based for loop.
	//     Access each string by-reference and make it constant.
    for (auto i : words)
        cout << i << " ";
    
	std::cout << std::endl;
	std::cout << "-------------------Additional 1----------------------"
			<< std::endl;

	//TODO ADDITIONAL 1 Create this function in vector_manip.cpp
	char ch = 'x';
	firstLetterChange(words, ch);

	//TODO print strings that had their first letter changed in vector
    
    
	std::cout << std::endl;
	std::cout << "-------------------Additional 2----------------------"
			<< std::endl;

	//TODO ADDITIONAL 2 Create this function in vector_manip.cpp
	std::cout << "Enter strings to add to vector:" << std::endl;
	addUserStrings(words, "done");

	//TODO Print the vector after adding words.
    for (auto k : words)
        cout << k << " ";

	return 0;
}
