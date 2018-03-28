#include <iostream>
#include <fstream>

using namespace std;

const int c_setSize = 10000;

int get_number(int, int);

void get_set(int[], int&);
void load_file(int[], int&);
void prepare_set(int[], int&);
void create_file(int[], int);

void print_set(const int[], int);

void set_union(int[], int[], int, int);
void set_intersection(int[], int[], int, int);
void set_difference(int[], int[], int, int);

void cartesian(int[], int[], int, int);
void power_set(int[], int);

void set_disjoint(int[], int[], int[], int, int, int);
bool set_disjoint_assist(int set1[] , int set2[] , int c1 , int c2);
void set_equality(int set1[], int set2[] , int set3[] , int c1, int c2 , int c3);
bool set_equality_assist(int set1[] , int set2[] , int set3[] , int c1 , int c2 , int c3,bool& found1,bool& found2,bool& found3);
bool set_equality_boolean(int set1[] , int set2[] , int c1 , int c2);
void proper_subset(int[], int[], int, int, int);
void proper_subset_assist(int[], int[], int, int);

int main()
{
	//The two sets are saved together in an array.
	//This will make it easier to convert the program to 3 sets.

	//to access set A use 'set[0]'. To access set B, use 'set[1]'
	int set[3][c_setSize];
	//to access size of set A use 'c[0]'. To access size of set B, use 'c[1]'
	int c[3] = { 0, 0 , 0};

	cout << "Ahlan ya user ya Habibi" << endl;
	cout << "what do you want to do today" << endl;
	while (true) {
		cout << "\n1 >> Enter a new data set" << endl;
		cout << "2 >> Load data set from file" << endl;
		cout << "3 >> Display current data set" << endl;
		cout << "4 >> Union of A and B" << endl;
		cout << "5 >> Intersection of A and B" << endl;
		cout << "6 >> Difference between A and B (A - B)" << endl;
		cout << "7 >> Difference between B and A (B - A)" << endl;
		cout << "8 >> Cartesian product of A and B" << endl;
		cout << "9 >> Power set of A" << endl;
		cout << "10 >> Check if A and B are disjoint" << endl;
		cout << "11 >> Check if A and B are equal" << endl;
		cout << "12 >> Check if a set is a proper subset of other" << endl;
		cout << "13 >> End" << endl;
		int k;
		int choose = get_number(1, 13);
		cout << endl;
		switch (choose) {
		case 1:  // >> Enter a new data set
			cout << "Which set do you want to modify (1-3): ";
			k = get_number(1, 3) - 1;
			get_set(set[k], c[k]);
			create_file(set[k], c[k]);
			break;
		case 2:  // >> Load data set from file
			cout << "Which set do you want to modify (1-3): ";
			k = get_number(1, 3) - 1;
			load_file(set[k], c[k]);

			break;
		case 3:  // >> Display current data set
			cout << "Set A:\n";
			print_set(set[0], c[0]);
			cout << "Set B:\n";
			print_set(set[1], c[1]);
			cout << "Ser C:\n";
			print_set(set[2], c[2]);
			break;
		case 4:  // >> Union of A and B
			set_union(set[0], set[1], c[0], c[1]);
			break;
		case 5:  // >> Intersection of A and B
			set_intersection(set[0], set[1], c[0], c[1]);
			break;
		case 6:  // >> Difference between A and B (A - B)
			set_difference(set[0], set[1], c[0], c[1]);
			break;
		case 7:  // >> Difference between B and A (B - A)
			set_difference(set[1], set[0], c[1], c[0]);
			break;
		case 8:
			cartesian(set[0], set[1], c[0], c[1]);
			break;
		case 9:
			power_set(set[0], c[0]);
			break;
		case 10: // >> Check if A and B are disjoint
			set_disjoint(set[0], set[1], set[2], c[0], c[1], c[2]);
			break;
		case 11: // >> Check if A and B are equal
			set_equality(set[0], set[1], set[2], c[0], c[1], c[2]);
			break;
		case 12: // >> Check if a set is a proper subset of other
			proper_subset_assist(set[0], set[1], c[0], c[1]);
			break;
		case 13: // >> End
			return 0;
		}
	}
}

int get_number(int begin, int end) {
	int answer;
	while (true) {
		cin >> answer;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "Invalid input.\n";
		}
		else if (answer < begin || answer > end) {
			cout << "Input out of range (" << begin << "-" << end << ")\n";
		}
		else {
			cin.ignore(INT_MAX, '\n');
			break;
		}
	}
	return answer;
}

void get_set(int set[], int &c) {
	cout << "Enter the data set (seperate numbers by spaces, press Enter after you are done):" << endl;
	c = 0;
	while (true) {
		cin >> set[c++];
		if (cin.get() == '\n' || c == c_setSize)
			break;
	}
	prepare_set(set, c);
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
	while (file >> current && !file.eof() && c < c_setSize) {
		set[c++] = current;
	}
	prepare_set(set, c);
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
		set[min] = temp;            //swap
	}
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

void print_set(const int set[], int c) {
	cout << "{";
	for (int i = 0; i < c; ++i) {
		cout << set[i];
		if (i != c - 1)
			cout << ", ";
	}
	cout << "}" << endl;
}

/*--------------------------------------------------------------------------------------
Ahmed Dardery
* Union of A, B                 (A U B)
* Intersection of A, B          (A ∩ B)
* Difference between A and B    (A - B)
--------------------------------------------------------------------------------------*/
void set_union(int set1[], int set2[], int c1, int c2) {
	int unionSet[c_setSize];
	int c = 0;
	int i = 0, j = 0;
	while (i < c1 && j < c2) {
		if (set1[i] < set2[j])
			unionSet[c++] = set1[i++];

		else if (set1[i] > set2[j])
			unionSet[c++] = set2[j++];

		else {
			unionSet[c++] = set1[i];
			++i, ++j;
		}
	}
	for (; i < c1; ++i) unionSet[c++] = set1[i];
	for (; j < c2; ++j) unionSet[c++] = set2[j];
	print_set(unionSet, c);
}

void set_intersection(int set1[], int set2[], int c1, int c2) {
	int intersectionSet[c_setSize];
	int c = 0;
	int i = 0, j = 0;
	while (i < c1 && j < c2) {
		if (set1[i] < set2[j])
			++i;
		else if (set1[i] > set2[j])
			++j;
		else {
			intersectionSet[c++] = set1[i];
			++i, ++j;
		}
	}
	print_set(intersectionSet, c);
}

void set_difference(int set1[], int set2[], int c1, int c2) {
	int diffSet[c_setSize];
	int c = 0;
	int i = 0, j = 0;
	while (i < c1 && j < c2) {
		if (set1[i] < set2[j])
			diffSet[c++] = set1[i++];
		else if (set1[i] > set2[j])
			++j;
		else
			++i, ++j;
	}
	for (; i < c1; ++i) diffSet[c++] = set1[i];
	print_set(diffSet, c);
}

/*--------------------------------------------------------------------------------------
Belal Hamdy
* Difference between B and A        (B - A)
* Cartesian product of A and B
* Power set of A
--------------------------------------------------------------------------------------*/

void cartesian(int set1[], int set2[], int siz1, int siz2)
{
	cout << '{';
	for (int i = 0; i<siz1; ++i)
	{
		for (int j = 0; j<siz2; ++j)
		{
			cout << '(' << set1[i] << ", " << set2[j] << ')';
			if (i < siz1 - 1 || j < siz2 - 1)
				cout << ", ";
		}
	}
	cout << '}';

}
void power_set(int set[], int siz)
{
	int pattern;
	if (siz >= 21)
		cout << "The power set will exceed million sets!!\n";
	else
	{
		cout << '{';
		int totalCount = 1 << siz;
		for (int i = 0; i < totalCount; i++)
		{
			pattern = i;
			cout << '{';
			for (int j = 0; pattern != 0 ; j++)
			{
				if (pattern & 1) {
					cout << set[j];
					if (pattern != 1)
						cout << ", ";
				}
				pattern >>= 1;

			}
			cout << '}';
			if (i < totalCount - 1)
				cout << ", ";
		}
		cout << '}';
	}
}


/*--------------------------------------------------------------------------------------
Adham Mamdouh
* Check if A and B are disjoint                 (A ∩ B = {})
* Check if A and B are equal                    (A = B)
* Check if a set is a proper subset of other    (A ⊂ B or B ⊂ A)
--------------------------------------------------------------------------------------*/
void set_disjoint(int set1[], int set2[], int set3[] , int c1, int c2 , int c3) {
	bool found1 = set_disjoint_assist(set1 , set2 , c1 , c2);
	bool found2 = set_disjoint_assist(set2 , set3 , c2 , c3);
	bool found3 = set_disjoint_assist(set1 , set3 , c1 , c3);
	if(found1 == true && found2 == true && found3 == true)
        cout << "the sets disjoint from each other" << endl;
    else if (found1 == false && found2 == false && found3 == false)
        cout << "the sets are joint" << endl;
    else {
        if (found1 == true)
            cout << "the first set disjoint form the second set" << endl;
        if (found2 == true)
            cout << "the second set disjoint from the third set" << endl;
        if (found3 == true)
            cout << "the third set disjoint from the first set" << endl;
    }
}

bool set_disjoint_assist(int set1[] , int set2[] , int c1 , int c2){
    for(int i = 0 ; i < c1 ; ++i){
        for(int j = 0 ; j < c2 ; ++j){
            if(set1[i] == set2[j]){
                return false;
            }
        }
    }
    return true;
}

void set_equality(int set1[], int set2[] , int set3[] , int c1, int c2 , int c3) {
    bool found1 ;
	bool found2 ;
	bool found3 ;
	if(set_equality_assist(set1 , set2 , set3 , c1 , c2 , c3 , found1 , found2 , found3)){
        if(found1 == true && found2 == true && found3 == true)
            cout << "the sets are equal to each other" << endl;
        else if (found1 == false && found2 == false && found3 == false)
            cout << "the sets are not equal" << endl;
        else {
            if (found1 == true)
                cout << "the first set equal to the second set" << endl;
            if (found2 == true)
                cout << "the second set equal to the third set" << endl;
            if (found3 == true)
                cout << "the third set equal to the first set" << endl;
        }
	}
}

bool set_equality_assist(int set1[] , int set2[] , int set3[] , int c1 , int c2 , int c3,bool& found1,bool& found2,bool& found3){
    if (c1 != c2 && c1 != c3){
		cout << "The Sets aren't equal to each other!" << endl;
		return false;
		}
    else {
        if (c1 < c2)
            found1 = set_equality_boolean(set1 , set2 , c1 , c2);
        else if (c1 > c2)
            found1 = set_equality_boolean(set2 , set1 , c2 , c1);
        if(c2 < c3)
            found2 = set_equality_boolean(set2 , set3 , c2 , c3);
        else if(c2 > c3)
            found2 = set_equality_boolean(set3 , set2 , c3 , c2);
        if(c1 < c3)
            found3 = set_equality_boolean(set1 , set3 , c1 , c3);
        else if(c1 > c3)
            found3 = set_equality_boolean(set3 , set1 , c3 , c1);
        return true;
        }
}

bool set_equality_boolean(int set1[] , int set2[] , int c1 , int c2){
    for (int i = 0 ; i < c1 ; ++i){
        if(set1[i] != set2[i])
            return false;
    }
    return true;
}
void proper_subset(int set1[], int set2[], int c1, int c2, int sub) {
	int counter = 0;
	for (int i = 0; i < c1; ++i) {
		for (int j = 0; j < c2; ++j) {
			if (set1[i] != set2[j]) {
				++counter;
			}
			else if (set1[i] == set2[j])
				break;
		}
		if (counter == c2) {
			sub = 0;
			break;
		}
		counter = 0;
	}
	if (sub == 1)
		cout << "the First Set is Proper subset from the Second Set" << endl;
	else if (sub == 2)
		cout << "the Second Set is Proper subset from the First Set" << endl;
	else if (sub == 0)
		cout << "No Proper Subset!" << endl;
}

void proper_subset_assist(int set1[], int set2[], int c1, int c2) {
	int sub = 0;
	if (c1 == c2)
		cout << "No Proper Subset" << endl;
	else if (c1 < c2) {
		sub = 1;
		proper_subset(set1, set2, c1, c2, sub);
	}
	else {
		sub = 2;
		proper_subset(set2, set1, c2, c1, sub);
	}
}
