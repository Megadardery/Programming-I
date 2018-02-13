#include <iostream>
#include <string>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<time.h>
#include <stdlib.h>

using namespace std;

int main()
{
	int typ , now = 100 , p1 , p2 , pc ,c = 0;
	bool ran = false;
	cout << " Welcome to SUM-100 game..\n you and the second player will choose a number from 1 to 10 \n then your numbers will be added to each other \n when the sum reaches 100 the last one who played is the winner \n \n";
	cout << "Please choose number of players : ";
	cin >> typ;
	// checks that the number of players entered correctly
	while (true) {
		if (typ != 1 && typ != 2)
		{
			cout << "Error please try again."<<endl<<"Please choose number of players : ";
			cin >> typ;
		}
		else
			break;
	}

	if (typ == 2) {
		// main loop of the game of 2 players
		while (true)
		{
			// checks that player 1 playes corrrectly
			while (true)
			{
				cout << "Player 1 : ";
				cin >> p1;
				now -= p1;
				if (now < 0 || p1 <= 0 || p1 > 10)
				{
					cout << "Error please try again\n";
					now += p1;
				}
				else
					break;
			}
			//checks winning of player 1
			if (now == 0)
			{
				cout << "Player 1 wins\n";
				break;
			}
			cout << "Sum : " << 100-now << endl;
			// checks that player 2 playes corrrectly
			while (true)
			{
				cout << "Player 2 : ";
				cin >> p2;
				now -= p2;
				if (now < 0 || p2 <= 0 || p2 > 10)
				{
					cout << "Error please try again\n";
					now += p2;
				}
				else
					break;
			}
			//checks winning of player 2
			if (now == 0)
			{
				cout << "Player 2 wins\n";
				break;
			}
			cout << "Sum : " << 100-now << endl;


		}

	}

	else if (typ == 1)
	{
		// main game loop
		while (true)
		{
			// checks that player playes corrrectly
			while (true)
			{
				cout << "You : ";
				cin >> p1;
				now -= p1;
				if (now < 0 || p1 <= 0 || p1 > 10)
				{
					cout << "Error please try again\n";
					now += p1;
				}
				else
					break;
			}
			//checks winning of player
			if (now == 0)
			{
				cout << "You win\n";
				break;
			}
			cout << "Sum : " << 100-now<< endl;
			pc = 11 - p1;
			if (c == 0)
			{
				pc = 12 - p1;
				c++;
			}
			if ((pc > 10 || ran) && now - pc > 11)
			{
				pc = rand() % 10 + 1;
				ran = true;
			}
			if (now <= 10)
				pc = now;
			now -= pc;

			cout << "PC : " << pc<<endl;
			if (now == 0)
			{
				cout << "PC wins\n";
				break;
			}
			cout << "Sum : " << 100 - now << endl;

		}
	}




	return 0;
}
