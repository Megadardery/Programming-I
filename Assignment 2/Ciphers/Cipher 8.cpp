#include <iostream>

using namespace std;

void cipher(string word , char key);
void decipher(string text , char key);

int main()
{
    int choose = 0 ;
    char key ;
    string text = "" ;
    cout << "ahlan ya user ya habibi" << endl;
    cout << " 1 >> cipher " << endl;
    cout << " 2 >> decipher " << endl;
    cout << " 3 >> End " << endl;
    cin >> choose ;

    cout << "enter the text" << endl;
    cin.ignore();
    getline(cin , text);
    cout << "enter the key :" << endl;
    cin >> key;
    if(choose == 1){
        cipher(text , key);
    }
    else if(choose == 2){
        decipher(text , key);
    }
    else if(choose == 3){
        return 0 ;
    }
    return 0;
}
void cipher(string text , char key){
    for(int i = 0 ; i< text.length() ; ++i){
        if(text[i] == ' '){
            continue;
        }
        cout << hex << (96 + (text[i] ^ key));
    }
}

void decipher(string text , char key){
    int Xor = 0 , dec = 0 , hexa = 0;
    for(int i = 0 ; i < text.length() ; ++i){
        if(text[i] >= '0' && text[i] <= '9'){
            dec = (text[i] - '0');
        }
        else if(text[i] > 96 && text[i] < 123){
            dec = ((text[i] - char(97)) + 10);
        }
        if(i % 2 == 0){
            hexa += (dec * 16);
        }
        else{
            hexa += dec;
            cout << char((char(hexa) ^ char(96)) ^ key);
            hexa = 0;
        }
    }
}
