/*
// Program: Assignment 4.cpp
// Purpose: Loads image from file, applies some filters on it
//          and then saves it in another file.
//
// Authors: Ahmed Nasr Eldardery    (20170034)
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
unsigned char enlarged_image[SIZE][SIZE][RGB];
unsigned char flipped_image[SIZE][SIZE][RGB];


#define RED 0
#define GREEN 1
#define BLUE 2


int get_Num(int, int, int, int);

void filter_flip();
void filter_invert();
void filter_blackwhite();
void filter_detectedge();
void rotate_image();
void enlarge_image();
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
            filter_invert();
            break;
        case '3':
            break;
        case '4':
            filter_flip();
            break;
        case '5':
            break;
        case '6':
            rotate_image();
            break;
        case '7':
            filter_detectedge();
            break;
        case '8':
            enlarge_image();
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

int get_Num(int n1, int n2, int n3, int n4 = 0)
{
    int num;
    while (true)
    {
        cin >> num;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cout << "Invalid input.\n";
        }
        else if (num != n1 && num != n2 && num!=n3 && n4 == 0 )
        {
            cout << "Input out of range (" <<n1<<" - " << n2 << " - " << n3 <<" only)\n";
        }
        else if (num != n1 && num != n2 && num!=n3 && n4 != 0 && num != n4 )
        {
            cout << "Input out of range (1-4 only)\n";
        }
        else
        {
            cin.ignore(INT_MAX, '\n');
            break;
        }
    }
    return num;
}
void rotate_image()
{
    cout << "Enter rotation degree : " ;
    int degree = get_Num(90,180,270,0);
    if (degree == 90)
    {
        for (int i = 0 ; i< SIZE ; ++i)
        {
            for (int j = 0 ; j<SIZE ; ++j)
            {
                flipped_image[j][i][RED] = image[i][j][RED]  ;
                flipped_image[j][i][GREEN] = image[i][j][GREEN] ;
                flipped_image[j][i][BLUE] = image[i][j][BLUE] ;

            }
        }
        for (int i = 0 ; i<SIZE ; ++i)
        {
            for (int j = 0 ; j<SIZE ; ++j)
            {
                image[i][j][RED] = flipped_image[i][j][RED] ;
                image[i][j][GREEN] = flipped_image[i][j][GREEN] ;
                image[i][j][BLUE] = flipped_image[i][j][BLUE] ;
            }

        }
    }
    else if (degree == 180)
    {
        for (int i = 0 ; i< SIZE ; ++i)
        {
            for (int j = 0 ; j<SIZE ; ++j)
            {
                flipped_image[(SIZE-1)-i][(SIZE-1)-j][RED] = image[i][j][RED]  ;
                flipped_image[(SIZE-1)-i][(SIZE-1)-j][GREEN] = image[i][j][GREEN] ;
                flipped_image[(SIZE-1)-i][(SIZE-1)-j][BLUE] = image[i][j][BLUE] ;

            }
        }
        for (int i = 0 ; i<SIZE ; ++i)
        {
            for (int j = 0 ; j<SIZE ; ++j)
            {
                image[i][j][RED] = flipped_image[i][j][RED] ;
                image[i][j][GREEN] = flipped_image[i][j][GREEN] ;
                image[i][j][BLUE] = flipped_image[i][j][BLUE] ;
            }

        }
    }
    else
    {
        for (int i = 0 ; i< SIZE ; ++i)
        {
            for (int j = 0 ; j<SIZE ; ++j)
            {
                flipped_image[j][i][RED] = image[i][j][RED]  ;
                flipped_image[j][i][GREEN] = image[i][j][GREEN] ;
                flipped_image[j][i][BLUE] = image[i][j][BLUE] ;

            }
        }
        for (int i = 0 ; i< SIZE ; ++i)
        {
            for (int j = 0 ; j<SIZE ; ++j)
            {
                image[(SIZE-1)-i][(SIZE-1)-j][RED] = flipped_image[i][j][RED]  ;
                image[(SIZE-1)-i][(SIZE-1)-j][GREEN] = flipped_image[i][j][GREEN] ;
                image[(SIZE-1)-i][(SIZE-1)-j][BLUE] = flipped_image[i][j][BLUE] ;

            }
        }
    }

}

void enlarge_image()
{
    cout << "Enter the number of quarter (1-4) : " ;
    int q = get_Num(1,2,3,4) ;
    int startX, endX,startY,endY, counterX = 0, counterY=0 ;
    char tmpR, tmpG, tmpB ;
    if (q==1)
    {
        startX = startY = 0 ;
        endX = endY = 128 ;
    }
    else if (q == 2)
    {
        startX = 0;
        startY = endX = 128;
        endY = 256 ;
    }
    else if (q == 3)
    {
        startX = endY = 128 ;
        startY = 0 ;
        endX = 256 ;
    }
    else
    {
        startX = startY = 128 ;
        endX = endY = 256 ;
    }
    for (int x = startX ; x<endX ; ++x )
    {
        for (int y = startY ; y<endY ; ++y)
        {
            tmpR = image[x][y][RED] ;
            tmpG = image[x][y][GREEN] ;
            tmpB = image[x][y][BLUE];
            for (int i = counterY ; i<counterY+2 ; ++i)
            {
                for (int j = counterX ; j<counterX+2 ; ++j)
                {
                    enlarged_image[i][j][RED] = tmpR ;
                    enlarged_image[i][j][GREEN] = tmpG ;
                    enlarged_image[i][j][BLUE] = tmpB ;


                }
            }
            counterX+=2;

        }
        counterX = 0 ;
        counterY +=2 ;
    }
    for (int i = 0 ; i<SIZE ; ++i)
    {
        for (int j = 0 ; j<SIZE ; ++j)
        {
            image[i][j][RED] = enlarged_image[i][j][RED] ;
            image[i][j][GREEN] = enlarged_image[i][j][GREEN] ;
            image[i][j][BLUE] = enlarged_image[i][j][BLUE] ;
        }
    }

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

void filter_invert()
{
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            image[i][j][RED] = 255 - image[i][j][RED];
            image[i][j][GREEN] = 255 - image[i][j][GREEN];
            image[i][j][BLUE] = 255 - image[i][j][BLUE];

        }
    }
    cout << "Inverse filter applied successfully!" << endl;
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
    const unsigned char THRESHOLD = 30;
    for (int i = 0; i < SIZE - 1; ++i)
    {
        for (int j = 0; j < SIZE - 1; ++j)
        {
            if (abs(image[i][j][RED] - image[i][j+1][RED] >= THRESHOLD) ||
                    abs(image[i][j][RED] - image[i+1][j][RED] >= THRESHOLD))
                image[i][j][RED] = 255;
            else
                image[i][j][RED] = 0;

            if (abs(image[i][j][GREEN] - image[i][j+1][GREEN] >= THRESHOLD) ||
                    abs(image[i][j][GREEN] - image[i+1][j][GREEN] >= THRESHOLD))
                image[i][j][GREEN] = 255;
            else
                image[i][j][GREEN] = 0;

            if (abs(image[i][j][BLUE] - image[i][j+1][BLUE] >= THRESHOLD) ||
                    abs(image[i][j][BLUE] - image[i+1][j][BLUE] >= THRESHOLD))
                image[i][j][BLUE] = 255;
            else
                image[i][j][BLUE] = 0;
        }
    }
    filter_invert();
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
