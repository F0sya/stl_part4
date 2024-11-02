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

void print(string name, vector<int> numbers) {
	cout << "	Ім'я:" << name << endl;
	cout << "	Результати:";
	for (int i = 0; i < numbers.size(); i++) {
		cout << numbers[i] << " ";
	}
	cout << endl;
}


int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int choice;
	int num;
	double sum = 0;
	string name;
	vector<int> numbers;

	map<string, vector<int>> students;

	
	while (true) {
		cout << "\n----------MENU------------\n";
		cout << "1.Add to map new student" << endl;
		cout << "2.Add new mark to a student" << endl;
		cout << "3.Print average mark of student" << endl;
		cout << "4.Exit" << endl;
		cout << "\n----------MENU------------\n";
		
		cin >> choice;

		cin.ignore();

		switch (choice) {

		case 1:
			cout << "Введіть ім'я: ";
			getline(cin, name);
			cout << "Введіть оцінки (через пробіл): ";

			while (cin >> num) {
				numbers.push_back(num);
				if (cin.get() == '\n') {
					break;
				}
			}
			cout << "Додано студента:" << endl;
			print(name, numbers);

			students.insert({ name,numbers });
			break;
		case 2: {
			string found_name;
			int new_mark;
			vector<int> arr;
			cout << "Enter a name:"; getline(cin, found_name);
			if (students.find(found_name) != students.end()) {
				cout << "Enter a new mark:"; cin >> new_mark;
				arr = students.find(found_name)->second;
				arr.push_back(new_mark);
				students[found_name] = arr;
				print(found_name, arr);
			}
			else {
				cout << "No occurencies" << endl;
			}
			break;
			}
		case 3: {
			string found_name;
			vector<int> arr;
			cout << "Enter a name:";
			getline(cin, found_name);
			if (students.find(found_name) != students.end()) {
				cout << name << " : середній бал = " << average_num(students.find(found_name)->second);
			}
			else {
				cout << "No occurencies" << endl;
			}
			break;
			}
		case 4:
			exit(0);
		}
	}


	return 0;
}