//  main.cpp
//  FinalExamQ5
//  Created by Mark Billingsley on 4/26/21.
//  C++ program that
//      reads in 3D vectors from “vectors.txt”
//          doubles separated by white space in order x1 y1 z1 x2 y2 z2 x3 y3
//      writes out vector lengths to “lengths.txt” - each vector length on a separate line
//      MyVector class to hold the doubles for x, y, and z
//          The default constructor should initialize the members to 0.0
//          Member function length() which returns sqrt(x*x + y*y + z*z) using std::sqrt()

#include <iostream>
using std::string;
using std::endl;
#include <vector>
using std::vector;
#include <fstream>
using std::ifstream;
using std::ofstream;


// define class
class MyVector {
public:
    MyVector() : _vectors{{0.0, 0.0, 0.0}} {};
    MyVector(string fname);
    void writeVectorLength(string outputfilename);
private:
    struct singlevector {
        double _x;
        double _y;
        double _z;
    };
    vector<singlevector> _vectors;
    double length (singlevector v) {
        return sqrt(v._x * v._x + v._y * v._y + v._z * v._z);}
};

// define member function MyVector that has file name as argument, read vectors from file
MyVector::MyVector(string infile) {
    ifstream fin(infile);
    if (!fin) {
        std::cout << "Error opening " << infile << endl;
        exit(1);
    }

    double x, y, z;
    while (true) {
        fin >> x >> y >> z;
        if (!fin) {
            if (fin.eof()) {
                break;
            }
            std::cout << "Error reading stream from file" << endl;
            exit(4);
        }
        _vectors.push_back({x, y, z});
    }
}

// define member function to output vector length to external file
void MyVector::writeVectorLength(string outputfilename) {
    ofstream fout(outputfilename);
    for (auto n : _vectors) {
        fout << length(n) << endl;
    }
}

int main() {
// test using default constructor
//    MyVector mv1;
//    mv1.writeVectorLength("lengths.txt");

// test using vectors.txt input file
    MyVector mv2 ("vectors.txt");
    mv2.writeVectorLength("lengths.txt");

    return 0;
}
