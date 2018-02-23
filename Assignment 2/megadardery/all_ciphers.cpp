/* FCI – Programming 1 – 2018 - Assignment 2

	Program Name: all_ciphers.cpp
	Last Modification Date: 23/02/2018
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
		cout << "\nEnter the cipher alphabet (26 letters). Be careful not to include repeated characters in the cipher alphabet: \n";
		getline(cin, charset);
		if (charset.length() != 26) {
			cout << "Invalid input.\n";
			continue;
		}
		return charset;
	}
}

//--------------------------------------------------------------------------------------------------------------------------------------------
string AffineCipher(string msg) {
	string result = "";
	for (int i = 0; i < (int)msg.length(); ++i) {
		if (msg[i] >= 'A' && msg[i] <= 'Z') {
			result += char(((msg[i] - 'A') * 5 + 8) % 26 + 'A');
		}
		else if (msg[i] >= 'a' && msg[i] <= 'z') {
			result += char(((msg[i] - 'a') * 5 + 8) % 26 + 'a');
		}
		else {
			result += msg[i];
		}
	}
	return result;
}
string CaesarCipher(string msg) {
	int shifts = getNumber(0,25, "\nEnter the number of right shifts you want (0-25): \n");
	string result = "";
	for (int i = 0; i < (int)msg.length(); ++i) {
		if (msg[i] >= 'A' && msg[i] <= 'Z')
			result += (msg[i] - 'A' + 26 - shifts) % 26 + 'A';
		else if (msg[i] >= 'a' && msg[i] <= 'z')
			result += (msg[i] - 'a' + 26 - shifts) % 26 + 'a';
		else
			result += msg[i]; 
	}
	return result;
}
string AtbashCipher(string msg) {
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
string ROT13Cipher(string msg) {
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
string BaconianCipher(string msg) {

	string result = "";

	for (int i = 0; i < (int)msg.length(); ++i) {
		int ascii = msg[i];

		if (ascii >= 'a' && ascii <= 'z')			//to upper case
			ascii -= 0x20;

		if (ascii < 'A' || ascii > 'Z') {
			result += ascii;
			continue;
		}

		int encoding = ascii - 'A';
		string charEncoding = "";
		for (int i = 0; i < 5; ++i) {
			charEncoding = "ab"[encoding & 1] + charEncoding;
			encoding >>= 1;
		}
		result = result + charEncoding;
	}
	return result;
}
string SimpleSubstitutionCipher(string msg) {
	string charset = getAlphabet();
	string result = "";
	for (int i = 0; i < (int)msg.length(); ++i) {
		if (msg[i] >= 'A' && msg[i] <= 'Z')
			result += charset[msg[i] - 'A'];
		else if (msg[i] >= 'a' && msg[i] <= 'z')
			result += charset[msg[i] - 'a'];
		else
			result += msg[i];
	}
	return result;
}
string PolybiusSquareCipher(string msg) {
	string result;
	for (int i = 0; i < (int)msg.length(); ++i) {
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
	return result;
}
string MorseCipher(string msg) {
	string result = "";

	for (int i = 0; i < (int)msg.length(); ++i) {
		if (msg[i] >= 'a' && msg[i] <= 'z')
			msg[i] -= 0x20;
		else if (msg[i]<' ' || msg[i] > '_' || c_morse[msg[i] - ' '] == EMPTY)
			continue;

		result += c_morse[msg[i] - ' '] + " ";
	}

	return result;

}
string XORCipher(string msg) {
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
string RailfenceCipher(string msg) {
	int lines = getNumber(0, 25, "\nEnter the number of lines you want (0-25): \n");

	string result = "";
	int jump = 2 * lines - 2;
	if (jump == 0) jump = 1;

	for (int mystep = 0; mystep < lines; ++mystep) {
		int advance = mystep * 2;

		for (int i = 0 - mystep; i < (int)msg.length(); i += jump) {
			if (i >= 0)
				result += msg[i];

			if (advance != 0 && advance != jump)
				if (i + advance < (int)msg.length())
					result += msg[i + advance];
		}
	}

	return result;
}
//--------------------------------------------------------------------------------------------------------------------------------------------
string AffineDecipher(string msg) {
	string result = "";
	for (int i = 0; i < (int)msg.length(); ++i) {
		if (msg[i] >= 'A' && msg[i] <= 'Z') {
			result += char((21 * (msg[i] - 'A' + 18) % 26) + 'A');
		}
		else if (msg[i] >= 'a' && msg[i] <= 'z') {
			result += char((21 * (msg[i] - 'a' + 18) % 26) + 'a');
		}
		else {
			result += msg[i];
		}
	}
	return result;
}
string CaesarDecipher(string msg) {
	int shifts = getNumber(0, 25, "\nEnter the number of right shifts you had (0-25): \n");
	string result = "";
	for (int i = 0; i < (int)msg.length(); ++i) {
		if (msg[i] >= 'A' && msg[i] <= 'Z')
			result += (msg[i] - 'A' + shifts) % 26 + 'A';
		else if (msg[i] >= 'a' && msg[i] <= 'z')
			result += (msg[i] - 'a' + shifts) % 26 + 'a';
		else
			result += msg[i];
	}
	return result;
}
string AtbashDecipher(string msg) {
	return AtbashCipher(msg);
}
string ROT13Decipher(string msg) {
	return ROT13Cipher(msg);
}
string BaconianDecipher(string msg) {

	string result = "";

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
	return result;
}
string SimpleSubstitutionDecipher(string msg) {
	string charset = getAlphabet();
	string result = "";
	for (int i = 0; i < (int)msg.length(); ++i) {
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
	return result;

}
string PolybiusSquareDecipher(string msg) {
	string result = "";

	int first = -1;

	for (int i = 0; i < (int)msg.length(); ++i) {
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
	return result;
}
string MorseDecipher(string msg) {
	string currLetter = "";
	string result = "";
	for (int i = 0; i <= (int)msg.length(); ++i) {
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
	return result;
}
string XORDecipher(string msg) {
	return XORCipher(msg);
}
string RailfenceDecipher(string msg) {
	int lines = getNumber(0, 25, "\nEnter the number of lines you want (0-25): \n");
	int jump = 2 * lines - 2;
	if (jump == 0) jump = 1;

	string result = msg;

	int curr = 0;
	for (int mystep = 0; mystep < lines; ++mystep) {
		int advance = mystep * 2;

		for (int i = 0 - mystep; i < (int)msg.length(); i += jump) {
			if (i >= 0)
				result[i] = msg[curr++];

			if (advance != 0 && advance != jump)
				if (i + advance < (int)msg.length())
					result[i + advance] = msg[curr++];
		}
	}
	return result;
}
//--------------------------------------------------------------------------------------------------------------------------------------------

int main() {

	string(*ciphers[10])(string) = { AffineCipher,CaesarCipher,AtbashCipher,ROT13Cipher,BaconianCipher,SimpleSubstitutionCipher,PolybiusSquareCipher,MorseCipher,XORCipher,RailfenceCipher };
	string(*deciphers[10])(string) = { AffineDecipher,CaesarDecipher,AtbashDecipher,ROT13Decipher,BaconianDecipher,SimpleSubstitutionDecipher,PolybiusSquareDecipher,MorseDecipher,XORDecipher,RailfenceDecipher };

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
			cout << ciphers[mycipher](message) << "\n";
		}
		else if (action == "2") {
			cout << "\nPlease enter the message to decipher:\n";
			string message;
			getline(cin, message);
			cout << deciphers[mycipher](message) << "\n";
		}

		cout << "\n";
	}

	return 0;
}
