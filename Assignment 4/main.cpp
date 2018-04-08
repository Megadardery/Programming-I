/*
// Program: Assignment 4.cpp
// Purpose: Loads image from file, applies some filters on it
//          and then saves it in another file.
//
// Authors: Ahmed Nasr Eldardery    (20170034)
//          Adham Mamdouh Mohamed   (20170039)
//          Belal Hamdy Ezzat       (20170077)

// Date:    8 April 2018
// Version: 1.0
*/

#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "bmplib.h"

#define SIZE 256
#define RGB 3

using namespace std;

#define RED 0
#define GREEN 1
#define BLUE 2

unsigned char image[SIZE][SIZE][RGB];
bool grayscale = true;

void print_menu();

void copy_array(unsigned char[][SIZE][RGB], unsigned char[][SIZE][RGB]);
void copy_array(unsigned char[][SIZE], unsigned char[][SIZE][RGB]);
void copy_array(unsigned char[][SIZE][RGB], unsigned char[][SIZE]);

void swap(unsigned char[], unsigned char[]);
void swap(unsigned char, unsigned char);


int clamp(int, int, int);
int get_num(int, int, int, int);
float get_ratio();

void filter_blackwhite();
void filter_invert();
void filter_merge();
void filter_flip();
void filter_flip(bool);
void filter_rotate();
void filter_rotate(int);
void filter_darkenlighten();
void filter_darkenlighten(float);
void filter_detectedges();
void filter_enlarge();
void filter_enlarge(int, int);
void filter_shrink();
void filter_shrink(float);

bool load_image(unsigned char[][SIZE][RGB], bool&);
void save_image(unsigned char[][SIZE][RGB], bool);

int main()
{
	cout << "Ahlan ya user ya habibi :)\n";
	while (!load_image(image, grayscale));
	while (true)
	{
		print_menu();

		char response = cin.get();
		cin.ignore(INT_MAX, '\n');
		switch (response)
		{
		case '1':
			filter_blackwhite();
			break;
		case '2':
			filter_invert();
			break;
		case '3':
			filter_merge();
			break;
		case '4':
			filter_flip();
			break;
		case '5':
			filter_rotate();
			break;
		case '6':
			filter_darkenlighten();
			break;
		case '7':
			filter_detectedges();
			break;
		case '8':
			filter_enlarge();
			break;
		case '9':
			filter_shrink();
			break;
		case 's':
			save_image(image, grayscale);
			break;
		case 'l':
			load_image(image, grayscale);
			break;
		case '0':
			return 0;

		default:
			cout << "Invalid input.";

		}
	}
	return 0;
}

void print_menu()
{
	cout << "Please select a filter to apply or 0 to exit:" << endl <<
		"1- Black & White Filter" << endl <<
		"2- Invert Filter" << endl <<
		"3- Merge Filter" << endl <<
		"4- Flip Image" << endl <<
		"5- Rotate Image" << endl <<
		"6- Darken and Lighten Image" << endl <<
		"7- Detect Image Edges" << endl <<
		"8- Enlarge Image" << endl <<
		"9- Shrink Image" << endl <<
		"s- Save the image to a file" << endl <<
		"l- load a different image from file" << endl <<
		"0- Exit" << endl;
}

void copy_array(unsigned char to[][SIZE][RGB], unsigned char from[][SIZE][RGB]) {
	for (int i = 0; i < SIZE; ++i)
		for (int j = 0; j < SIZE; ++j)
			to[i][j][RED] = from[i][j][RED],
			to[i][j][GREEN] = from[i][j][GREEN],
			to[i][j][BLUE] = from[i][j][BLUE];
}
void copy_array(unsigned char to[][SIZE], unsigned char from[][SIZE][RGB]) {
	for (int i = 0; i < SIZE; ++i)
		for (int j = 0; j < SIZE; ++j)
			to[i][j] = from[i][j][0];
}
void copy_array(unsigned char to[][SIZE][RGB], unsigned char from[][SIZE]) {
	for (int i = 0; i < SIZE; ++i)
		for (int j = 0; j < SIZE; ++j)
			to[i][j][RED] = from[i][j],
			to[i][j][GREEN] = from[i][j],
			to[i][j][BLUE] = from[i][j];
}

void swap(unsigned char x[], unsigned char y[]) {
	swap(x[RED], y[RED]);
	swap(x[GREEN], y[GREEN]);
	swap(x[BLUE], y[BLUE]);
}
void swap(unsigned char x, unsigned char y) {
	unsigned char tmp = x;
	y = x;
	x = tmp;
}

int clamp(int val, int min, int max) {
	if (val > max)
		return max;
	else if (val < min)
		return min;
	else
		return val;
}

int get_num(int n1, int n2, int n3, int n4 = 0)
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
		else if (num != n1 && num != n2 && num != n3 && n4 == 0)
		{
			cout << "Input out of range (" << n1 << ", " << n2 << ", or " << n3 << " only)\n";
		}
		else if (num != n1 && num != n2 && num != n3 && n4 != 0 && num != n4)
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
float get_ratio() {
    cout << "Enter ratio: \n";
	float ratio;
	while (true)
	{
		cin >> ratio;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "Invalid input.\n";
		}
		else if (ratio <= 0 || ratio >= 1)
		{
			cout << "Input out of range (0 -> 1)\n";
		}
		else
		{
			cin.ignore(INT_MAX, '\n');
			break;
		}
	}
	return ratio;
}

void filter_blackwhite()
{
	grayscale = true;
	for (int i = 0; i < SIZE; ++i)
	{
		for (int j = 0; j < SIZE; ++j)
		{
			int val = (image[i][j][RED] + image[i][j][GREEN] + image[i][j][BLUE]) / (3.0 * 255) + 0.5;
			val *= 255;
			image[i][j][RED] = image[i][j][GREEN] = image[i][j][BLUE] = val;
		}
	}
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
}

void filter_merge()
{
	unsigned char merge_image[SIZE][SIZE][RGB];
	bool merge_grayscale;
	if (!load_image(merge_image, merge_grayscale)) return;
	for (int i = 0; i < SIZE; ++i) {
		for (int j = 0; j < SIZE; ++j) {
			image[i][j][RED] = ((int)image[i][j][RED] + merge_image[i][j][RED]) / 2;
			image[i][j][BLUE] = ((int)image[i][j][BLUE] + merge_image[i][j][BLUE]) / 2;
			image[i][j][GREEN] = ((int)image[i][j][GREEN] + merge_image[i][j][GREEN]) / 2;
		}
	}
	grayscale = grayscale && merge_grayscale;
}

void filter_flip(bool horizontal) {
	if (horizontal) {
		for (int i = 0; i < SIZE; ++i)
		{
			for (int j = 0; j < SIZE / 2; ++j)
			{
				swap(image[i][j][RED], image[i][(SIZE - 1) - j][RED]);
				swap(image[i][j][GREEN], image[i][(SIZE - 1) - j][GREEN]);
				swap(image[i][j][BLUE], image[i][(SIZE - 1) - j][BLUE]);
			}
		}
	}
	else {
		for (int i = 0; i < SIZE / 2; ++i)
		{
			for (int j = 0; j < SIZE; ++j)
			{
				swap(image[i][j][RED], image[(SIZE - 1) - i][j][RED]);
				swap(image[i][j][GREEN], image[(SIZE - 1) - i][j][GREEN]);
				swap(image[i][j][BLUE], image[(SIZE - 1) - i][j][BLUE]);
			}
		}
	}
}

void filter_flip()
{
	cout << "Flip (h)orizontally or (v)ertically?" << endl;
	char response = cin.get();
	cin.ignore(INT_MAX, '\n');
	if (response == 'h')
		filter_flip(true);
	else if (response == 'v')
		filter_flip(false);
	else {
		cout << "Invalid response." << endl;
	}
}

void filter_rotate()
{
	cout << "Enter rotation degree : ";
	int degree = get_num(90, 180, 270, 0);
	filter_rotate(degree);
}

void filter_rotate(int degree) {
	unsigned char rotatedImage[SIZE][SIZE][RGB];
	if (degree == 90)
	{
		for (int i = 0; i< SIZE; ++i)
		{
			for (int j = 0; j<SIZE; ++j)
			{
				rotatedImage[j][i][RED] = image[i][j][RED];
				rotatedImage[j][i][GREEN] = image[i][j][GREEN];
				rotatedImage[j][i][BLUE] = image[i][j][BLUE];

			}
		}
	}
	else if (degree == 180)
	{
		for (int i = 0; i< SIZE; ++i)
		{
			for (int j = 0; j<SIZE; ++j)
			{
				rotatedImage[(SIZE - 1) - i][(SIZE - 1) - j][RED] = image[i][j][RED];
				rotatedImage[(SIZE - 1) - i][(SIZE - 1) - j][GREEN] = image[i][j][GREEN];
				rotatedImage[(SIZE - 1) - i][(SIZE - 1) - j][BLUE] = image[i][j][BLUE];
			}
		}
	}
	else
	{
		for (int i = 0; i< SIZE; ++i)
		{
			for (int j = 0; j<SIZE; ++j)
			{
				rotatedImage[(SIZE - 1) - j][(SIZE - 1) - i][RED] = image[i][j][RED];
				rotatedImage[(SIZE - 1) - j][(SIZE - 1) - i][GREEN] = image[i][j][GREEN];
				rotatedImage[(SIZE - 1) - j][(SIZE - 1) - i][BLUE] = image[i][j][BLUE];

			}
		}
	}
	copy_array(image, rotatedImage);
}

void filter_darkenlighten() {

	cout << "Do you want to (d)arken or (l)ighten?" << endl;
	char response = cin.get();
	cin.ignore(INT_MAX, '\n');
	float ratio;
	if (response == 'd') {
		ratio = get_ratio();
		filter_darkenlighten(-ratio);
	}
	else if (response == 'l') {
		ratio = get_ratio();
		filter_darkenlighten(ratio);
	}
	else {
		cout << "Invalid response." << endl;
	}
}

void filter_darkenlighten(float ratio) {
	int red_value, blue_value, green_value;
	for (int i = 0; i < SIZE; ++i) {
		for (int j = 0; j < SIZE; ++j) {
			red_value = image[i][j][RED] + int(image[i][j][RED] * ratio);
			blue_value = image[i][j][BLUE] + int(image[i][j][BLUE] * ratio);
			green_value = image[i][j][GREEN] + int(image[i][j][GREEN] * ratio);
			image[i][j][RED] = clamp(red_value, 0, 255);
			image[i][j][BLUE] = clamp(blue_value, 0, 255);
			image[i][j][GREEN] = clamp(green_value, 0, 255);
		}
	}
}

void filter_detectedges()
{
	const unsigned char THRESHOLD = 30;
	for (int i = 0; i < SIZE - 1; ++i)
	{
		for (int j = 0; j < SIZE - 1; ++j)
		{
			if (abs(image[i][j][RED] - image[i][j + 1][RED] >= THRESHOLD) ||
				abs(image[i][j][RED] - image[i + 1][j][RED] >= THRESHOLD))
				image[i][j][RED] = 255;
			else
				image[i][j][RED] = 0;

			if (abs(image[i][j][GREEN] - image[i][j + 1][GREEN] >= THRESHOLD) ||
				abs(image[i][j][GREEN] - image[i + 1][j][GREEN] >= THRESHOLD))
				image[i][j][GREEN] = 255;
			else
				image[i][j][GREEN] = 0;

			if (abs(image[i][j][BLUE] - image[i][j + 1][BLUE] >= THRESHOLD) ||
				abs(image[i][j][BLUE] - image[i + 1][j][BLUE] >= THRESHOLD))
				image[i][j][BLUE] = 255;
			else
				image[i][j][BLUE] = 0;
		}
	}
	filter_invert();
}

void filter_enlarge()
{
	cout << "Enter the number of quarter (1-4) : ";
	int q = get_num(1, 2, 3, 4);

	if (q == 1)
		filter_enlarge(0, 0);
	else if (q == 2)
		filter_enlarge(0, 128);
	else if (q == 3)
		filter_enlarge(128, 0);
	else
		filter_enlarge(128, 128);

}
void filter_enlarge(int startX, int startY) {
	unsigned char enlargedImage[SIZE][SIZE][RGB];

	int endX = startX + 128;
	int endY = startY + 128;

	unsigned char tmpR, tmpG, tmpB;

	int counterX = 0, counterY = 0;

	for (int x = startX; x < endX; ++x)
	{
		for (int y = startY; y < endY; ++y)
		{
			tmpR = image[x][y][RED];
			tmpG = image[x][y][GREEN];
			tmpB = image[x][y][BLUE];
			for (int i = counterY; i<counterY + 2; ++i)
			{
				for (int j = counterX; j<counterX + 2; ++j)
				{
					enlargedImage[i][j][RED] = tmpR;
					enlargedImage[i][j][GREEN] = tmpG;
					enlargedImage[i][j][BLUE] = tmpB;
				}
			}
			counterX += 2;

		}
		counterX = 0;
		counterY += 2;
	}

	copy_array(image, enlargedImage);

}

void filter_shrink()
{
	float ratio = get_ratio();
	filter_shrink(ratio);
}
void filter_shrink(float ratio) {
	unsigned char shrunkImage[SIZE][SIZE][RGB];
	int counter = 0, row = 0, col = 0;
	int small = 1 / (ratio);
	unsigned int red_sum, blue_sum, green_sum;
	for (int k = 0; k < SIZE; k += 6) {
		for (int i = k; i < SIZE; ++i) {
			if (i % small) {
				shrunkImage[row][col][RED] = (red_sum / small);
				shrunkImage[row][col][BLUE] = (blue_sum / small);
				shrunkImage[row][col][GREEN] = (green_sum / small);
				++col;
			}
			for (int j = k; j < (small + k); ++j) {
				red_sum += image[j][i][RED];
				blue_sum += image[j][i][BLUE];
				green_sum += image[j][i][GREEN];
			}
		}
		++row;
	}
	for (int i = 0; i < SIZE; ++i) {
		if (i >= row) {
			for (int j = 0; j < SIZE; ++j) {
				shrunkImage[i][j][RED] = 255;
				shrunkImage[i][j][BLUE] = 255;
				shrunkImage[i][j][GREEN] = 255;
			}
		}
		for (int j = col; j < SIZE; ++j) {
			shrunkImage[i][j][RED] = 255;
			shrunkImage[i][j][BLUE] = 255;
			shrunkImage[i][j][GREEN] = 255;
		}
	}
	copy_array(image, shrunkImage);
}

bool load_image(unsigned char imageRGB[][SIZE][RGB], bool& grayscale)
{
	char filename[100];

	cout << "Enter the source image file name (don't include .bmp): ";
	cin.getline(filename, 100, '\n');

	// Add to it .bmp extension and load image
	strcat(filename, ".bmp");

	FILE *file;
	if (!(file = fopen(filename, "rb"))) {
		cout << "Cannot open file: " << filename << endl;
		return false;
	}
	fseek(file, 11, SEEK_CUR);
	unsigned char type[1];
	fread(type, sizeof(unsigned char), 1, file);
	grayscale = (int)type[0] != 0;


	unsigned char imageGS[SIZE][SIZE];

	if (grayscale) {
		if (readGSBMP(filename, imageGS) != 0) return false;
		copy_array(imageRGB, imageGS);
	}
	else
		if (readRGBBMP(filename, imageRGB) != 0) return false;

	return true;
}

void save_image(unsigned char imageRGB[][SIZE][RGB], bool grayscale)
{
	char filename[100];

	// Get gray scale image target file name
	cout << "Enter the target image file name (don't include .bmp): ";
	cin.getline(filename, 100, '\n');

	// Add to it .bmp extension and load image
	strcat(filename, ".bmp");

	if (grayscale) {
		unsigned char imageGS[SIZE][SIZE];
		copy_array(imageGS, imageRGB);
		writeGSBMP(filename, imageGS);
	}
	else {
		writeRGBBMP(filename, imageRGB);
	}
}
