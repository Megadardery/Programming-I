// FCI - Programming 1 - 2018 - Assignment 2
// Program name:    Bakhshali
// author1 and id and group : adham mamdouh , 20170039 , 2
// Teaching Assistant: Eng.Ali Eng.Menna

#include <iostream>

using namespace std;

int main()
{
    int number =0;
    cin >> number ;
    double guess = 1.0;
    double a = 0.0 , b = 0.0;
    if( number < 0 ){
        cout << "invalid input" << endl;
        return 0;
    }
    else if (number == 0){
        cout << 0 << endl;
        return 0 ;
    }
    for(int i = 0 ; i < 10 ; ++i){
        a =((number - (guess * guess)) / (2 * guess));
        b = (guess + a);
        guess = (b - ((a * a) / (2 * b)));
    }
    cout << guess << endl;

    return 0;
}
