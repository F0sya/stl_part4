#include <iostream>
#include <map>
#include <Windows.h>
#include <vector>
#include <string>

using namespace std;

double average_num(vector<int> numbers) {
	double sum = 0;
	for (int i = 0; i < numbers.size(); i++) {
		sum += numbers[i];
	}
	return sum / numbers.size();
}

void print(string name, vector<string> numbers) {
	cout << "	Назва:" << name << endl;
	cout << "	Автор:";
	for (int i = 0; i < numbers.size(); i++) {
		cout << numbers[i] << " ";
	}
	cout << endl;
}


int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int choice;
	string author;
	double sum = 0;
	string name;
	vector<string> authors;

	map<string, vector<string>> lib;


	while (true) {
		cout << "\n----------MENU------------\n";
		cout << "1.Add new book" << endl;
		cout << "2.Find book by name" << endl;
		cout << "3.Print lib" << endl;
		cout << "4.Exit" << endl;
		cout << "\n----------MENU------------\n";

		cin >> choice;

		cin.ignore();

		switch (choice) {


		case 1:
			cout << "Введіть назву книги: ";
			getline(cin, name);
			cout << "Введіть авторів(через кому): ";

			while (cin >> author) {
				authors.push_back(author);
				if (cin.get() == '\n') {
					break;
				}
			}
			cout << "Додано книгу:" << endl;
			print(name,authors);

			lib.insert({name,authors});
			authors.clear();
			break;
		case 2: {
			string found_key;
			cout << "Введіть назву книги:"; getline(cin, found_key);


			cout << "Результат:" << endl;
			for (auto i : lib) {
				if(lib.find(found_key) != lib.end()){
					print(i.first, i.second);
				}
			}

			break;
		}
		case 3: {
			cout << "Бібліотека:" << endl;
			int k = 0;
			for (auto i : lib) {
				k++;
				cout << k << ")";
				print(i.first, i.second);
			}
			break;
		}
		case 4:
			exit(0);
		}
	}


	return 0;
}