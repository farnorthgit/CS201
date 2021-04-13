// Mark Billingsley
// CS201, spring 2021
// ASCIIART / PPM2ASCII program, Homework 7
// Program that reads a PPM image and outputs a PGM version of that image.


#include <iostream>
using std::cout;
using std::endl;
using std::string;
#include <fstream>
using std::ifstream;
using std::ofstream;

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
  if (line[0]=='P' && line[1] =='3') {
//    fout << "Magic number is P3." << endl;
  } else {
    fout << "Unable to read magic number (this program only reads P3 files)." << endl;
    exit(2);
  }

// output P2 as first line of the PGM file
  fout << "P2" << endl;

// THEN PROCESS THE COMMENT IN THE PARROT FILE
  // process the comment
  getline(fin, line);
  if (line[0] == '#') {
//    fout << "Ignoring comment" << endl;
  }

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
    
  for ( int i=0 ; i<xres*yres ; i++ ) {
    fin >> r >> g >> b;
    if (!fin) {
      fout << "Error reading stream" << endl;
      exit(4);
    }
    // Y = 0.2126R + 0.7152G + 0.0722B (from HW7)
    y = 0.2126*r + 0.7152*g + 0.0722*b;
    if (y < 0.0 || y >= 256.0) fout << "ERROR!!!!!!!!!!!" << endl;
    iy = (int) y;
    // iy should be [0...255]
    if (iy < 0 || iy > 255) fout << "ERROR!!!!!!!!!!!!!!" << endl;
    iy /= 16;
    // iy should be [0...15]
    if (iy < 0 || iy > 15) fout << "ERROR!!!!!!!!!!!!!!" << endl;
    fout << iy << " ";
    if (i % 80 == 79) fout << endl;
  }

}
