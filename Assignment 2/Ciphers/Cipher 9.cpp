/* FCI – Programming 1 – 2018 - Assignment 2

	Program Name: Cipher 9.cpp
	Last Modification Date: 28/02/2018
	Adham Mamdouh Mohamed (adhammamdouh): G2 - 20170039
	Purpose: This is a program that implements cipher #9: railfence cipher.
*/

#include <iostream>

using namespace std;

void cipher(string msg, int key);
void Decipher(string msg, int key);

int main()
{
    string msg ;
    int key = 0, choose = 0;
    cout << "Ahlan ya user ya 7bibi" << '\n' ;
    cout << "Rail Fence cypher :" << '\n' ;
    while(true)
    {
        cout << "What do you want to do today ?" << '\n';
        cout << "1 >> Cipher a message" << '\n' ;
        cout << "2 >> Decipher a message" << '\n' ;
        cout << "3 >> End" << '\n';
        cin >> choose ;
        cout << endl;
        if(choose == 1)
        {
            cout << "Enter the message" << '\n';
            cin.ignore();
            getline(cin, msg);
            cout << "Enter the secret key" << '\n';
            cin >> key;
            cipher(msg, key);
            cout << endl;
        }
        else if(choose == 2)
        {
            cout << "Enter the message" << '\n';
            cin.ignore();
            getline(cin, msg);
            cout << "Enter the secret key" << '\n';
            cin >> key;
            Decipher(msg, key);
            cout << endl;
        }
        else if(choose == 3)
        {
            break;
        }
        else
        {
            cout << "\nError enter the number again";
        }
    }

    return 0;
}
void cipher(string msg, int key)
{
    int msgLen = msg.length(), i, j, k = -1, row = 0, col = 0;
    char railMatrix[key][msgLen];

    for(i = 0; i < key; ++i)
        for(j = 0; j < msgLen; ++j)
            railMatrix[i][j] = '\n';

    for(i = 0; i < msgLen; ++i)
    {
        railMatrix[row][col++] = msg[i];

        if(row == 0 || row == key-1)
            k= k * (-1);

        row = row + k;
    }

    cout<<"\nEncrypted Message: ";

    for(i = 0; i < key; ++i)
    {
        for(j = 0; j < msgLen; ++j)
        {
            if(railMatrix[i][j] != '\n')
            {
                cout<<railMatrix[i][j];
            }
        }
    }
}
void Decipher(string msg, int key)
{
    int msgLen = msg.length(), i, j, k = -1, row = 0, col = 0, m = 0;
    char railMatrix[key][msgLen];

    for(i = 0; i < key; ++i)
        for(j = 0; j < msgLen; ++j)
            railMatrix[i][j] = '\n';

    for(i = 0; i < msgLen; ++i)
    {
        railMatrix[row][col++] = '*';

        if(row == 0 || row == key-1)
        {
            k= k * (-1);
        }

        row = row + k;
    }

    for(i = 0; i < key; ++i)
    {
        for(j = 0; j < msgLen; ++j)
        {
            if(railMatrix[i][j] == '*')
            {
                railMatrix[i][j] = msg[m++];
            }
        }
    }
    row = 0;
    col = 0;
    k = -1;

    cout<<"\nDecrypted Message: ";

    for(i = 0; i < msgLen; ++i)
    {
        cout<<railMatrix[row][col++];

        if(row == 0 || row == key-1)
        {
            k= k * (-1);
        }
        row = row + k;
    }
}

