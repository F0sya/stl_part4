#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include <locale>
#include <Windows.h>
using namespace std; 

void print(map<string,int> mp) {
    for (const auto& pair : mp) {
        cout << pair.first << " Ч " << pair.second << '\n';
    }
}


int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string text;
    cout << "¬вед≥ть текст: ";
    getline(cin, text);



    string word;
    size_t pos = 0;
    map<string, int> mp;
    while ((pos = text.find(" ")) != string::npos) {
        word = text.substr(0, pos);
        mp.insert({ word, 0 });
        for (auto i : mp) {
            if (i.first == word) {
                int temp = i.second + 1;
                mp.erase(i.first);
                mp.insert({word,temp});
            }
        }
        text.erase(0, pos + 1);
    }
    mp.insert({ text, 0 });
    for (auto i : mp) {
        if (i.first == text) {
            int temp = i.second + 1;
            mp.erase(i.first);
            mp.insert({ text,temp });
        }
    }

    for (const auto& pair : mp) {
        cout << pair.first << " Ч " << pair.second << '\n';
    }

    return 0;
}