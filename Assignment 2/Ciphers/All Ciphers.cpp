/* FCI – Programming 1 – 2018 - Assignment 2

	Program Name: All Ciphers.cpp
	Last Modification Date: 02/03/2018
	Ahmed Nasr Eldardery (megadardery): G2 - 20170034
	Adham Mamdouh Mohamed (adhammamdouh): G2 - 20170039
	Ashraf Samir Ali (ashrafsamir): G2 - 20170053
	Purpose: This is a program that implements all 10 different types of ciphers in Assignment 2

*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int getNumber(int, int, string);
string getAlphabet();

string AffineCipher(string, bool);
string CaesarCipher(string, bool);
string AtbashCipher(string, bool);
string ROT13Cipher(string, bool);
string BaconianCipher(string, bool);
string SimpleSubstitutionCipher(string, bool);
string PolybiusSquareCipher(string, bool);
string MorseCipher(string, bool);
string XORCipher(string, bool);
string RailfenceCipher(string, bool);

int main() {
	string(*ciphers[10])(string, bool) = { AffineCipher,CaesarCipher,AtbashCipher,ROT13Cipher,BaconianCipher,SimpleSubstitutionCipher,PolybiusSquareCipher,MorseCipher,XORCipher,RailfenceCipher };

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

		cout << "\nWhich encryption algorithm do you want to try? (0-9)\n";
		cout << " 0- Affine Cipher\n";
		cout << " 1- Caesar Cipher\n";
		cout << " 2- Atbash Cipher\n";
		cout << " 3- ROT13 Cipher\n";
		cout << " 4- Baconian Cipher\n";
		cout << " 5- Simple Subsititution Cipher\n";
		cout << " 6- Polybius Square Cipher\n";
		cout << " 7- Morse Code Cipher\n";
		cout << " 8- XOR Cipher\n";
		cout << " 9- Rail-fence Cipher\n";

		int mycipher = getNumber(0, 9, "");

		if (action == "1") {
			cout << "\nPlease enter the message to cipher:\n";
			string message;
			getline(cin, message);
			message = ciphers[mycipher](message, true);
			cout << "\nCiphered message:\n" << message << "\n";
		}
		else if (action == "2") {
			cout << "\nPlease enter the message to decipher:\n";
			string message;
			getline(cin, message);
			message = ciphers[mycipher](message, false);
			cout << "\nDeciphered message:\n" << message << "\n";
		}

		cout << "\n";
	}
	return 0;
}


int getNumber(int begin, int end, string message) {
	int answer;
	while (true) {
		string raw;
		cout << message;
		cin >> answer;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "Invalid input.\n";
		}
		else if (answer < begin || answer > end) {
			cout << "Input out of range (" << begin << "-" << end << ")\n";
		}
		else {
			cin.ignore(INT_MAX, '\n');
			break;
		}
	}
	return answer;
}

string getAlphabet() {
	string charset;
	while (true) {
		cout << "\nEnter the cipher key (1-26 letters)\n";
		getline(cin, charset);
		bool isTaken[26] = {};
		bool isOk = true;
		for (int i = 0; i < charset.length(); ++i) {
			if (charset[i] >= 'A' && charset[i] <= 'Z')
				charset[i] += 0x20;
			int value = charset[i] - 'a';
			if (value < 0 || value > 25) {
				cout << "Invalid key, must contain only alphabetical characters.\n";
				isOk = false;
				break;
			}
			if (isTaken[value]) {
				cout << "Invalid key, must not contain duplicate characters.\n";
				isOk = false;
				break;
			}
			else
				isTaken[value] = true;
		}
		if (isOk) {
			for (int i = 0; i < 26; ++i) {
				if (!isTaken[i])
					charset += ('a' + i);
			}
			return charset;
		}
	}
}

string AffineCipher(string msg, bool cipher) {
	const int cValues[] = { 1, 9, 21, 15, 3, 19, -1, 7, 23, 11, 5, 17, 25 };
	int a, b, c;
	if (cipher) {
		a = getNumber(1, 25, "a is (1-25) not divisible by 2 nor 13: ");
		while (a % 13 == 0 || a % 2 == 0) {
			cout << "Invalid input.\n";
			a = getNumber(1, 25, "a is (1-25) not divisible by 2 nor 13: ");
		}
		b = getNumber(0, 25, "b is (0-25)                          : ");
		cout << "The corresponding value for c is: " << cValues[a / 2] << "\n";
	}
	else {
		b = getNumber(0, 25, "b is (0-25)                          : ");
		c = getNumber(0, 25, "c is (0-25) not divisible by 2 nor 13: ");
		while (c % 13 == 0 || c % 2 == 0) {
			cout << "Invalid input.\n";
			c = getNumber(0, 25, "c is (0-25) not divisible by 2 nor 13: ");
		}
	}
	char bias;
	string result = "";

	for (int i = 0; i < (int)msg.length(); ++i) {
		if (msg[i] >= 'A' && msg[i] <= 'Z')
			bias = 'A';
		else if (msg[i] >= 'a' && msg[i] <= 'z')
			bias = 'a';
		else {
			result += msg[i];
			continue;
		}
		if (cipher)
			result += char(((msg[i] - bias) * a + b) % 26 + bias);
		else
			result += char((c * (msg[i] - bias - b + 26) % 26) + bias);
	}
	return result;
}
string CaesarCipher(string msg, bool cipher) {
	int shifts;
	if (cipher)
		shifts = getNumber(0, 25, "\nEnter the number of right shifts you want (0-25): \n");
	else
		shifts = getNumber(0, 25, "\nEnter the number of left shifts you want (0-25): \n");
	char bias;
	string result = "";

	for (int i = 0; i < (int)msg.length(); ++i) {
		if (msg[i] >= 'A' && msg[i] <= 'Z')
			bias = 'A';
		else if (msg[i] >= 'a' && msg[i] <= 'z')
			bias = 'a';
		else {
			result += msg[i];
			continue;
		}
		if (cipher)
			result += (msg[i] - bias + 26 - shifts) % 26 + bias;
		else
			result += (msg[i] - bias + shifts) % 26 + bias;
	}
	return result;
}
string AtbashCipher(string msg, bool cipher) {
	string result = "";
	for (int i = 0; i < (int)msg.length(); ++i) {
		if (msg[i] >= 'A' && msg[i] <= 'Z')
			result += 'Z' - msg[i] + 'A';
		else if (msg[i] >= 'a' && msg[i] <= 'z')
			result += 'z' - msg[i] + 'a';
		else
			result += msg[i];
	}
	return result;
}
string ROT13Cipher(string msg, bool cipher) {
	string result = "";
	for (int i = 0; i < (int)msg.length(); ++i) {
		if (msg[i] >= 'A' && msg[i] <= 'Z')
			result += (msg[i] - 'A' + 13) % 26 + 'A';
		else if (msg[i] >= 'a' && msg[i] <= 'z')
			result += (msg[i] - 'a' + 13) % 26 + 'a';
		else
			result += msg[i];
	}
	return result;
}
string BaconianCipher(string msg, bool cipher) {
	char bias;
	string result = "";
	if (cipher) {
		for (int i = 0; i < (int)msg.length(); ++i) {
			if (msg[i] >= 'A' && msg[i] <= 'Z')
				bias = 'A';
			else if (msg[i] >= 'a' && msg[i] <= 'z')
				bias = 'a';
			else {
				result += msg[i];
				continue;
			}

			int encoding = msg[i] - 'A';
			string charEncoding = "";
			for (int i = 0; i < 5; ++i) {
				charEncoding = "ab"[encoding & 1] + charEncoding;
				encoding >>= 1;
			}
			result += charEncoding;
		}
	}
	else {
		for (int i = 4; i < (int)msg.length(); i += 5) {
			if (msg[i - 4] != 'a' && msg[i - 4] != 'b') {
				result += msg[i - 4];
				i -= 4;
				continue;

			}
			int encoding =
				(msg[i - 4] - 'a') * 16 +
				(msg[i - 3] - 'a') * 8 +
				(msg[i - 2] - 'a') * 4 +
				(msg[i - 1] - 'a') * 2 +
				(msg[i] - 'a') * 1;

			result += (encoding + 'A');
		}
	}
	return result;
}
string SimpleSubstitutionCipher(string msg, bool cipher) {
	string charset = getAlphabet();
	string result = "";
	for (int i = 0; i < (int)msg.length(); ++i) {
		if (cipher) {
			if (msg[i] >= 'A' && msg[i] <= 'Z')
				result += charset[msg[i] - 'A'];
			else if (msg[i] >= 'a' && msg[i] <= 'z')
				result += charset[msg[i] - 'a'];
			else
				result += msg[i];
		}
		else {
			int j;
			for (j = 0; j < 26; ++j) {
				if (charset[j] == msg[i])
					break;
			}
			if (j == 26)
				result += msg[i];
			else
				result += j + 'a';
		}
	}
	return result;
}
string PolybiusSquareCipher(string msg, bool cipher) {
	string key;
	while (true) {
		string raw;
		cout << "Enter The secret key (5 unique characters):" << endl;
		getline(cin, raw);
		for (int i = 0; i < (int)raw.length(); ++i) {
			if (raw[i] != ' ')
				key += raw[i];
		}
		if (key.length() != 5) {
			cout << "Invalid input.\n";
		}
		else
			break;
	}


	string result;
	int first = -1;

	for (int i = 0; i < (int)msg.length(); ++i) {
		if (cipher) {
			int letter;
			if (msg[i] >= 'A' && msg[i] <= 'Z')
				letter = msg[i] - 'A';
			else if (msg[i] >= 'a' && msg[i] <= 'z')
				letter = msg[i] - 'a';
			else {
				result += msg[i];
				continue;
			}
			if (letter == 25) {
				result += "00";
			}
			else {
				int a = letter / 5;
				int b = letter % 5;

				result += key[a];
				result += key[b];
			}
		}
		else {
			int j;
			for (j = 0; j < 5; ++j) {
				if (key[j] == msg[i])
					break;
			}
			if (j == 5) {
				if (msg[i] == '0') {
					result += 'Z';
					++i;
				}
				else
					result += msg[i];
			}
			else {
				if (first == -1)
					first = j;
				else {
					int code = 5 * first + j;
					first = -1;
					result += code + 'A';

				}
			}

		}
	}
	return result;
}
string MorseCipher(string msg, bool cipher) {
	const int c_morse_size = 64;

	const string c_morse[c_morse_size] = { " ", "-.-.--", ".-..-.", "", "...-..-", "", ".-...", ".----.", "-.--.", "-.--.-", "", ".-.-.", "--..--", "-....-", ".-.-.-", "-..-.", //	space !"#$%&'()*+,-./
		"-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.",	//	Numbers
		"---...", "-.-.-.", "", "-...-", "", "..--..", ".--.-.", //	:;<=>?@
		".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", //letters
		"", "", "", "", "..--.-" }; //	[\]^_

	string result = "";
	string currLetter = "";
	if (!cipher) msg += ' ';
	for (int i = 0; i < (int)msg.length(); ++i) {
		if (cipher) {
			if (msg[i] >= 'a' && msg[i] <= 'z')
				msg[i] -= 0x20;
			else if (msg[i]<' ' || msg[i] > '_' || c_morse[msg[i] - ' '] == "")
				continue;

			result += c_morse[msg[i] - ' '] + " ";
		}
		else {
			if ((msg[i] == ' ' || i == (int)msg.length()) && currLetter != "") {
				if (currLetter == " ")
					result += ' ';
				else {
					int j;
					for (j = 0; j < c_morse_size; ++j) {
						if (c_morse[j] == currLetter) break;
					}
					if (j != c_morse_size)
						result += (j + ' ');
					else
						result += '#';
				}
				currLetter = "";
				continue;
			}
			currLetter += msg[i];
		}
	}

	return result;
}
string XORCipher(string msg, bool cipher) {
	cout << "How do you want to interpret your input\n1- String Message\n2- Hexadecimal Message\n";
	int response = getNumber(1, 2, "");

	char secretKey;
	while (true) {
		cout << "\nEnter the secret key: \n";
		string raw;
		getline(cin, raw);
		if (raw.length() != 1) {
			cout << "Invalid input.\n";
			continue;
		}
		secretKey = raw[0];
		break;
	}

	string hexaMsg = "\n(Hexa: ";
	string result = "";

	if (response == 1) {
		for (int i = 0; i < (int)msg.length(); ++i) {
			int curr = (msg[i] ^ secretKey) | 0x60;
			hexaMsg = (hexaMsg + "0123456789abcdef"[(curr >> 4) % 16]) + "0123456789abcdef"[curr % 16];
			result += curr;
		}
	}
	else {
		int dec = 0, charVal = 0;
		for (int i = 0; i < (int)msg.length(); ++i) {
			if (msg[i] >= '0' && msg[i] <= '9')
				dec = (msg[i] - '0');

			else if (msg[i] >= 'a' && msg[i] <= 'f')
				dec = ((msg[i] - 'a') + 10);

			else if (msg[i] >= 'A' && msg[i] <= 'F')
				dec = ((msg[i] - 'A') + 10);

			if (i % 2 == 0)
				charVal += (dec * 16);

			else {
				charVal += dec;
				int curr = (charVal ^ secretKey) | 0x60;
				hexaMsg = (hexaMsg + "0123456789abcdef"[curr % 16]) + "0123456789abcdef"[(curr >> 4) % 16];
				result += curr;

				charVal = 0;
			}
		}
	}
	return result + hexaMsg + ")";
}

string RailfenceCipher(string msg, bool cipher) {
	int key = getNumber(1, 25, "\nEnter the number of lines you want (1-25): \n");
	if (key == 1) return msg;
	int msgLen = msg.length(), k = -1, row = 0, col = 0;
	vector<vector<char>> railMatrix(key, vector<char>(msgLen));

	for (int i = 0; i < key; ++i)
		for (int j = 0; j < msgLen; ++j)
			railMatrix[i][j] = '-';

	for (int i = 0; i < msgLen; ++i) {
		railMatrix[row][col++] = (cipher ? msg[i] : '*');

		if (row == 0 || row == key - 1)
			k = -k;

		row += k;
	}

	if (cipher) {

		string result;

		for (int i = 0; i < key; ++i)
			for (int j = 0; j < msgLen; ++j)
				if (railMatrix[i][j] != '-')
					result += railMatrix[i][j];

		return result;
	}
	else {
		int m = 0;

		for (int i = 0; i < key; ++i)
			for (int j = 0; j < msgLen; ++j)
				if (railMatrix[i][j] == '*')
					railMatrix[i][j] = msg[m++];

		row = 0;
		col = 0;
		k = -1;

		string result;

		for (int i = 0; i < msgLen; ++i) {
			result += railMatrix[row][col++];

			if (row == 0 || row == key - 1)
				k = -k;

			row += k;
		}
		return result;
	}
}
