#include <iostream>
#include <string>
#include <limits>

using namespace std;
/*
By Ahmed Nasr Eldardery - megadardery

The two squares game, implemented in c++ 

Version 2.0
11/2/2018
*/

const int c_size = 4;
const int c_size2 = c_size * c_size;

string* initializeBoard() {
	string* game = new string[c_size2];
	for (int i = 0; i < c_size2; ++i) {
		game[i] = to_string(i + 1);
	}
	return game;
}

void printBoard(string* game) {
	cout << '\n';
	for (int i = 0; i < c_size2; ++i) {
		cout << game[i] << '\t';
		if ((i + 1) % c_size == 0)
			cout << '\n';
	}
	cout << '\n';
}

bool checkPossible(string* game) {
	for (int i = 0; i < c_size2; ++i) {
		if ((i + 1) % c_size != 0 && (i + 1) < c_size2 && game[i] != "X" && game[i + 1] != "X") //horizontal stick
			return true;
		else if ((i + c_size) < c_size2 && game[i] != "X" && game[i + c_size] != "X") //vertical stick
			return true;
	}
	return false;
}

int* getValidMove(char turn,string* game) {
	int* ans = new int[2];
	string raw;
	cout << "Player " << turn << ", Enter your next move \"x, y\": \n";

	while (true) {
		getline(cin, raw);
		size_t res = raw.find(',');
		if (res == string::npos) {
			cout << "Invalid input, please re-enter in this format \"x,y\": \n";
			continue;
		}
		int num1, num2;
		try {
			num1 = stoi(raw.substr(0, res));
			num2 = stoi(raw.substr(res + 1, string::npos));
		}
		catch (...) {
			cout << "Invalid input, please re-enter in this format \"x,y\": \n";
			continue;
		}
		if (num1 > num2) {
			int temp = num2;
			num2 = num1;
			num1 = temp;
		}
		if (!((num1 > 0 && num2 > 0) && (num1 <= c_size2 && num2 <= c_size2) &&
			((num2 - num1 == c_size) || (num2 - num1 == 1 && num1 % c_size != 0)))) {
			cout << "Unallowed move, please re-enter: \n";
			continue;
		}
		if (game[num1 - 1] == "X" || game[num2 - 1] == "X") {
			cout << "The square is covered, please re-enter: \n";
			continue;
		}
		ans[0] = num1;
		ans[1] = num2;
		return ans;
	}
}

int* getAIMove(int x, int y) {
	int* ans = new int[2];
	ans[0] = c_size2 - x + 1;
	ans[1] = c_size2 - y + 1;
	cout << "Hmm.... I will do " << ans[0] << ", " << ans[1] << "\n";
	return ans;
}

void coreGame(bool human) {
	string* myGame = initializeBoard();
	cout << "--------------------------------------\n";

	char turn = '0';
	int* ans;
	while (checkPossible(myGame)) {
		printBoard(myGame);
		if (turn == '1')
			turn = '2';
		else
			turn = '1';
		if (human == false && turn == '2')
			ans = getAIMove(ans[0], ans[1]);
		else
			ans = getValidMove(turn, myGame);

		myGame[ans[0] - 1] = "X";
		myGame[ans[1] - 1] = "X";
	}
	printBoard(myGame);
	cout << "--------------------------------------\n";
	if (human == false && turn == '2')
		cout << "Hahaha! I win. Nobody can beat Mr. perfect AI :D\n";
	else
		cout << "Player " << turn << " is the winner!!! Congrats!!! :D\n";
}

int main() {
	cout << "Two squares game:\n\tThis game is played on a board of 4 x 4 squares. Two players take turns;\n";
	cout << "each of them takes turn to place a rectangle(that covers two squares) on the board, covering\n";
	cout << "any 2 squares. Only one rectangle can be on a square. A square cannot be covered twice. The\n";
	cout << "last player who can place a card on the board is the winner. By megadardery : D:\n\n";

	cout << "How many players are going to play ? \"1/2\" : \n";

	char gamestate;
	gamestate = cin.get();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	while (gamestate == '1' || gamestate == '2') {
		if (gamestate == '2')
			coreGame(true);
		else
			coreGame(false);

		cout << "Play again? How many players? \"1/2\": \n";
		gamestate = cin.get();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
}
