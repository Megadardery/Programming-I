/* FCI – Programming 1 – 2018 - Assignment 2

	Program Name: Cipher 9.cpp
	Last Modification Date: 28/02/2018
	Ahmed Nasr Eldardery (megadardery): G2 - 20170034
	Purpose: This is a program that implements cipher #9: railfence cipher.
*/

#include <iostream>

using namespace std;

string RailfenceCipher(string, int, bool);

int main() {
	cout << "Ahlan ya user ya habibi.\n";

	while (true) {
		cout << "\nWhat do you like to do today?\n"
			<< " 1- Cipher a message\n"
			<< " 2- Decipher a message\n"
			<< " 3- End\n";

		string action;
		getline(cin, action);

		if (action == "3") {
			cout << "\nHabibi ya user, ashofak later :)\n";
			break;
		}
		else if (action != "2" && action != "1") {
			cout << "Invalid input.\n";
			continue;
		}
		int lines;
        while (true) {
            string raw;
            cout << "\nEnter the number of lines you want (0-25): \n";
            cin >> lines;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(INT_MAX, '\n');
                cout << "Invalid input.\n";
                continue;
            }
            if (lines < 1 || lines > 25) {
                cout << "Invalid input.\n";
                continue;
            }
            cin.ignore(INT_MAX, '\n');
            break;
        }

		if (action == "1") {
			cout << "\nPlease enter the message to cipher:\n";
			string message;
			getline(cin, message);
			cout << RailfenceCipher(message, lines, true) << "\n";
		}
		else if (action == "2") {
			cout << "\nPlease enter the message to decipher:\n";
			string message;
			getline(cin, message);
			cout << RailfenceCipher(message, lines, false) << "\n";
		}

		cout << "\n";
	}
	return 0;
}

string RailfenceCipher(string msg, int lines, bool cipher) {

	int jump = 2 * lines - 2;
	if (jump == 0) jump = 1;

	string result;
	if (!cipher)
        result.resize(msg.size());

	int curr = 0;
	for (int mystep = 0; mystep < lines; ++mystep) {
		int advance = mystep * 2;

		for (int i = 0 - mystep; i < (int)msg.length(); i += jump) {
			if (i >= 0)
			if (cipher)
				result += msg[i];
			else
				result[i] = msg[curr++];

			if (advance != 0 && advance != jump)
				if (i + advance < (int)msg.length())
					if (cipher)
						result += msg[i + advance];
					else
						result[i + advance] = msg[curr++];
		}
	}

	return result;
}
