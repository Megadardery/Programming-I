#include <bits/stdc++.h>

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
    cout<<"at  "<<start<<"  degrees celsius the velocity of sound is  "<<velocity<<" m/s "<<endl;
    start++;
   }
    return 0;
}
