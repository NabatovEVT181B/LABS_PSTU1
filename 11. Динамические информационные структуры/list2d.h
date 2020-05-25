#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<Windows.h>
//define fileName "list2d.bin"
using namespace std;
struct list2d
{
	char value[15];
	list2d *next;
	list2d *prev;
};

list2d* make2List(int n)
{
	list2d *first, *p,*pp;
	first = 0;
	if (n == 0) return first;
	cout << "¬ведите 1-й элемент: ";
	p = new list2d;
	cin.ignore();
	cin.getline(p->value, 15);
	first = p;
	pp = p;
	p->prev = 0;
	for (int i = 1; i < n; i++)
	{
		list2d *h = new list2d;
		p->next = h;
		pp = p;
		p = h;
		p->prev = pp;
		pp = pp->next;
		p->next = 0;
		cout << "¬ведите " << i + 1 << "-й элемент: ";
		cin.getline(p->value, 15);
	}
	return first;
}

void showList(list2d *first)
{
	if (first == 0) { cout << "—писок пуст! " << endl; return; }
	cout << "| ";
	while (first != 0)
	{
		SetConsoleCP(1251);
		cout << first->value << " | ";
		first = first->next;
		SetConsoleCP(866);
	}
	cout << endl;
}

void showListB(list2d *first)
{
	list2d *p = first;
	if (first == 0) { cout << "—писок пуст! " << endl; return; }
	cout << "| ";
	while (p->next != 0)
		p = p->next;

	while (p != 0)
	{
		SetConsoleCP(1251);
		cout << p->value << " | ";
		p = p->prev;
		SetConsoleCP(866);
	}
	cout << endl;
}

void deleteList(list2d *&first)
{
	if (first == 0) { cout << "—писок пуст! " << endl; return; }
	list2d *q, *q1;
	q = first;
	q1 = first;
	while (q1 != 0)
	{
		q = q1;
		q1 = q1->next;
		delete q;
	}
	first = 0;
}

void pushBack(list2d *&first)
{
	list2d *elm = new list2d;
	list2d*h = first;

	cout << "¬ведите элемент: ";
	cin.getline(elm->value, 15);

	if (h != 0) {

		while (h->next != 0)
		h = h->next;
		h->next = elm;
		elm->next = 0;
		elm->prev = h;
	}
	else { first = elm; first->next = 0; first->prev = 0; }
}

void pushBack(list2d *&first, list2d *elm)
{
	list2d*h = first;
	if (h != 0) {
		while (h->next != 0)
			h = h->next;
		h->next = elm;
		elm->next = 0;
		elm->prev = h;
	}
	else { first = elm; first->next = 0; first->prev = 0; }
}

void pushBack(string*& arr, size_t& size, string value)
{
	if (value == "") return;
	string* temp = new string[size + 1];
	temp[size] = value;
	for (int i = 0; i < size; i++)
	{
		temp[i] = arr[i];
	}
	delete[] arr;
	size++;
	arr = temp;

}

void pushFront(list2d *&first)
{
	list2d *elm = new list2d;
	cout << "¬ведите элемент: ";
	cin.getline(elm->value, 15);
	if (first != 0)
	{
		elm->next = first;
		elm->prev = 0;
		first->prev = elm;
		first = elm;
	}
	else
	{
		elm->next = 0;
		elm->prev = 0;
		first = elm;
	}
}

void addSomeFront(list2d *&first)
{
	list2d *tempList = 0;
	list2d *p;
	int n;
	cout << "¬ведите номер элемента: ";
	cin >> n;
	cin.ignore();
	for (size_t i = 0; i < n; i++)
		pushBack(tempList);
	p = tempList;
	while (p->next != 0)
		p = p->next;
	p->next = first;
	first->prev = p;
	first = tempList;
}

void deleteOne(list2d *&first, int n)
{
	int count = 0;
	if (first == 0) { cout << "—писок пуст!" << endl; return; }
	list2d *h = first;
	list2d *p;
	while (h != 0)
	{
		h = h->next;
		count++;
	}
	if (n > count || n < 0)
	{
		cout << n << " Ёлемент не существует" << endl;
		system("pause>nul");
		return;
	}
	count = 1;
	h = first;

	if (n == 0)
	{
		first = first->next;
		first->prev = 0;
		delete h;
		return;
	}
	p = h->next;
	while (p != 0)
	{
		if (count == n)
		{
			h->next = p->next;
			p->next->prev = h;
			delete p;
			return;
		}
		p = p->next;
		h = h->next;
		count++;
	}
}

void addSome(list2d *&first) {

}

void deleteSome(list2d *&first) {
	string str = "";
	cout << "¬ведите номера элементов: ";
	getline(cin, str);
	string *arr = new string[1];
	string iter = "";
	size_t size = 0;

	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] != ' ')
		{
			iter += str[i];
		}
		else
		{
			pushBack(arr, size, iter);
			iter = "";
		}
	}
	pushBack(arr, size, iter);
	cout << endl << "=====================================" << endl;
	showList(first);

	for (int i = 0; i < size; i++)
	{
		deleteOne(first, stoi(arr[i]) - 1);
		for (int j = i + 1; j < size; j++)
			if (stoi(arr[j]) > stoi(arr[i])) {
				arr[j] = to_string(stoi(arr[j]) - 1);
			}
	}
	showList(first);
	system("pause>nul");
}

void writeToFile(list2d *first, string fileName)
{
	ofstream fout(fileName);

	while (first != 0)
	{
		fout.write((char*)(first), sizeof(list2d));
		first = first->next;
	}
	fout.close();
}

void readFromFile(list2d *&first, string fileName)
{
	ifstream fin(fileName);
	if (!fin.is_open())
	{
		system("cls");
		cout << "ќшибка открыти€ файла! " << endl;
		system("pause>nul");
		return;
	}
	if (first != 0)
	deleteList(first);

	while (!fin.eof())
	{
		list2d *elm = new list2d;
		if (fin.read((char*)(elm), sizeof(list2d)))
			pushBack(first, elm);
	}
	fin.close();
}

void useList2d()
{
	const string fileName = "list2d.bin";
	unsigned int n;
	short k;
	bool quit = false;
	system("cls");
	cout << "¬ведите количество элементов в списке: ";
	cin >> n;

	list2d *list = make2List(n);

	cout << "=====================================" << endl;
	showList(list);
	system("pause>nul");
	while (!quit)
	{
		system("cls");
		cout << "¬ведите номер операции: " << endl << endl;
		cout << "1 - вывести список" << endl;
		cout << "2 - создать новый список" << endl;
		cout << "3 - удалить список" << endl;
		cout << "4 - добавить элемент в конец списка" << endl;
		cout << "5 - добавить элемент в начало списка" << endl;
		cout << "6 - добавить несколько элементов в начало списка" << endl;
		cout << "7 - удалить несколько элементов" << endl << endl;

		cout << "8 - сохранить в файл" << endl;
		cout << "9 - восстановить из файла" << endl << endl;

		cout << "10 - назад" << endl << endl;

		cin >> k;
		cin.ignore();

		switch (k)
		{
		case 1:
			system("cls");
			showList(list);
			showListB(list);
			system("pause>nul");
			break;
		case 2:
			system("cls");
			deleteList(list);
			cout << "¬ведите количество элементов в списке: ";
			cin >> n;
			list = make2List(n);
			break;
		case 3:
			deleteList(list);
			break;
		case 4:
			system("cls");
			pushBack(list);
			break;
		case 5:
			system("cls");
			pushFront(list);
			break;
		case 6:
			system("cls");
			addSomeFront(list);
			break;
		case 7:
			system("cls");
			deleteSome(list);
			break;
		case 8:
			writeToFile(list, fileName);
			break;
		case 9:
			readFromFile(list, fileName);
			break;
		case 10:
			if (list != 0)
			deleteList(list);
			quit = true;
			break;
		case 11:
			cout << "¬ведите номер элемента: ";
			cin >> n;
			if (n < 1)n = 1;
			deleteOne(list, n-1);
			break;
		}
	}
}
