#include <iostream>
#include <fstream>

using namespace std;

void get_set(int[], int&);
void print_set(const int[], int);
void create_file(int[], int);
void load_file(int[], int&);
void prepare_set(int[], int&);

int main()
{
	int choose;
	int set[10000];
	int c = 0;
	cout << "1 >> Create File" << endl;
	cout << "2 >> Load File" << endl;
	cin >> choose;
	cin.ignore(INT_MAX, '\n');
	if (choose == 1) {
		get_set(set, c);
		prepare_set(set, c);
		//create_file(set,c);
		cout << endl;
		print_set(set, c);
	}
	else if (choose == 2) {
		load_file(set, c);
		prepare_set(set, c);
		print_set(set, c);
	}
	/*get_set(set, c);
	cout << endl;
	print_set(set,c);*/
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
