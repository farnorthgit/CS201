// Mark Billingsley
// CS201, spring 2021
// PPM2PGM program, Homework 7
// Program that reads a PPM image and outputs a PGM version of that image.


#include <iostream>
using std::cout;
using std::endl;
using std::string;
#include <fstream>
using std::ifstream;
using std::ofstream;
#include <vector>
using std::vector;

int main()
{
// FIRST DEAL WITH OPENING FILES
// create and open a PGM file
    ofstream fout("parrot2pgm.pgm");
    
// open the PPM file and print error if unable to open
    string infile = "parrot.ppm";
    ifstream fin(infile);
    if (!fin) {
        fout << "Error opening " << infile << endl;
        exit(1);
    }

// THEN DEAL WITH MAGIC NUMBERS
// read the PPM file's magic number and print error if it isn't P3
    string line;
    getline(fin, line);
    if (!fin || line.size() < 2 || line.at(0) != 'P' || line.at(1) != '3') {
        fout << "Error reading magic number." << endl;
        exit (2);
    }

// output P2 as first line of the PGM file
    fout << "P2" << endl;

// THEN PROCESS THE COMMENT IN THE PARROT FILE
// process the comment
    getline(fin, line);
    if (line[0] != '#') {
        fout << "Error: comment expected here" << endl;
        exit (2);
    }

    // fout my own comments to the file
    fout << "# This file was created by conversion from PPM." << endl;
    fout << "# (c) 2021 Mark Billingsley.  All rights reserved.  :)" << endl;

// THE TAKE THE XRES YRES AND MAXVAL FROM PPM FILE AND USE THEM FOR PGM FILE
// read in xres, yres, and maxval
    int xres, yres, maxval;
    fin >> xres >> yres >> maxval;
    if (!fin) {
        fout << "Error reading stream" << endl;
        exit(3);
    }
    fout << xres << " " << yres << endl;
    fout << maxval << endl;

// loop for xres * yres iterations
    int r, g, b, iy;
    double y;
    struct rgbval {int rpix; int gpix; int bpix;};
    vector<rgbval> image;
    
    for ( int i=0 ; i<xres*yres ; i++ ) {
        fin >> r >> g >> b;
        if (!fin) {
            fout << "Error reading stream" << endl;
            if (fin.eof())
                fout << "Error: Reached end of file before reaching anticipated resolution" << endl;
            exit(4);
        }
        if (r < 0 || r > maxval || g < 0 || g > maxval || b < 0 || b > maxval) {
            fout << "Improper RGB value." << endl;
            exit(5);
        }
// save to vector
        image.push_back({r, g, b});
    }

// CYCLE THRU IMAGE VECTOR, CONVERT TO PGM, OUTPUT TO FILE
    int counter = 0;
    for (auto n : image) {
// Y = 0.2126R + 0.7152G + 0.0722B (from HW7)
        y = 0.2126*n.rpix + 0.7152*n.gpix + 0.0722*n.bpix;
        if (y < 0.0 || y >= 256.0) fout << "ERROR!!!!!!!!!!!" << endl;
        iy = (int) y;
// iy should be [0...255]
        if (iy < 0 || iy > 255) fout << "ERROR!!!!!!!!!!!!!!" << endl;
        iy /= 16;
// iy should be [0...15]
        if (iy < 0 || iy > 15) fout << "ERROR!!!!!!!!!!!!!!" << endl;
        fout << iy << " ";
        if (counter % xres == (xres-1)) fout << endl;
        counter++;
    }
}
