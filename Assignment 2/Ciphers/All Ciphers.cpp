/* FCI – Programming 1 – 2018 - Assignment 2

	Program Name: All Ciphers.cpp
	Last Modification Date: 25/02/2018
	Ahmed Nasr Eldardery (megadardery): G2 - 20170034
	Purpose: This is a program that implements all 10 different types of ciphers in Assignment 2;
*/
#include <iostream>
#include <string>
using namespace std;

#define EMPTY ""
const int c_morse_size = 64;

const string c_morse[c_morse_size] = { " ", "-.-.--", ".-..-.", EMPTY, "...-..-", EMPTY, ".-...", ".----.", "-.--.", "-.--.-", EMPTY, ".-.-.", "--..--", "-....-", ".-.-.-", "-..-.", //	space !"#$%&'()*+,-./
"-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.",	//	Numbers
"---...", "-.-.-.", EMPTY, "-...-", EMPTY, "..--..", ".--.-.", //	:;<=>?@
".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", //letters
EMPTY, EMPTY, EMPTY, EMPTY, "..--.-" }; //	[\]^_

int getNumber(int begin, int end, string message) {
	int answer;
	while (true) {
		string raw;
		cout << message;
		getline(cin, raw);
		try {
			answer = stoi(raw);
		}
		catch (...) {
			cout << "Invalid input.\n";
			continue;
		}
		if (answer < begin || answer > end) {
			cout << "Invalid input.\n";
			continue;
		}
		break;
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

//--------------------------------------------------------------------------------------------------------------------------------------------
string AffineCipher(string msg, bool cipher) {
	int a, b, c;

	while (true) {
		a = getNumber(1, 25, "\nThe cipher uses the formula (ax + b) mod 26 and the decipher uses the formula c(y - b) mod 26 \na is (1-25): ");
		b = getNumber(0, 25, "b is (0-25): ");
		c = getNumber(1, 25, "c is (1-25): ");
		if (a*c % 26 == 1)
			break;
		else {
			cout << "\nThe values you have inputted cannot be used for the cipher operation, they must satisfy the condition (a * c) mod 26 = 1\n";
			return "";
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
	int shifts = getNumber(0,25, "\nEnter the number of right shifts you want (0-25): \n");
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
			if (letter >= 22) --letter;

			int a = letter / 5 + 1;
			int b = letter % 5 + 1;

			result += a + '0';
			result += b + '0';
		}
		else {
			if (msg[i] >= '0' && msg[i] <= '5') {
				if (first == -1)
					first = msg[i] - '0' - 1;
				else {
					int code = 5 * first + msg[i] - '0' - 1;
					if (code >= 22)
						++code;
					result += code + 'A';
					first = -1;
				}
			}
			else
				result += msg[i];
		}
	}
	return result;
}
string MorseCipher(string msg, bool cipher) {
	string result = "";
	string currLetter = "";
	if (!cipher) msg += ' ';
	for (int i = 0; i < (int)msg.length(); ++i) {
		if (cipher) {
			if (msg[i] >= 'a' && msg[i] <= 'z')
				msg[i] -= 0x20;
			else if (msg[i]<' ' || msg[i] > '_' || c_morse[msg[i] - ' '] == EMPTY)
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
	char secret;
	while (true) {
		cout << "\nEnter the secret key: \n";
		string raw;
		getline(cin, raw);
		if (raw.length() != 1) {
			cout << "Invalid input.\n";
			continue;
		}
		secret = raw[0];
		break;
	}
	string hexa = "\n(Hexa: ";
	string result = "";
	for (int i = 0; i < (int)msg.length(); ++i) {
		int curr = msg[i] ^ secret;
		hexa = (hexa + "0123456789ABCDEF"[curr % 16]) + "0123456789ABCDEF"[(curr >> 4) % 16];
		result += curr;
	}
	return result + hexa + ")";
}
string RailfenceCipher(string msg, bool cipher) {
	int lines = getNumber(0, 25, "\nEnter the number of lines you want (0-25): \n");
	int jump = 2 * lines - 2;
	if (jump == 0) jump = 1;

	string result;
	if (cipher)
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
//--------------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------

int main() {

	string(*ciphers[10])(string, bool) = { AffineCipher,CaesarCipher,AtbashCipher,ROT13Cipher,BaconianCipher,SimpleSubstitutionCipher,PolybiusSquareCipher,MorseCipher,XORCipher,RailfenceCipher };

	cout << "Ahlan ya user ya habibi.\n";

	while (true) {
		cout << "\nWhat do you like to do today?\n" 
			<< "1- Cipher a message\n"
			<< "2- Decipher a message\n"
			<< "3- End\n";

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

		int mycipher = getNumber(0, 9, "\nWhich encryption algorithm do you want to try? (0-9)\n");

		if (action == "1") {
			cout << "\nPlease enter the message to cipher:\n";
			string message;
			getline(cin, message);
			cout << ciphers[mycipher](message, true) << "\n";
		}
		else if (action == "2") {
			cout << "\nPlease enter the message to decipher:\n";
			string message;
			getline(cin, message);
			cout << ciphers[mycipher](message, false) << "\n";
		}

		cout << "\n";
	}

	return 0;
}
