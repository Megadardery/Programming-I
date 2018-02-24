#include <iostream>

using namespace std;
double pow(double base , double power){
    double Power = 1.0;
    int i = 1;
    for(i = 1 ; i <= power ; ++i){
        Power= Power * base;
    }
    return Power;
}
double fac(double num){
    double Fac = 1.0 ;
    int i = 0 ;
    while(num > 0){
        Fac = Fac * num;
        num = num -1;
        i += 1;
    }
    return Fac ;
}
int main()
{
    float x = 0.0 ;
    double power = 1.0 ;
    cout << "Enter the the power"
    cin >> x;
    for (int i = 1 ; i <= 100 ; ++i){
        power = power + (pow(x,i) / fac(i));
    }
    cout << fixed << power << endl;
    return 0;
}
