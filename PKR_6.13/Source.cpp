#include <iostream>
#include <string>

using namespace std;

struct Student {
	string name;
	string I1;
	string I2;
	int fis;
	int oop;
	int pkr;
	int ukr;
	int ang;
};

struct Node
{
	int n;
	Node** link;
	Student* student;
};

int menu();
bool menu_check(int a);
void create(Node*& root);
void create_w(Node*& root);
void print(Node* root);
void print_w(Node* root);
void print_all_5(Node* root);
void print_if_3(Node* root);
bool check_1(Node* root);
bool check_2(Node* root);
bool check_3(Node* root);
void dell_2(Node*& root);
void del_brunch(Node*& root, int n);
void clean(Node*& a);

int main() {
	Node* a = new Node;
	int con;
	int v;
	do {
		con = menu();
		switch (con)
		{
		case 1:
			create(a);
			break;
		case 2:
			print(a);
			break;
		case 3:
			print_all_5(a);
			break;
		case 4:
			print_if_3(a);
			break;
		case 5:
			dell_2(a);
			print(a); 
			break;
		case 6:
			cout << "Num: "; cin >> v;
			del_brunch(a,v-1);
			print(a);
			break;
		default:
			break;
		}
	} while (con != 0);
	clean(a);
}


void create(Node*& root) {
	cout << "Enter amount: "; cin >> root->n;
	root->link = new Node*[root->n];
	root->student = NULL;
	for (int i = 0; i < root->n; i++) {
		root->link[i] = new Node;
		create_w(root->link[i]);
	}
	cout << endl;
}

void create_w(Node*& root) {
	root->student = new Student;
	root->link = NULL;
	cout << "Enter name "; cin >> root->student->name;
	cout << "Enter I1 "; cin >> root->student->I1;
	cout << "Enter I2 "; cin >> root->student->I2;

	cout << "Enter fis "; cin >> root->student->fis;
	cout << "Enter oop "; cin >> root->student->oop;
	cout << "Enter pkr "; cin >> root->student->pkr;
	cout << "Enter ukr "; cin >> root->student->ukr;
	cout << "Enter ang "; cin >> root->student->ang;
	
}

void print(Node* root) {
	for (int i = 0; i < root->n; i++) {
		print_w(root->link[i]);
	}
	cout << endl;
}


void print_w(Node* root) {
	Student* s = root->student;
	cout << s->name << " " << s->I1 << ". " << s->I2 << ". :"
		<< s->fis << " "
		<< s->oop << " "
		<< s->pkr << " "
		<< s->ukr << " "
		<< s->ang << " " << endl ;
}

void print_all_5(Node* root)
{
	for (int i = 0; i < root->n; i++) {
		if (check_1(root->link[i])) {
			print_w(root->link[i]);
		}
	}
	cout << endl;
}

void print_if_3(Node* root)
{
	for (int i = 0; i < root->n; i++) {
		if (check_2(root->link[i])) {
			print_w(root->link[i]);
		}
	}
	cout << endl;
}

bool check_1(Node* root)
{
	Student* s = root->student;
	if (s->fis == 5 && s->ang == 5 && s->oop == 5 && s->pkr == 5 && s->ukr == 5) {
		return true;
	}
	else {
		return false;
	}
}

bool check_2(Node* root)
{
	Student* s = root->student;
	if (s->fis == 3 || s->ang == 3 || s->oop == 3 || s->pkr == 3 || s->ukr == 3) {
		return true;
	}
	else {
		return false;
	}
}

bool check_3(Node* root)
{
	Student* s = root->student;
	int k = 0;
	if (s->fis == 2) {
		k++;
	}
	if (s->oop == 2) {
		k++;
	}
	if (s->pkr == 2) {
		k++;
	}
	if (s->ukr == 2) {
		k++;
	}
	if (s->ang == 2) {
		k++;
	}
	if (k >= 2) {
		return true;
	}
	else
	{
		return false;
	}
}

void dell_2(Node*& root)
{
	for (int i = 0; i < root->n; i++) {
		if (check_3(root->link[i])) {
			del_brunch(root, i);
		}
	}
}

void del_brunch(Node*& root, int n)
{
	delete root->link[n]->student;
	for (int j = n; j < root->n -1; j++) {
		root->link[j] = root->link[j + 1];
	}
	root->n -= 1;
}


int menu() {
	int c;
	do {
		cout << "Choose:\n Enter tree(1)\n Print tree(2)\n Print tree with all 5(3)\n"
			<< " Print tree with 3(4)\n delete brunch with 2(5)\n delete brunch(6)\n Exit(0)" << endl;
		cin >> c;
	} while (menu_check(c));
	return c;
}

bool menu_check(int a) {
	if (a < 0 || a >6) {
		return true;
	}
	else {
		return false;
	}
}

void clean(Node*& a) {
	for (int i = 0; i < a->n; i++) {
		delete a->link[i]->student;
		delete a->link[i];
	}
	delete a->link;
	delete a;
}