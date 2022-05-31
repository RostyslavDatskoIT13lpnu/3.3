#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

struct Goods
{
	string name;
	int amount;
	int pack;
	double cost;
};

void print(Goods* g, int n);			//вивід масиву
void create(Goods*& g, int n);			//ввід масиву
void sort_name(Goods* g, int n);		//сортування за ім'ям
void sort_cost(Goods* g, int n);		//сортування за ціною
void search_cost(Goods* g, int n, double roo);		//пошук за ціною
void search_name(Goods* g, int n, string name);		//пошук за ім'ям
void save(Goods* g, int n);				//зберегти у файл
void load(Goods*& g, int& n);				//завантажити з файлу
bool check(string s, string s1);		//перевірка на алфавітну розбіжність
int menu();
bool menu_check(int a);
void search_cost_diapason(Goods* g, int n, double min, double max);  //пошук у діапазоні цін

int main() {
	Goods* g;
	int n = 1;
	string str;
	char* name = new char[100];
	int cont;
	int cc;
	double min;
	double max;
	g = new Goods[n];

	do {
		do {
			cont = menu();
		} while (!menu_check(cont));
		switch (cont)
		{
		case 1:
			print(g, n);
			break;
		case 2:
			cout << "Enter n: "; cin >> n;
			g = new Goods[n];
			create(g, n);
			break;
		case 3:
			sort_name(g, n);
			print(g, n);
			break;
		case 4:
			sort_cost(g, n);
			print(g, n);
			break;
		case 5:
			cout << "Enter name: "; cin >> str;
			search_name(g, n, str);
			break;
		case 6:
			cout << "Enter cost: "; cin >> cc;
			search_cost(g, n, cc);
			break;
		case 7:
			load(g, n);
			break;
		case 8:
			save(g, n);
			break;
		case 9:
			cout << "Enter min: "; cin >> min;
			cout << "Enter max: "; cin >> max;

			search_cost_diapason(g, n, min, max);
			break;
		default:
			break;
		}

	} while (cont != 0);
}

void print(Goods* g, int n) {			//вивід масиву

	cout << "------------------------------------------------------------" << endl;
	cout << "| N |    name    |     amount    |    pack    |    cost    |" << endl;
	cout << "------------------------------------------------------------" << endl;

	for (int i = 0; i < n; i++) {
		cout << "|" << setw(3) << i + 1 << "|"
			<< setw(12) << g[i].name << "|"
			<< setw(15) << g[i].amount << "|"
			<< setw(12) << g[i].pack << "|"
			<< setw(12) << g[i].cost << "|" << endl;
	}
	cout << "------------------------------------------------------------" << endl;
}
void create(Goods*& g, int n) {			//ввід масиву
	for (int i = 0; i < n; i++) {
		cout << "Good " << i + 1 << endl;
		cout << "Name: "; cin >> g[i].name;
		cout << "Amount: "; cin >> g[i].amount;
		cout << "Pack: "; cin >> g[i].pack;
		cout << "Cost: "; cin >> g[i].cost;
	}

}
void sort_name(Goods* g, int n) {		//сортування за ім'ям
	Goods tmp;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (check(g[i].name, g[j].name)) {
				tmp = g[i];
				g[i] = g[j];
				g[j] = tmp;
			}
		}
	}
}
void sort_cost(Goods* g, int n) {		//сортування за ціною
	Goods tmp;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (g[i].cost < g[j].cost) {
				tmp = g[i];
				g[i] = g[j];
				g[j] = tmp;
			}
		}
	}
}
void search_cost(Goods* g, int n, double roo) {		//пошук за ціною

	cout << "------------------------------------------------------------" << endl;
	cout << "| N |    name    |     amount    |    pack    |    cost    |" << endl;
	cout << "------------------------------------------------------------" << endl;
	for (int i = 0; i < n; i++) {
		if (g[i].cost == roo) {


			cout << "|" << setw(3) << i + 1 << "|"
				<< setw(12) << g[i].name << "|"
				<< setw(15) << g[i].amount << "|"
				<< setw(12) << g[i].pack << "|"
				<< setw(12) << g[i].cost << "|" << endl;

		}
	}
	cout << "------------------------------------------------------------" << endl;
}
void search_name(Goods* g, int n, string name) {		//пошук за ім'ям
	cout << "------------------------------------------------------------" << endl;
	cout << "| N |    name    |     amount    |    pack    |    cost    |" << endl;
	cout << "------------------------------------------------------------" << endl;
	for (int i = 0; i < n; i++) {
		if (g[i].name == name) {


			cout << "|" << setw(3) << i + 1 << "|"
				<< setw(12) << g[i].name << "|"
				<< setw(15) << g[i].amount << "|"
				<< setw(12) << g[i].pack << "|"
				<< setw(12) << g[i].cost << "|" << endl;

		}
	}
	cout << "------------------------------------------------------------" << endl;


}
void save(Goods* g, int n) {				//зберегти у файл
	fstream fout("file.txt");
	fout << n << endl;
	for (int i = 0; i < n; i++) {
		fout << g[i].name << endl;
		fout << g[i].amount << endl;
		fout << g[i].pack << endl;
		fout << g[i].cost << endl;
	}
}

void load(Goods*& g, int& n) {				//завантажити з файлу
	fstream fin("file.txt");
	fin >> n;
	g = new Goods[n];
	for (int i = 0; i < n; i++) {
		fin >> g[i].name;
		fin >> g[i].amount;
		fin >> g[i].pack;
		fin >> g[i].cost;
	}
}
bool check(string s, string s1) {
	char d[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G',
				 'H', 'I', 'J', 'K', 'L', 'M', 'N',
				 'O', 'P', 'Q', 'R', 'S', 'T', 'U',
				 'V', 'W', 'X', 'Y', 'Z' };
	int a1;
	int a2;
	for (int i = 0; i < 26; i++) {
		if (d[i] == s[0]) {
			a1 = i;
			break;
		}
	}
	for (int i = 0; i < 26; i++) {
		if (d[i] == s1[0]) {
			a2 = i;
			break;
		}
	}
	if (a2 < a1) {
		return true;
	}
}
int menu() {
	int d;
	cout << "Print(1)\nEnter(2)\nSort name(3)\nSort cost(4)\nFind name(5)\nFind cost(6)\nLoad file(7)\nSave file(8)\nFind cost diapason(9)\nExit(0)\n";
	cin >> d;
	return d;
}

bool menu_check(int a) {
	if (a < 0 || a > 9) {
		return false;
	}
	else {
		return true;
	}
}

void search_cost_diapason(Goods* g, int n, double min, double max) {
	cout << "------------------------------------------------------------" << endl;
	cout << "| N |    name    |     amount    |    pack    |    cost    |" << endl;
	cout << "------------------------------------------------------------" << endl;
	for (int i = 0; i < n; i++) {
		if (g[i].cost > min && g[i].cost < max) {


			cout << "|" << setw(3) << i + 1 << "|"
				<< setw(12) << g[i].name << "|"
				<< setw(15) << g[i].amount << "|"
				<< setw(12) << g[i].pack << "|"
				<< setw(12) << g[i].cost << "|" << endl;

		}
	}
	cout << "------------------------------------------------------------" << endl;
}
