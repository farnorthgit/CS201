//  main.cpp
//  L28
//  Created by Mark Billingsley on 4/6/21.
//  Write a C++ program that opens a text file, writes the word “ Hello”—or some other message—to it 10 times, each on a separate line, and closes the file.
//  Modify your program from part 1 so that the output sent to the file is a list of the integers 1 to 100, formatted with std::setw in a 10x10 square (see example)
//  Create a function using this prototype -- void printIntegersToFile(const std::vector & integers, std::ofstream& output); -- to print a vector of integers in a 10x10 square, but shuffled in a random order. Use std::shuffle with a PRNG object in main() to do so.

#include <iostream>
using std::cout;
using std::endl;
#include <fstream>
using std::ofstream;
#include <sstream>
using std::setw;

int main() {

// sets us up to output (fout) to file abc.txt
// since abc.txt doesn't already exist, this'll create it
    ofstream fout("abc.txt");
// check for error immediately after attempting to open a file
    if (!fout)
        cout << "error establishing access to file" << endl;

// do the following 100 times
    for (auto j = 1; j <= 100; j++) {
// write j to abc.txt
        fout << setw(4) << j;
// check for error in writing to file
        if (!fout) cout << "error writing to file" << endl;
// if j is divisible by ten then start a new line
        if (j%10 == 0) fout << endl;
    }

    cout << "your program has reached its end" << endl;
    return 0;
}
