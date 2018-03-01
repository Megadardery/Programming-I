/* FCI – Programming 1 – 2018 - Assignment 2
	Program Name: Cipher 6.cpp
	Last Modification Date: 28/02/2018
	Adham Mamdouh Mohamed (adhammamdouh): G2 - 20170039
	Purpose: This is a program that implements cipher #6: Polybius square cipher.
*/

#include <iostream>
#include <cmath>

using namespace std;

void cipher(string msg , string key);
void decipher(string deciphe , string key);


int main()
{
    int choose;
    string msg , key ;
    cout << "ahlan ya user ya 7abibi" << endl;
    cout << "Polybius Square Cipher" << endl;
    while(true){
    cout << "What do you want to do today ?" << '\n';
    cout << "1 >> Cipher a message" << '\n' ;
    cout << "2 >> Decipher a message" << '\n' ;
    cout << "3 >> End" << '\n';
    cin >> choose;
    if(choose == 1){
        cout << "Enter The secret key :" << endl;
        cin.ignore();
        getline(cin , key);
        cout << "Enter the message : " ;
        getline(cin ,msg);
        cipher(msg , key);
    }
    else if(choose == 2){
        cout << "Enter The secret key :" << endl;
        cin.ignore();
        getline(cin , key);
        cout << "Enter the ciphered message : " ;
        getline(cin ,msg);
        decipher(msg , key);
    }
    else if(choose == 3){
        return 0 ;
    }
    else {
        cout << '\a' << "invalid input" << endl;
    }
    }
    return 0;
}
void cipher(string msg , string key){
    int position = 0.0,col = 0.0;
    float row = 0.0 ;
    cout << '\n' ;
    for(int i = 0 ; i < msg.length() ; ++i){
        if(msg[i] == 'Z' || msg[i] == 'z'){
            cout << "00" ;
            continue;
        }
        if(int(msg[i]) > 96 && int(msg[i]) < 123){
            msg[i] = int(msg[i]) - 32;
        }
        else if(msg[i] == ' '){
            continue;
        }
        position = (int(msg[i]) - 64);
        row = ceil(position / 5.0);
        col = ceil(position % 5);
        if(col == 0){
            col = 5;
        }
        cout << key[2*(row-1)] <<key[2*(col -1)] ;
    }
    cout << '\n';
    cout << "\nThe secret key to decipher the message = " << key ;
}
void decipher(string deciphe , string key){
    int posit ;
    float k = 1.0 , m = 1.0;
    for(int i = 0 ; i < deciphe.length() ; ++i){
        if(deciphe[i] == '0'){
            ++i;
            cout << 'Z' ;
        }
        else if(i % 2 == 0){
        for(int j = 0 ; j < key.length() ; ++j){
            if(deciphe[i] == key[j]){
                posit = j;
                break;
            }
            k += 0.5;
        }
        }
        else{
            for(int j = 0 ; j < key.length() ; ++j){
                if(deciphe[i] == key[j]){
                    break;
                }
                m += 0.5;
            }
            cout << char(64 + (((posit - (posit - k))-1)*5 + m));
            k = 1.0 ;
            m = 1.0 ;
        }

    }
}