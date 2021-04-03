//  main.cpp
//  L27
//  Created by Mark Billingsley on 4/2/21.
//

#include <iostream>
using std::cout;
using std::endl;
#include <random>
using std::random_device;
using std::mt19937;
using std::uniform_int_distribution;
#include <vector>
using std::vector;
#include <algorithm>
using std::shuffle;

//  Write a C++ program that simulates flipping a fair coin 1000 times. (A fair coin comes up either heads or tails, each with equal probability.) The program should print the number of times the coin comes up heads and the number of times it comes up tails.
//  Each time the program runs, different coin flips should result. When you demonstrate your code, run it multiple times, to show that this happens.
//  Your program must generate pseudorandom numbers using an object of class  mt19937.

int main() {
    random_device rd;
//  Modify your program from part 1 so that it always produces the  same coin flips each time it is run.
//  mt19937 gen(rd());
    mt19937 gen(7);
    uniform_int_distribution <int> distrib (0, 1);
    int heads = 0;
    int tails = 0;
    
    for (int i = 0; i < 1000; i++) {
        int randval = distrib(gen);
        if (randval == 0)
            heads++;
        else
            tails++;
    }
    cout << "You flipped heads " << heads << " times." << endl;
    cout << "You flipped tails " << tails << " times." << endl;

//  Write a program that fills a  vector with the numbers 1 to 100, in order, shuffles the numbers randomly, and prints the result
    vector<int> vv;
    for (int i = 1; i < 101; i++) {
        vv.push_back(i);
    }
    shuffle(begin(vv), end(vv), gen);
    for (auto n : vv) {
        cout << n << "  ";
    }
    cout << endl;
    return 0;
}
