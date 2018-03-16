#include <iostream>
#include <fstream>

using namespace std;

void get_set(int[] , int&);
void print_set(const int[] , int);
void create_file(int[] , int);
void load_file(int[] , int&);
void prepare_set(int[] , int&);
void Disjoint(int[] , int[] , int , int);
void Set_equality(int[] , int[] , int , int);
void proper_subset(int[] , int[] , int , int , int);
void proper_subset_assist(int [] , int [] , int , int);

int main()
{
	int choose;
	int set1[10000] , set2[10000];
	int c1 = 0 , c2 = 0;
	cout << "Ahlan ya user ya Habibi" << endl;
	cout << "what do you want to do today" << endl;
    while(true){
        cout << "\n1 >> Create File" << endl;
        cout << "2 >> Load File" << endl;
        cout << "3 >> Display data sets" << endl;
        cout << "10 >> Check if A and B are disjoint" << endl;
        cout << "11 >> Check if A and B are equal" << endl;
        cout << "12 >> Check if a set is a proper subset of other" << endl;
        cout << "13 >> End" << endl;
        cin >> choose;
        cin.ignore(INT_MAX, '\n');
        cout << endl;
        switch(choose){
            case 1 :
                cout << "Enter the First Set :" << endl;
                get_set(set1 , c1);
                prepare_set(set1 , c1);
                create_file(set1 , c1);
                cout << "Enter the Second Set :" << endl;
                get_set(set2 , c2);
                prepare_set(set2 , c2);
                create_file(set2 , c2);
                break;
            case 2 :
                load_file(set1 , c1);
                prepare_set(set1 , c1);
                load_file(set2 , c2);
                prepare_set(set2 , c2);
                break;
            case 3 :
                print_set(set1 , c1);
                print_set(set1 , c2);
                break;
            case 10 :
                Disjoint(set1 , set2 , c1 ,c2);
                break;
            case 11 :
                Set_equality(set1 , set2 , c1 , c2);
                break;
            case 12 :
                proper_subset_assist(set1 , set2 , c1 , c2);
                break;
            case 13 :
                return 0;
            default :
                cout << "Invalid Input !!" << endl;
        }
    }
}
void get_set(int set[], int &c) {
	c = 0;
	while (true) {
		int x;
		cin >> set[c++];
		if (cin.get() == '\n')
			break;
	}
}

void print_set(const int set[], int c) {
	cout << "{";
	for (int i = 0; i < c; ++i) {
		cout << set[i];
		if (i != c - 1)
			cout << ", ";
		else
			cout << "}" << endl;
	}
}

void get_path(char path[]) {
	cout << "Enter path : ";
	cin.getline(path, 100, '\n');
	//----------------: unallowed                / \ : * ? " < > |
}

void create_file(int set[], int c) {
	ofstream file;
	while (true) {
		char path[100];
		cout << "Enter the path of the file to save: ";
		cin.getline(path, 100, '\n');
		file.open(path);
		if (!file)
			cout << "Couldn't access the file.\n";
		else
			break;
	}

	for (int i = 0; i < c; ++i) {
		file << set[i] << " ";
	}
	cout << "File created successfully! ^_^" << endl;
}

void load_file(int set[], int& c) {
	ifstream file;
	while (true) {
		char path[100];
		cout << "Enter the path of the file to load: ";
		cin.getline(path, 100, '\n');
		file.open(path);
		if (!file)
			cout << "Couldn't access the file.\n";
		else
			break;
	}

	int current;
	c = 0;
	while (file >> current && !file.eof()) {
		set[c++] = current;
	}
	cout << "File loaded successfully! ^_^" << endl;
}

void prepare_set(int set[], int& c) {
	for (int i = 0; i < c - 1; i++) {
		int min = i;

		//find the index of the minimum value in the unsorted list, remove duplicates.
		for (int j = i + 1; j < c; ++j) {
			if (set[min]>set[j])
				min = j;
			else if (set[min] == set[j]) {
				//remove item by swapping it with the end of the list
				//look through the current j again.
				int temp = set[j];
				set[j] = set[--c];
				set[c] = temp;
				--j;
			}
		}

		int temp = set[i];
		set[i] = set[min];
		set[min] = temp;			//swap
	}
}

void Disjoint(int set1[] , int set2[] , int c1 , int c2){
    int found = 0;
    for(int i = 0 ; i < c1 ; ++i){
        for(int j = 0 ; j < c2 ; ++j){
            if(set1[i] == set2[j]){
                found = 1;
                cout << set1[i] << " " ;
            }
        }
    }
    if(found == 0)
        cout << "The Sets are Disjoint" << endl;
    else
        cout << endl <<"The Sets aren't Disjoint!" << endl;
}

void Set_equality(int set1[] , int set2[] , int c1 , int c2){
    int found_element = 0;
    if(c1 != c2)
        cout << "The Sets aren't equal to each other!" << endl;
    else{
        for(int i = 0 ; i < c1 ; ++i){
            if(set1[i] != set2[i]){
                found_element = 1;
                cout << "The Sets aren't equal to each other!" << endl;
                break;
            }
        }
        if(found_element == 0)
            cout << "The Sets are equal ^_^" << endl;
    }
}

void proper_subset(int set1[] , int set2[] , int c1 , int c2 , int sub ){
        int counter = 0 ;
        for (int i = 0 ; i < c1 ; ++i){
            for(int j = 0 ; j < c2 ; ++j){
                if(set1[i] != set2[j]){
                    ++counter;
                }
                else if(set1[i] == set2[j])
                    break;
            }
            if(counter == c2){
                sub = 0 ;
                break;
            }
        }
        if(sub == 1)
            cout << "the First Set is Proper subset from the Second Set" << endl;
        else if (sub == 2)
            cout << "the Second Set is Proper subset from the First Set" << endl;
        else if (sub == 0)
            cout << "No Proper Subset!" << endl;
}

void proper_subset_assist(int set1[] , int set2[] , int c1 , int c2){
    int sub = 0;
    if(c1 == c2)
        cout << "No Subset" << endl;
    else if (c1 < c2){
        sub = 1;
        proper_subset(set1 , set2 , c1 ,c2 , sub);
    }
    else{
        sub = 2;
        proper_subset(set2 , set1 , c2 , c1 , sub);
    }
}
