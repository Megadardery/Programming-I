#include <iostream>
#include <iomanip>

using namespace std;
double pow(double base, double power) {
	double Power = 1.0;
	int i = 1;
	for (i = 1; i <= power; ++i) {
		Power = Power * base;
	}
	return Power;
}
double fac(double num) {
	double Fac = 1.0;
	int i = 0;
	while (num > 0) {
		Fac = Fac * num;
		num = num - 1;
		i += 1;
	}
	return Fac;
}
int main()
{
	cout << fixed << setprecision(3);
	double x = 0.0;
	double power = 1.0;
	cout << "Enter the the power : ";
	cin >> x;
	for (int i = 1; i <= 100; ++i) {
		power = power + (pow(x, i) / fac(i));
		cout << power << " ";
		if (i % 10 == 0) cout << endl;
	}
	cout << endl << endl << endl;

	cout << "The answer is: " << power << endl;
	return 0;
}