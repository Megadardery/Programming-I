#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

void get_set(int arr[] , int &c);
void print_set(const int arr[] , int c);
void get_path();
void create_file(int arr[] , int c);
void load_file(int arr[], int& c);
void prepare_set(int[],int&);

int main()
{
    int choose ;
    int arr[10000];
    int c = 0;
    cout << "1 >> Create File" << endl;
    cout << "2 >> Load File" << endl;
    cin >> choose;
    cin.ignore(INT_MAX, '\n');
    if(choose == 1){
        get_set(arr, c);
        prepare_set(arr,c);
        //create_file(arr,c);
        cout << endl;
        print_set(arr,c);
    }
    else if (choose == 2){
        load_file(arr,c);
        prepare_set(arr,c);
        print_set(arr,c);
    }
    /*get_set(arr, c);
    cout << endl;
    print_set(arr,c);*/
}
void get_set(int arr[] , int &c){
    c = 0;
    while (true){
        int x;
        cin >> arr[c++];
        if (cin.get()=='\n')
            break;
    }
}

void print_set(const int arr[] , int c){
    cout << "{";
    for(int i = 0 ; i < c ; ++i){
        cout << arr[i];
        if (i != c - 1)
             cout << ", ";
        else
            cout << "}" << endl;
    }
}

void get_path(char path[]){
    cout << "Enter path : " ;
    cin.getline(path , 100 , '\n');
    //----------------: unallowed                / \ : * ? " < > |
}

void create_file(int arr[] , int c){
    char path[100];
    get_path(path);
    ofstream file(path);

    for (int i = 0; i < c; ++i){
        file << arr[i] << " ";
    }
    cout << "File created successfully! ^_^" << endl;
}

void load_file(int arr[], int& c){
    char path[100];
    get_path(path);
    ifstream file(path);

    int current;
    c = 0;
    while (file >> current && !file.eof()){
        arr[c++] = current;
    }
    cout << "File loaded successfully! ^_^" << endl;
}

void prepare_set(int arr[], int& c){
    sort(arr,arr+c);

    int memory = arr[0];
    for (int i = 1; i < c; ){
        if (arr[i] != memory){
            memory = arr[i];
            ++i;
        }
        else{
            for (int j = i; j < c; ++j){
                arr[j] = arr[j+1];
            }
            --c;
        }
    }
}

