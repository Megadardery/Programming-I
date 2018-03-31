/*
// Program: Assignment 4.cpp
// Purpose: Loads image from file, applies some filters on it
//          and then saves it in another file.
//
// Authors:  Ahmed Nasr Eldardery    (20170034)
//          Adham Mamdouh Mohamed   (20170039)
            Belal Hamdy Ezzat       (20170077)

// Date:    1 April 2018
// Version: 1.0
*/

#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "bmplib.h"

using namespace std;
unsigned char image[SIZE][SIZE][RGB];

void loadImage ();
void saveImage ();

int main()
{
    cout << "Ahlan ya user ya habibi :)\n";

    loadImage();

    while (true)
    {
        cout << "Please select a filter to apply or 0 to exit:" <<
             "1- Black & White Filter" <<
             "2- Invert Filter" <<
             "3- Merge Filter" <<
             "4- Flip Image" <<
             "5- Darken and Lighten Image" <<
             "6- Rotate Image" <<
             "7- Detect Image Edges" <<
             "8- Enlarge Image" <<
             "9- Shrink Image" <<
             "s- Save the image to a file" <<
             "l- load a different image from file" <<
             "0- Exit" << endl;
        char response = cin.get();
        cin.ignore(INT_MAX,'\n');
        switch(response)
        {
        case '1':
            break;
        case '2':
            break;
        case '3':
            break;
        case '4':
            break;
        case '5':
            break;
        case '6':
            break;
        case '7':
            break;
        case '8':
            break;
        case '9':
            break;
        case 's':
            saveImage();
            break;
        case 'l':
            loadImage();
            break;
        case '0':
            return 0;

        default:
            cout << "Invalid input.";

        }
    }
    return 0;
}

void loadImage ()
{
    char imageFileName[100];

    // Get gray scale image file name
    cout << "Enter the source image file name (don't include .bmp) ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    cin.getline(imageFileName,100,'\n');

    readRGBBMP(imageFileName, image);
}

void saveImage ()
{
    char imageFileName[100];

    // Get gray scale image target file name
    cout << "Enter the target image file name (don't include .bmp): ";
    cin.getline(imageFileName,100,'\n');

    // Add to it .bmp extension and load image
    strcat (imageFileName, ".bmp");
    writeRGBBMP(imageFileName, image);
}
