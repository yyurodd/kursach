#include <Windows.h>
#include <iostream>
#include <fstream> 
#include <string>
#include <cctype>
#include "course.h"
using namespace std;

string text;

void SpaceDeleter() {
	for (int i = 0; i < text.size(); i++) {
		if (text[i] == ' ' && text[i + 1] == ' ')
			while (text[i + 1] == ' ')
				text.erase((i + 1), 1);
	}
}

void SignDeleter() {
	for (int i = 0; i < text.size(); i++)
		if ((text[i] == '.' || text[i] == ',' || text[i] == '?' || text[i] == '!' || text[i] == ';' || text[i] == ':') && (text[i + 1] == '.' || text[i + 1] == ',' || text[i + 1] == '?' || text[i + 1] == '!' || text[i + 1] == ';' || text[i + 1] == ':')) {
			if (text[i] == '.' && text[i + 1] == '.' && text[i + 2] == '.' && text[i + 3] == ' ')
				i += 3;
			else
				while (text[i + 1] == '.' || text[i + 1] == ',' || text[i + 1] == '?' || text[i + 1] == '!' || text[i + 1] == ';' || text[i + 1] == ':')
					text.erase((i + 1), 1);
		}
}

void CorrectRegister() {
	for (int i = 1; i < text.size(); i++) {
		if (text[i] == ' ')
			i += 2;
		text[i] = tolower(text[i]);

	}
}

void UpperCase(string txt) {
	txt[0] = toupper(txt[0]);
	for (int i = 1; i < txt.size(); i++) {
		if (txt[i] == ' ')
			txt[i + 1] = toupper(txt[i + 1]);
	}
	std::cout << txt << "\n";
}




void SameLetters(string txt) {
	txt += ' ';
	string currentWord = "";
	for (int i = 0; i < txt.length(); i++) {
		if (txt[i] != ' ') {
			currentWord += txt[i];
		}
		else {
			bool hasSameLetters = false;
			for (int j = 0; j < currentWord.length(); j++) {
				for (int k = j + 1; k < currentWord.length(); k++) {
					if (currentWord[j] == currentWord[k]) {
						hasSameLetters = true;
						break;
					}
				}
			}
			if (hasSameLetters) {
				cout << currentWord << " ";
			}
			currentWord = "";
		}
	}
}



void Search(string txt) {
	string under;
	int k = 0;
	int count = 0;

	cin >> under;

	for (int i = 0; i < txt.length(); i++) {
		if (txt[i] == under[0]) {
			k = 1;
			int j;
			for (j = 1; j < under.length(); j++) {
				if (txt[i + j] != under[j]) {
					k = 0;
					break;
				}
			}
			if (k == 1) {
				count++;
			}
			if (j == under.length()) {
				cout << "Индекс начала подстроки: " << i << "\n";
			}
		}
	}
	cout << "Количество совпадений: " << count;
}

void lab4()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(0, "");
	bool input = true;
	cout << "Введите текст: ";
	if (input) {
		cin.ignore();
		getline(cin, text);
	}

	cout << "Входной текст: " << text << "\n\n";

	cout << "Задание 2\n\n";
	SpaceDeleter();
	SignDeleter();
	CorrectRegister();
	cout << "Отредактированный текст: " << text << "\n";

	cout << "\n\n" << "Задание 3\n\n";
	cout << "Слова с одинаковыми буквами: \n";
	SameLetters(text);
	cout << "\n\n";
	cout << "Задание 4\n\n";
	cout << "Заменена во всех словах первая буква соответствующей прописной буквой: \n\n";
	UpperCase(text);



	cout << "\n\n" << "Задание 5";
	cout << "\n\nЛинейный поиск: \nВведите подстроку, которую хотите найти: \n";
	Search(text);

}
