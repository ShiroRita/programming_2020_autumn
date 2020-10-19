#include<iostream>
#include<clocale>
#include<ctime>
#include"ArrayList.h"

using namespace std;

void printMenu()
{
	cout << "МЕНЮ" << endl;
	cout << "0 - Выход из программы" << endl;
	cout << "1 - Вывести массив на экран" << endl;
	cout << "2 - Добавить элемент" << endl;
	cout << "3 - Добавить элемент в позицию" << endl;
	cout << "4 - Удалить элемент по индексу" << endl;
	cout << "5 - Найти элемент" << endl;
	cout << "6 - Добавить несколько элементов" << endl;
	cout << "7 - Добавить несколько элементов, начиная с некоторой позиции" << endl;
}

int input()
{
	int i = 0;
	cin >> i;
	return i;
}

void addElement(ArrayList& a)
{
	a.add(input());	
}

void addElementToIndex(ArrayList& a)
{
	cout << "элемент";
	int element = input();
	cout << "позиция";
	int index = input();
	a.add(element, index);
}

void deleteElement(ArrayList& a)
{
	int index = input();

	if (a.remove(index) != true)
	{
		while (a.remove(index) != true)
		{
			a.remove(index);
		}
	}
}

void sElement(ArrayList a)
{
	cout << "введите содержимое: ";
	cout << a.indexOf(input()) << endl;
}

void sIndex(ArrayList a)
{
	cout << "введите индекс: ";
	cout << a.get(input()) << endl;
}

void search(ArrayList a)
{
	cout << "1 - поиск по содержимому" << endl;
	cout << "2 - поиск по индексу" << endl;
	switch (int choice = input())
	{
	case 1:
		sElement(a);
		break;
	case 2:
		sIndex(a);
		break;
	}
}

void addSomeElements(ArrayList& a)
{
	cout << "количество вводимых элементов: ";
	int n = input();
	ArrayList list(n);
	cout << "введите элементы: ";
	for (int i = 0; i < n; ++i)
	{
		addElement(list);
	}

	a.addAll(list);
}

void addSomeElementsFromIndex(ArrayList& a)
{
	cout << "количество вводимых элементов: ";
	int n = input();
	cout << "индекс начальной позиции: ";
	int index = input();
	ArrayList list(n);
	cout << "введите элементы: ";
	for (int i = 0; i < n; ++i)
	{
		addElement(list);
	}

	a.addAll(index, list);
}

void processChoice(ArrayList& a, int choice)
{
	switch (choice)
	{
	case 1:
	{
		a.print();
	}
	break;
	case 2:
	{
		addElement(a);
	}
	break;
	case 3:
	{
		addElementToIndex(a);
	}
	break;
	case 4:
	{
		deleteElement(a);
	}
	break;
	case 5:
	{
		search(a);
	}
	break;
	case 6:
	{
		addSomeElements(a);
	}
	break;
	case 7:
	{
		addSomeElementsFromIndex(a);
	}
	break;
	}
}

int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "Russian");
	ArrayList a;


	int choice = 0;
	do
	{
		system("cls");
		printMenu();
		cin >> choice;
		processChoice(a, choice);
		system("pause");
	} while (choice != 0);

	return EXIT_SUCCESS;
}
