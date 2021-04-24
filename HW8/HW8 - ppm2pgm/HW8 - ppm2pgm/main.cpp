//  Mark Billingsley
//  CS201, Spring 2021
//  HW8 - PPM2PGM
//  This program takes a PPM file and converts it to PGM art.  However, it also retains the ability (based on earlier assignment) to also convert to ASCII art.


#include <iostream>
using std::cout;
using std::endl;
using std::string;
#include <fstream>
using std::ifstream;
using std::ofstream;
#include <vector>
using std::vector;

ofstream fout("parrot2ascii.txt");

// establish class RGBImage
class RGBImage {
public:
// default constructor
    RGBImage() : _xres(0), _yres(0), _maxval(0) {
        fout << "Default constructor called: RGBImage variable created w/o passing argument.";
        fout << endl;}
// RGBImage constructor function declaration - defined farther below
    RGBImage(string fname) ;
// toASCII function that converts the RGBImage to ASCII and outputs the results
    void toASCII() ;
// add new file to output a PGM based on the PPM that was read in
    void writePGMFile(string outputfilename) ;
private:
// private data for use only by the public variables / functions
    int _xres, _yres, _maxval;
    vector<int> _image;
};

// body of RGBImage constructor where called with one string as the argument
RGBImage::RGBImage(string infile) {
// open the input file
    ifstream fin(infile);
    if (!fin) {
        fout << "Error opening " << infile << endl;
        exit(1);
    }
    fout << "Opened " << infile << endl;

// read the magic number
    string line;
    getline(fin, line);
    if (!fin || line.size() < 2 || line.at(0) != 'P' || line.at(1) != '3') {
        fout << "Error reading magic number." << endl;
        exit(2);
    }
    fout << "Magic number is P3" << endl;

// quick and dirty - process comment
  getline(fin, line);
  if (!fin) { fout << "Error reading stream" << endl; exit(2); }
  if (line[0] == '#') {
    fout << "Ignoring comment" << endl;
  }

// read in xres, yres, and maxval
    fin >> _xres >> _yres >> _maxval;
    if (!fin) {
        fout << "Error reading stream" << endl;
        exit(2);
    }
    fout << "Image size: " << _xres << " x " << _yres << endl;
    fout << "Maxval = " << _maxval << endl;

// loop for _xres * _yres iterations
    int r, g, b;
    for ( int i=0 ; i<_xres*_yres ; i++ ) {
        fin >> r >> g >> b;
        if (!fin) {
            fout << "Error reading stream" << endl;
            if (fin.eof())
                fout << "Reached end of file" << endl;
            exit(4);
        }
// check r,g,b are between 0 and _maxval
        if (r < 0 || r > _maxval || g < 0 || g > _maxval || b < 0 || b > _maxval) {
            fout << "Improper RGB value." << endl;
            exit(5);
        }
// save to vector - change to Pixel class / Image class
        _image.push_back(r);
        _image.push_back(g);
        _image.push_back(b);
    }
}

// function to convert PPM to ASCII and output the result
void RGBImage::toASCII() {
// open / create output file
    int iy;
    double y;
    string values = "$#TXH*=aexo:-,. ";
    int r, g, b;
    int index = 0;

    for ( int i=0 ; i<_xres*_yres ; i++,index+=3 ) {
        r = _image[index];
        g = _image[index+1];
        b = _image[index+2];
// Y = 0.2126R + 0.7152G + 0.0722B (from HW7)
        y = 0.2126*r + 0.7152*g + 0.0722*b;
        if (y < 0.0 || y >= 256.0) fout << "ERROR!!!!!!!!!!!" << endl;
        iy = (int) y;
// iy should be [0...255]
        if (iy < 0 || iy > 255) fout << "ERROR!!!!!!!!!!!!!!" << endl;
        iy /= 16;
// iy should be [0...15]
        if (iy < 0 || iy > 15) fout << "ERROR!!!!!!!!!!!!!!" << endl;
        fout << values[iy];
// to format ascii output properly
        if (i % _xres == (_xres-1)) fout << endl;
    }
}

void RGBImage::writePGMFile(string outputfilename) {
    ofstream fout(outputfilename);
// CYCLE THRU IMAGE VECTOR, CONVERT TO PGM, OUTPUT TO FILE
    int counter = 0;
    int iy;
    double y;
    int r, g, b;
    int index = 0;
    for ( int i=0 ; i<_xres*_yres ; i++,index+=3 ) {
        r = _image[index];
        g = _image[index+1];
        b = _image[index+2];
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
        if (counter % _xres == (_xres-1)) fout << endl;
        counter++;
    }
}

// main program
int main() {

    RGBImage ppm("parrot.ppm");
    ppm.toASCII();
    ppm.writePGMFile("parrot.pgm");

    fout << "Program finished." << endl;
}

