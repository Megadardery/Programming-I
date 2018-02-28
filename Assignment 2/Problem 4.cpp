/* FCI – Programming 1 – 2018 - Assignment 2
	Program Name: Problem 4.cpp
	Last Modification Date: 26/02/2018
	Ahmed Nasr Eldardery (megadardery): G2 - 20170034
	Purpose: This is a program that implements problem #4 (13)
  Algorithm:
      1.    Get weight, height, gender, and age.
      2.    Calculate BMR:
                66 + (6.3 * weight) + (12.9 * height) - (6.8 * age) for men
                655 + (4.3 * weight) + (4.7 * height) - (4.7 * age) for women
      3.    Calculate the number of chocolate bars: BMR/230.0

*/

#include <iostream>

using namespace std;

int main() {
	float weight, height;
	int age;
	bool isMan;
  double BMR;
  
	cout << "Enter your weight in pounds: ";
	cin >> weight;
	cout << "Enter your height in inches: ";
	cin >> height;
	cout << "Enter your age: ";
	cin >> age;
	cin.ignore();
	cout << "Enter your gender (M or F): ";
	if (cin.get() == 'M')
		isMan = true;
	else
		isMan = false;

	if (isMan)
		BMR = 66 + (6.3 * weight) + (12.9 * height) - (6.8 * age);
	else
		BMR = 655 + (4.3 * weight) + (4.7 * height) - (4.7 * age);

	cout << "Your BMR is: " << BMR << "\n";

	cout << "You should consume " << BMR/230.0 << " chocolate bars to maintain your weight\n";
}
