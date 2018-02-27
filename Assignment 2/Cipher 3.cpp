/* FCI – Programming 1 – 2018 - Assignment 2
	Program Name: cipher3.cpp
	Last Modification Date: 23/02/2018
	Ashraf Samir Ali (AshrafSamir): G2 - 20170053
	Purpose: This is a program that implements cipher #3: ROT13 Cipher.
	
	Algorithm >> take input as letter from user check
	if (userLetter[i]<78 and userLetter[i]>=65) or (userLetter[i]<110 and userLetter[i]>=97)
	then take this char and add 13
	else if userLetter[i]>=78 and userLetter[i]<=90 ) or (userLetter[i]>=110 and userLetter[i]<=122)
	then take this char and - 13
	else take this char and print it without changes  */

#include <iostream>
#include <string>
using namespace std;

int main()
{
    cout<<"Ahlan ya user ya habibi ."<<endl;
    cout<<"What do you like to do today? "<<endl;
    cout<<"1- Cipher a message"<<endl;
    cout<<"2- Decipher a message"<<endl;
    cout<<"3- End"<<endl;
    bool isOk=true ;
    string userLetter,cipherMessage ;
    int youLike;
    while(isOk)
    {
        cin>>youLike;
        cin.ignore();
        if(youLike<=0 || youLike>3)
        {
            while(youLike<=0 || youLike>3)
            {
                cout<<"choose 1 or 2 or 3"<<endl;
                cin>>youLike;
                cin.ignore();
                if(youLike>0 && youLike<=3)
                {
                    cout<<" confirm your number "<<endl;
                }

            }
        }

    else if(youLike==1)
    {
        cout<<"enter a letter"<<endl;
        getline(cin,userLetter);
        for(int i=0;i<userLetter.length();i++){
            if((userLetter[i]<78 && userLetter[i]>=65) || (userLetter[i]<110 &&userLetter[i]>=97 ) ){
                cipherMessage=userLetter[i]+13;
                cout<<cipherMessage;
            }
            else if((userLetter[i]>=78 &&userLetter[i]<=90 )|| (userLetter[i]>=110 &&userLetter[i]<=122)){

                 cipherMessage=userLetter[i]-13;
                 cout<<cipherMessage;
            }
            else{
                cipherMessage=userLetter[i];
                cout<<cipherMessage;
            }
        }
        isOk=false;
    }
    else if(youLike==2)
    {
        cout<<"enter a letter"<<endl;
        getline(cin,userLetter);
        for(int i=0;i<userLetter.length();i++){
            if((userLetter[i]<78 && userLetter[i]>=65) || (userLetter[i]<110 &&userLetter[i]>=97 ) ){
                cipherMessage=userLetter[i]+13;
                cout<<cipherMessage;
            }
            else if((userLetter[i]>=78 &&userLetter[i]<=90 )|| (userLetter[i]>=110 &&userLetter[i]<=122)){

                 cipherMessage=userLetter[i]-13;
                 cout<<cipherMessage;
            }
            else{
                cipherMessage=userLetter[i];
                cout<<cipherMessage;
            }
        }
        isOk=false;
    }
    else if(youLike==3)
    {
        return 0;
    }

}



return 0;
}
