#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h> 

using namespace std;

struct Information
{
	string carrier;
	string capacity;
	string name;
	string author;
};

void form(Information *arr,int n)
{
	for (int i = 0; i < n; i++)
	{
		
		cout << "Введите носитель: ";
		cin >> arr[i].carrier;
		cout << "Введите объём: ";
		cin >> arr[i].capacity;
		cout << "Введите название: ";
		cin >> arr[i].name;
		cout << "Введите автора: ";
		cin >> arr[i].author;
		cout << endl;
	}
}

void store(Information *arr, int n)
{
	ofstream fout;
	fout.open("Information.txt", ofstream::app);
	if (!fout.is_open())
	{
		cout << "Ошибка открытия файла!" << endl;
	}
	else
	{
		for (int i = 0; i < n; i++) {
			fout << arr[i].carrier << " ";
			fout << arr[i].capacity<< " ";
			fout << arr[i].name<< " ";
			fout << arr[i].author << endl;
		}
	}
}

void print()
{
	string path = "Information.txt";
	ifstream fin;
	fin.open(path);

	if (!fin.is_open())
	{
		cout << "Ошибка открытия файла!" << endl;
	}
	else
	{
		cout << "Файл открыт!" << endl;
		string str;

		while(!fin.eof())
		{
			str = "";
			getline(fin, str);
			cout << str << endl;
		}
	}
	fin.close();
}

void del(string val, Information *arr, int &n)
{
	for (int i = 0; i < n; i++) {
		if (arr[i].capacity == val) {
			for (int k = i; k < n - 1; k++) {
				arr[k].carrier = arr[k + 1].carrier;
				arr[k].capacity = arr[k + 1].capacity;
				arr[k].name = arr[k + 1].name;
				arr[k].author = arr[k + 1].author;
			}
			n--;
			break;
		}
	}
	ofstream fout;
	fout.open("Information.txt");
	if (!fout.is_open())
	{
		cout << "Ошибка открытия файла!" << endl;
	}
	else
	{
		for (int i = 0; i < n; i++) {
			fout << arr[i].carrier << " ";
			fout << arr[i].capacity << " ";
			fout << arr[i].name << " ";
			fout << arr[i].author << endl;
		}
	}
}

void add(Information *arr, int number, int &n)
{
	for (int i = number; number < n - 1; number++) {
				arr[number].carrier = arr[number + 1].carrier;
				arr[number].capacity = arr[number + 1].capacity;
				arr[number].name = arr[number + 1].name;
				arr[number].author = arr[number + 1].author;
			}
	n++;
	cout << "Введите носитель: ";
	cin >> arr[number].carrier;
	cout << "Введите объём: ";
	cin >> arr[number].capacity;
	cout << "Введите название: ";
	cin >> arr[number].name;
	cout << "Введите автора: ";
	cin >> arr[number].author;
	cout << endl;
	ofstream fout;
	fout.open("Information.txt");
	if (!fout.is_open())
	{
		cout << "Ошибка открытия файла!" << endl;
	}
	else
	{
		for (int i = 0; i < n; i++) {
			fout << arr[i].carrier << " ";
			fout << arr[i].capacity << " ";
			fout << arr[i].name << " ";
			fout << arr[i].author << endl;
		}
	}
}

void scan(Information *arr, int &n)
{
	string path = "Information.txt";
	ifstream fin;
	fin.open(path);

	if (!fin.is_open())
	{
		cout << "Ошибка открытия файла!" << endl;
	}
	else
	{
		cout << "Файл открыт!" << endl;
		string str;
		int i = 0;
		while (!fin.eof())
		{
			fin >> arr[i].carrier;
			fin >> arr[i].capacity;
			fin >> arr[i].name;
			fin >> arr[i].author;
			fin.get();
			i++;
		}
	}
	fin.close();
}

int main()
{
	setlocale(LC_ALL, "ru");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int number, n;
	string val;
	cout << "\tС каким количеством записей вы хотите работать? - ";
	cin >> n;
	Information *arr = new Information[n];

M:	cout << "\tЧто вы хотите сделать?"<< endl;
	cout << "1 - Сформировать данные" << endl;
	cout << "2 - Записать данные в файл" << endl;
	cout << "3 - Считать данные из файла в структуру" << endl;
	cout << "4 - Показать, что в данный момент записано в файле" << endl;
	cout << "5 - Удалить 1-й элемент с заданным объёмом информации" << endl;
	cout << "6 - Добавить элемент перед элементом с указаным номером" << endl;
	cout << "7 - Выход из программы" << endl;
	cout << "Ваш выбор - ";
	cin >> number;
	switch (number)
	{
	case 1:
		form(arr,n);
		goto M;
		break;

	case 2:
		store(arr,n);
		cout << endl;
		goto M;
		
		break;

	case 3:
		scan(arr, n);
		cout << endl;
		goto M;

		break;

	case 4:
		print();
		cout << endl;
		goto M;

		break;

	case 5:
		cout << "Введите объём информации с которым необходимо удалить элемент: ";
		cin >> val;
		del(val,arr,n);
		cout << endl;
		goto M;

		break;
	
	case 6:
		cout << "Введите номер элемента перед которым нужно добавить новый элемент: ";
		cin >> number;
		add(arr, number, n);
		cout << endl;
		goto M;

		break;
    case 7:
		cout << endl;
		cout << "Программа завершила свою работу!";
		cout << endl;
		break;
		return 0;
	}
}
