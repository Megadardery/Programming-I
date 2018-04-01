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
#include <algorithm>
#include "bmplib.h"

using namespace std;
unsigned char image[SIZE][SIZE][RGB];

#define RED 0
#define GREEN 1
#define BLUE 2

void filter_flip();
void filter_blackwhite();
void filter_detectedge();
void load_image();
void save_image();

int main()
{
    cout << "Ahlan ya user ya habibi :)\n";

    load_image();
    while (true)
    {
        cout << "Please select a filter to apply or 0 to exit:" << endl <<
             "1- Black & White Filter" << endl <<
             "2- Invert Filter" << endl <<
             "3- Merge Filter" << endl <<
             "4- Flip Image" << endl <<
             "5- Darken and Lighten Image" << endl <<
             "6- Rotate Image" << endl <<
             "7- Detect Image Edges" << endl <<
             "8- Enlarge Image" << endl <<
             "9- Shrink Image" << endl <<
             "s- Save the image to a file" << endl <<
             "l- load a different image from file" << endl <<
             "0- Exit" << endl;
        char response = cin.get();
        cin.ignore(INT_MAX,'\n');
        switch(response)
        {
        case '1':
            filter_blackwhite();
            break;
        case '2':
            break;
        case '3':
            break;
        case '4':
            filter_flip();
            break;
        case '5':
            break;
        case '6':
            break;
        case '7':
            filter_detectedge();
            break;
        case '8':
            break;
        case '9':
            break;
        case 's':
            save_image();
            break;
        case 'l':
            load_image();
            break;
        case '0':
            return 0;

        default:
            cout << "Invalid input.";

        }
    }
    return 0;
}

void filter_blackwhite()
{
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            int val = (image[i][j][RED] + image[i][j][GREEN] + image[i][j][BLUE])/(3.0*255) + 0.5;
            val*=255;
            image[i][j][RED] = val;
            image[i][j][GREEN] = val;
            image[i][j][BLUE] = val;

        }
    }
    cout << "Black White filter applied successfully!" << endl;
}
void filter_flip()
{
    cout << "Flip (h)orizontally or (v)ertically?" << endl;
    char response = cin.get();
    cin.ignore(INT_MAX,'\n');
    if (response == 'v')
    {
        for (int i = 0; i < SIZE / 2; ++i)
        {
            for (int j = 0; j < SIZE; ++j)
            {
                swap(image[i][j][RED], image[SIZE - i][j][RED]);
                swap(image[i][j][GREEN], image[SIZE - i][j][GREEN]);
                swap(image[i][j][BLUE], image[SIZE - i][j][BLUE]);
            }
        }
    }
    else if (response == 'v')
    {
        for (int i = 0; i < SIZE; ++i)
        {
            for (int j = 0; j < SIZE / 2; ++j)
            {
                swap(image[i][j][RED], image[i][SIZE - j][RED]);
                swap(image[i][j][GREEN], image[i][SIZE - j][GREEN]);
                swap(image[i][j][BLUE], image[i][SIZE - j][BLUE]);
            }
        }
    }
    else
    {
        cout << "Invalid response." << endl;
    }
}

void filter_detectedge()
{
    for (int i = 0; i < SIZE - 1; ++i)
    {
        for (int j = 0; j < SIZE - 1; ++j)
        {
            if (abs(image[i][j][RED] - image[i][j+1][RED] >= 70) ||
                abs(image[i][j][RED] - image[i+1][j][RED] >= 70))
                image[i][j][RED] = 255;
            else
                image[i][j][RED] = 0;

            if (abs(image[i][j][GREEN] - image[i][j+1][GREEN] >= 70) ||
                abs(image[i][j][GREEN] - image[i+1][j][GREEN] >= 70))
                image[i][j][GREEN] = 255;
            else
                image[i][j][GREEN] = 0;

             if (abs(image[i][j][BLUE] - image[i][j+1][BLUE] >= 70) ||
                abs(image[i][j][BLUE] - image[i+1][j][BLUE] >= 70))
                image[i][j][BLUE] = 255;
            else
                image[i][j][BLUE] = 0;

            if (image[i][j][RED] == 0 && image[i][j][GREEN] == 0 && image[i][j][BLUE] == 0)
                image[i][j][BLUE] = image[i][j][GREEN] = image[i][j][RED] = 255;
        }
    }
}

void load_image ()
{
    char imageFileName[100];


    cout << "Enter the source image file name (don't include .bmp) ";
    cin.getline(imageFileName,100,'\n');

    // Add to it .bmp extension and load image
    strcat (imageFileName, ".bmp");

    readRGBBMP(imageFileName, image);
}

void save_image ()
{
    char imageFileName[100];

    // Get gray scale image target file name
    cout << "Enter the target image file name (don't include .bmp): ";
    cin.getline(imageFileName,100,'\n');

    // Add to it .bmp extension and load image
    strcat (imageFileName, ".bmp");
    writeRGBBMP(imageFileName, image);
}
