/* FCI – Programming 1 – 2018 - Assignment 2
	Program Name: Problem 3.cpp
	Last Modification Date: 23/02/2018
	Ashraf Samir Ali (AshrafSamir): G2 - 20170053
	Purpose: This is a program that did problem #3 (11) in the book.
	
	Algorith >> take start and end from user
	while start < end
	calculate this function  velocity=331.3+0.61*start
	end loop
	print velocity
*/
#include <iostream>

using namespace std;

int main()
{
   float start,enD,velocity;
   cout<<"Enter Start : ";
   cin>>start;
   cout<<"Enter End   : ";
   cin>>enD;
   while(start<=enD){
    velocity=331.3+0.61*start;
    cout<<"at  "<<start<<"  degrees celsius the velocity of sound is  "<<fixed<<setprecision(1)<<velocity<<" m/s "<<endl;
    start++;
   }
    return 0;
}
