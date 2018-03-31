#include <iostream>
#include <fstream>

using namespace std;

const int c_setSize = 10000;

int get_number(int, int );

const int min(const int& a, const int& b) { return !(b<a) ? a : b; }

void get_set(int[], int&);
void load_file(int[], int&);
void prepare_set(int[], int&);
void create_file(int[], int);

void print_set(const int[], int);

void set_union(int[], int[], int[], int, int, int);
void set_intersection(int[], int[], int[], int, int, int);
void set_difference(int[], int[], int[], int, int, int);

void cartesian(int[], int[] ,int[],int, int, int);
void power_set(int[], int);

void set_disjoint(int[], int[], int[], int, int, int);
bool set_disjoint_assist(int[], int[], int, int);
bool set_equality(int[], int[] , int[] , int, int, int);
bool set_equality_boolean(int[], int[], int, int);
int proper_subset(int[], int[], int[],int , int, int);
bool proper_subset_assist(int[], int[], int, int);

int main()
{
	//The two sets are saved together in an array.
	//This will make it easier to convert the program to 3 sets.

	//to access set A use 'set[0]'. To access set B, use 'set[1]'
	int set[3][c_setSize];
	//to access size of set A use 'c[0]'. To access size of set B, use 'c[1]'
	int c[3] = { 0, 0, 0 };

	cout << "Ahlan ya user ya Habibi" << endl;
	cout << "what do you want to do today" << endl;
	while (true) {
		cout << "\n1 >> Enter a new data set" << endl;
		cout << "2 >> Load data set from file" << endl;
		cout << "3 >> Display current data set" << endl;
		cout << "4 >> Union of A, B and C" << endl;
		cout << "5 >> Intersection of A, B and C" << endl;
		cout << "6 >> Difference between A and (B and C) (A - B - C)" << endl;
		cout << "7 >> Difference between B and (A and C) (B - A - C)" << endl;
		cout << "8 >> Cartesian product of A, B and C" << endl;
		cout << "9 >> Power set of A" << endl;
		cout << "10 >> Check if A, B and C are disjoint" << endl;
		cout << "11 >> Check if A, B and C are equal" << endl;
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
			if (c[k] > 0) create_file(set[k], c[k]);
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
			cout << "Set C:\n";
			print_set(set[2], c[2]);
			break;
		case 4:  // >> Union of A, B and C
			set_union(set[0], set[1], set[2], c[0], c[1], c[2]);
			break;
		case 5:  // >> Intersection of A, B and C
			set_intersection(set[0], set[1], set[2], c[0], c[1], c[2]);
			break;
		case 6:  // >> Difference between A and (B and C) (A - B - C)
			set_difference(set[0], set[1], set[2], c[0], c[1], c[2]);
			break;
		case 7:  // >> Difference between B and (A and C) (B - A - C)
			set_difference(set[1], set[0], set[2], c[1], c[0], c[2]);
			break;
		case 8: // >> Cartesian product of A, B and C
			cartesian(set[0], set[1], set[2], c[0], c[1], c[2]);
			break;
		case 9: // >> Power set of A
			power_set(set[0], c[0]);
			break;
		case 10: // >> Check if A, B and C are disjoint
			set_disjoint(set[0], set[1], set[2], c[0], c[1], c[2]);
			break;
		case 11: // >> Check if A, B and C are equal
			set_equality(set[0], set[1], set[2], c[0], c[1], c[2]);
			break;
		case 12: // >> Check if a set is a proper subset of other
			proper_subset(set[0], set[1], set[2], c[0], c[1], c[2]);
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
	while (c < c_setSize) {
		cin >> set[c++];
		if (cin.fail()) {
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			c = 0;
			cout << "Invalid number encountered! Operation failed." << endl;
			return;
		}
		if (cin.get() == '\n' || cin.peek() == '\n' && cin.get())
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
		if (!path[0]) {
			cout << "Operation cancelled!\n";
			return;
		}
		file.open(path);
		if (!file)
			cout << "Couldn't access the file.\n";
		else
			break;
	}

	int current;
	c = 0;
	while (c < c_setSize) {
		if (file >> current)
			set[c++] = current;
		else if (!file.eof()) {
			c = 0;
			file.close();
			cout << "Invalid number encountered! Operation failed.";
			return;
		}
		else
			break;
	}

	file.close();
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
		if (!path[0]) {
			cout << "Operation cancelled!\n";
			return;
		}
		file.open(path);
		if (!file)
			cout << "Couldn't access the file.\n";
		else
			break;
	}

	for (int i = 0; i < c; ++i) {
		file << set[i] << " ";
	}
	file.close();
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
void set_union(int set1[], int set2[], int set3[], int c1, int c2, int c3) {
	int unionSet[c_setSize];
	int c = 0;
	int i = 0, j = 0, k = 0;

	set1[c1] = INT_MAX;
	set2[c2] = INT_MAX;
	set3[c3] = INT_MAX;
	while (i < c1 || j < c2 || k < c3) {
		int minimum = min(min(set1[i], set2[j]), set3[k]);
		if (set1[i] == minimum) ++i;
		if (set2[j] == minimum) ++j;
		if (set3[k] == minimum) ++k;
		unionSet[c++] = minimum;
	}
	print_set(unionSet, c);
}

void set_intersection(int set1[], int set2[], int set3[], int c1, int c2, int c3) {
	int intersectionSet[c_setSize];
	int c = 0;
	int i = 0, j = 0, k = 0;

	set1[c1] = INT_MAX;
	set2[c2] = INT_MAX;
	set3[c3] = INT_MAX;
	while (i < c1 || j < c2 || k < c3) {
		int minimum = min(min(set1[i], set2[j]), set3[k]);
		if (set1[i] == set2[j] && set2[j] == set3[k]) intersectionSet[c++] = minimum;
		if (set1[i] == minimum) ++i;
		if (set2[j] == minimum) ++j;
		if (set3[k] == minimum) ++k;

	}
	print_set(intersectionSet, c);
}

void set_difference(int set1[], int set2[], int set3[], int c1, int c2, int c3) {
	int diffSet[c_setSize];
	int c = 0;
	int i = 0, j = 0, k = 0;

	set1[c1] = INT_MAX;
	set2[c2] = INT_MAX;
	set3[c3] = INT_MAX;
	while (i < c1 && (j < c2 || k < c3) ) {
		int minimum = min(min(set1[i], set2[j]), set3[k]);
		bool equal = set2[j] == set1[i] || set3[k] == set1[i];
		if (set2[j] == minimum) {
			++j;
		}
		if (set3[k] == minimum) {
			++k;
		}
		if (set1[i] == minimum && !equal) {
			diffSet[c++] = set1[i++];
		}
		else if (equal) ++i;
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

void cartesian(int set1[], int set2[], int set3[], int siz1, int siz2, int siz3)
{
	cout << '{';
	for (int i = 0; i<siz1; ++i)
	{
		for (int j = 0; j<siz2; ++j)
		{
			for (int k = 0; k<siz3; ++k)
			{

				cout << '(' << set1[i] << ", " << set2[j] << ", " << set3[k] << ')';
				if (i < siz1 - 1 || j < siz2 - 1 || k<siz3 - 1)
					cout << ", ";
			}
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
			for (int j = 0; pattern != 0; j++)
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
    for(unsigned int i = 0 ; i < c1 ; ++i){
        for(unsigned int j = 0 ; j < c2 ; ++j){
            if(set1[i] == set2[j]){
                return false;
            }
        }
    }
    return true;
}

bool set_equality(int set1[], int set2[] , int set3[] , int c1, int c2 , int c3) {
    if (c1 != c2 && c2 != c3 && c1 != c3){
		cout << "The Sets aren't equal to each other!" << endl;
		return false;
		}
    bool found1 = set_equality_boolean(set1 , set2 , c1 ,c2);
	bool found2 = set_equality_boolean(set2 , set3 , c2 ,c3);
	bool found3 = set_equality_boolean(set3 , set1 , c3 ,c1);
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
    return true;
}

bool set_equality_boolean(int set1[] , int set2[] , int c1 , int c2){
    int foundElement = 0;
    for (unsigned int i = 0 ; i < c1 ; ++i){
        for (unsigned int j = 0 ; j < c2 ; ++j){
            if(set1[i] == set2[j]){
                foundElement += 1 ;
                break;
            }
        }
    }
    if(foundElement == c1)
        return true;
    else
        return false;
}
int proper_subset(int set1[], int set2[], int set3[],int c1, int c2, int c3) {
	if(c1 == c2 && c2 == c3){
        cout << "No Proper Subset! the sets are equal" << endl;
        return 0;
	}
	if (c1 < c2 && proper_subset_assist(set1 , set2 , c1 ,c2))
            cout << "the First Set is Proper Subset from the Second Set" << endl;

    else if(proper_subset_assist(set2 , set1 , c2 , c1))
            cout << "the second set is Proper Subset from the first set" << endl;

    if (c2 < c3 && proper_subset_assist(set2 , set3 , c2 , c3))
            cout << "the Second Set is Proper Subset from the third Set" << endl;

    else if(proper_subset_assist(set3 , set2 , c3 , c2))
            cout << "the third set is Proper Subset from the second set" << endl;

    if (c3 < c1 && proper_subset_assist(set3 , set1 , c3 , c1))
            cout << "the third set is Proper Subset from the first Set" << endl;

    else if(proper_subset_assist(set1 , set3 , c1 , c3))
            cout << "the first set is Proper Subset from the third Set" << endl;
    return 0;
}

bool proper_subset_assist(int set1[], int set2[], int c1, int c2) {
    int counter = 0 ;
    for (int i = 0 ; i < c1 ; ++i){
        for(int j = 0 ; j < c2 ; ++j){
            if(set1[i] != set2[j])
                ++counter;
            else if (set1[i] == set2[j]){
                break;
            }
        }
        if(counter == c2){
            return false;
        }
        counter = 0;
    }
    return true;
}
