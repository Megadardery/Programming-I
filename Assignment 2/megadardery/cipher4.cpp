/* FCI – Programming 1 – 2018 - Assignment 2

	Program Name: cipher4.cpp
	Last Modification Date: 21/02/2018
	Ahmed Nasr Eldardery (megadardery): G2 - 20170034
	Purpose: This is a program that implements cipher #4;
*/
#include <iostream>
#include <string>

using namespace std;

string BaconianCipher(string msg) {

	string answer = "";

	for (int i = 0; i < (int)msg.length(); ++i) {
		int ascii = msg[i];

		if (ascii >= 'a' && ascii <= 'z')			//to upper case
			ascii -= 0x20;

		if (ascii < 'A' || ascii > 'Z') {
			answer += ascii;
			continue;
		}

		int encoding = ascii - 'A';
		string charEncoding = "";
		for (int i = 0; i < 5; ++i) {
			charEncoding = "ab"[encoding & 1] + charEncoding;
			encoding >>= 1;
		}
		answer = answer + charEncoding;
	}
	return answer;
}

string BaconianDecipher(string msg) {

	string answer = "";

	for (int i = 4; i < (int)msg.length(); i += 5) {
		if (msg[i - 4] != 'a' && msg[i - 4] != 'b') {
			answer += msg[i - 4];
			i -= 4;
			continue;

		}
		int encoding =
			(msg[i - 4] - 'a') * 16 +
			(msg[i - 3] - 'a') * 8 +
			(msg[i - 2] - 'a') * 4 +
			(msg[i - 1] - 'a') * 2 +
			(msg[i] - 'a') * 1;

		answer += (encoding + 'A');
	}
	return answer;
}

int main() {

	cout << "Ahlan ya user ya habibi.\n";

	while (true) {
		cout << "What do you like to do today?\n"
			<< "1- Cipher a message\n"
			<< "2- Decipher a message\n"
			<< "3- End\n";

		string action;
		getline(cin, action);
		if (action == "1") {
			cout << "Please enter the message to cipher:\n";
			string message;
			getline(cin, message);
			cout << BaconianCipher(message) << "\n";
		}
		else if (action == "2") {
			cout << "Please enter the message to decipher:\n";
			string message;
			getline(cin, message);
			cout << BaconianDecipher(message) << "\n";
		}
		else if (action == "3") {
			cout << "Habibi ya user, ashofak later :)\n";
			break;
		}
		else
			cout << "Invalid input\n";
		cout << "\n";
	}

	return 0;
}
