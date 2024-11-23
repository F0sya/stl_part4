#include <iostream>
#include <map>
#include <Windows.h>
#include <vector>
#include <string>

using namespace std;



void print(string name, vector<string> numbers) {
	cout << "	Назва:" << name << endl;
	cout << "	Студенти:";
	for (int i = 0; i < numbers.size(); i++) {
		cout << numbers[i] << ";";
	}
	cout << endl;
}


int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int choice;
	string group;
	double sum = 0;
	string name;
	vector<string> names;

	map<string, vector<string>> mp;


	while (true) {
		cout << "\n----------MENU------------\n";
		cout << "1.Create group" << endl;
		cout << "2.Add new student to group" << endl;
		cout << "3.Remove student from group" << endl;
		cout << "4.Print" << endl;
		cout << "5.Exit" << endl;
		cout << "\n----------MENU------------\n";

		cin >> choice;

		cin.ignore();

		switch (choice) {


		case 1:
			cout << "Назва групи: "; getline(cin, group);
			cout << "Імена студентів: ";
			while (true) {
				getline(cin, name);
				if (name == "") {
					break;
				}
				names.push_back(name);
			}

			mp.insert({group,names});

			print(group, names);
			break;
		case 2: {
			cout << "Назва групи до якої хочете додати:"; getline(cin, group);
			vector<string> arr;
			if (mp.find(group) != mp.end()) {
				cout << "Ім'я нового студента: "; getline(cin, name);
				arr = mp.find(group)->second;
				arr.push_back(name);
				mp[group] = arr;
				print(group, arr);
			}
			else {
				cout << "Шукана група не знайдена " << endl;
			}
			break;
		}
		case 3: {
			cout << "Назва групи з якої хочете видалити:"; getline(cin, group);
			vector<string> arr;
			vector<string> new_arr;
			if (mp.find(group) != mp.end()) {
				cout << "Ім'я  студента: "; getline(cin, name);
				arr = mp.find(group)->second;
				for (int i = 0; i < arr.size(); i++) {
					if (arr[i] != name) {
						new_arr.push_back(arr[i]);
					}
				}
				mp[group] = new_arr;
				print(group, new_arr);
			}
			else {
				cout << "Шукана група не знайдена " << endl;
			}
			break;
		}
		case 4: {
			for (auto i : mp) {
				cout << "Група " << i.first << ": ";
				for (int k = 0; k < i.second.size(); k++) {
					cout << i.second[k] << ";";
				}
			}
			break;
		}
		case 5:
			exit(0);
		}
	}


	return 0;
}