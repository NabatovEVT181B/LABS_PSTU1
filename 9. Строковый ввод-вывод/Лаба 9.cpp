#include "pch.h"
#include <iostream>
#include <fstream>
#include <Windows.h>
#include <string>
#include <sstream>
#include <set>

using namespace std;

void store(int size, string *arr)
{
	ofstream fout;
	fout.open("F1.txt");
	if (!fout.is_open())
	{
		cout << "Ошибка открытия файла!" << endl;
	}
	else
	{
		cin.ignore();
		for (int i = 0; i < size; i++) {
			getline(cin, arr[i]);
			fout << arr[i] << endl;
		}
	}
}

void sort()
{
	ifstream fin;
	fin.open("F1.txt");
	ofstream fout;
	fout.open("F2.txt", ofstream::app);
	for (string str; !fin.eof() && getline(fin, str); )
	{
		istringstream ist(str);
		set<char> s;
		bool flag = true;
		for (string word; flag && ist >> word;)
		{
			if (s.find(word[0]) == s.end())
				s.insert(word[0]);
			else
				flag = false;
		}
		if (flag)
			fout << str << endl;
	}
}

string get_word(istream &is) 
{
	string w;
	is >> w;
	return w;
}

int find()
{
	string word, min_word;
	size_t len, min_len = 1000;

	ifstream fin;
	fin.open("F2.txt");

	while (fin) {
		word = get_word(fin);
		if (word.length() == 0)
			break;
		len = word.length();
		if (len < min_len) {
			min_len = len;
			min_word = word;
		}
	}

	fin.close();

	cout << "Самое короткое слово: \"" << min_word << "\"" << endl << "Длина этого слова: " << min_len << endl << endl;
	return 0;
}


int main()
{
	setlocale(LC_ALL, "ru");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int number, size, sw;
	cout << "Введите кол-во строк, которое хотите ввести (НЕ меньше 10): ";
M: cin >> size;
	cout << endl << endl;
	string *arr = new string[size];
	if (size < 10) {
		cout << "Ошибка! Пожалуйста, введите не менее 10 строк: ";
		goto M;
	}
N:	cout << "\tЧто вы хотите сделать?"<< endl;
	cout << "1. Заполнить файл F1" << endl;
	cout << "2. Скопировать из файла F1 в файл F2 все строки, которые не содержат слова , начинающиеся на одну букву." << endl;
	cout << "3. Найти самое короткое слово в  файле F2." << endl;
	cout << "4. Завершить работу. " << endl << endl;
	cout << "Ваш выбор: ";
	cin >> sw;
	switch (sw) {


	case 1:
		store(size, arr);
		goto N;
		break;
	case 2:
		sort();
		goto N;
		break;
	case 3:
		find();
		goto N;
		break;
	case 4:
		cout << "Программа завершила работу!"<< endl << endl;
		return 0;
	}
}
