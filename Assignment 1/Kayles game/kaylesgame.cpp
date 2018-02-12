#include <iostream>

using namespace std;
char list[20] = {'1','2','3','4','5','6','7','8','9','0','1','2','3','4','5','6','7','8','9','0'};

void print_arr(char list[]){
    for (int i = 0 ; i < 20 ; ++i){
        cout << list[i] << " ";
    }
    cout << endl;

}

int main()
{
    int counter = 0 , changer = 1 , i = 0 , j = 0 , divistor = 10, num =5 ;
    string player1 , player2, maxx;
    print_arr(list);
    while (true){
        if(counter == 0){
            cout << "enter the name of the players :" << endl;
            char list[20] = {'1','2','3','4','5','6','7','8','9','0','1','2','3','4','5','6','7','8','9','0'};
            counter = 20;
            cout << "the name of the first player ";
            cin >> player1;
            cout << "the name of the second player ";
            cin >> player2;
        }
        while (true){
            if(changer == 1){
                cout << player1 <<" :"<< endl;
                cin >> maxx;
                if(maxx.length() < 3){
                    if(maxx.length() == 1){
                            divistor = 1;
                        }
                        else{
                            divistor = 10;
                        }
                    for (int k = 0 ; k < maxx.length() ; ++k){
                        i = ((int(maxx[k])-int('0'))*divistor)+i;
                        divistor =divistor / 10;
                        j = i;
                    }
                }
                else{
                    if(maxx.length() == 3){
                        divistor = 1;
                        }
                    else if (maxx.length() == 5){
                        divistor = 10;
                        }
                    for (int k = 0 ; k < maxx.length() ; ++k){
                        if(maxx == "10,9" || maxx == "9,10"){
                            i = 9;
                            j = 10;
                            break;
                        }
                        if(maxx[k] == ','){
                            num = k;
                            if(maxx.length() == 3){
                                divistor = 1;
                            }
                            else if (maxx.length() == 5){
                                divistor = 10;
                            }
                            continue;
                        }
                        else if(k < num){
                            i = ((int(maxx[k])-'0')*divistor) + i;
                            divistor /= 10;
                        }
                        else if (k > num){
                            j = ((int(maxx[k])-'0')*divistor) + j;
                            divistor /= 10;
                        }
                    }

                }
                changer = 2;
            }
            else if(changer == 2){
                cout << player2 << " :"<< endl;
                cin >> maxx;
                if(maxx.length() < 3){
                    if(maxx.length() == 1){
                        divistor = 1;
                    }
                    else{
                        divistor = 10;
                    }
                    for (int k = 0 ; k < maxx.length() ; ++k){
                        i = ((int(maxx[k])-'0')*divistor)+i;
                        divistor /= 10;
                    }
                    j = i;
                }
                else{
                    if(maxx.length() == 3){
                        divistor = 1;
                        }
                    else if (maxx.length() == 5){
                        divistor = 10;
                        }
                    for (int k = 0 ; k < maxx.length() ; ++k){
                        if(maxx == "10,9" || maxx == "9,10"){
                            i = 9;
                            j = 10;
                            break;
                        }
                        else if(maxx[k] == ','){
                            num = k;
                            if(maxx.length() == 3){
                                divistor = 1;
                            }
                            else if (maxx.length() == 5){
                            divistor = 10;
                            }
                            continue;
                        }
                        else if(k < num){
                            i = ((int(maxx[k])-'0')*divistor) + i;
                            divistor /= 10;
                        }
                        else if (k > num){
                            j = ((int(maxx[k])-'0')*divistor) + j;
                            divistor /= 10;
                        }
                    }

                }
                changer = 1;
            }
            cout << i << endl;
            cout << j << endl ;
            if(i > 20 || j > 20){
                cout << "error the number is out of the range" << endl;
                if(changer == 1){
                    changer = 2;
                }
                else{
                    changer = 1;
                }
            }
            else if(i == j and maxx.length() !=1 and maxx.length() != 2){
                cout << "the numbers are the same" << endl;
                if(changer == 1){
                    changer = 2;
                }
                else{
                    changer = 1;
                }
            }
            else if(i != j + 1 && i != j - 1 && maxx.length() > 2){
                cout << "the numbers are not adjacent" << endl;
                cout << i << "    " << j << endl;
                if(changer == 1){
                    changer = 2;
                }
                else{
                    changer = 1;
                }
            }
            else if(i == j){
                list[i - 1] = '-';
                counter -= 1;
                print_arr(list);
            }
            else if(i == j+1 or i == j -1){
                list[i-1] = '-';
                list[j-1] = '-';
                counter -= 2;
                print_arr(list);
            }
            if(counter == 0){
                if(changer == 2){
                    cout << player1 << " is the winner" << endl;
                }
                else{
                    cout << player2 << " is the winner" << endl;
                }
                break;
            }
            i = 0;
            j = 0;
        }
    }
    return 0;
}
