#include <iostream>
#include<ctime>
#include<clocale>
#include "ArrayList.h"

using namespace std;

void printMenu()
{
	cout << "МЕНЮ" << endl;
	cout << "0 - Выход из программы" << endl;
	cout << "1 - Добавить в список 10 случайных положительных двузначных чисел" << endl;
	cout << "2 - Добавить в список 10 случайных отрицательных двузначных чисел" << endl;
	cout << "3 - Поменять местами первый минимальный и последний максимальный элемент" << endl;
	cout << "4 - Перемешать все элементы массива" << endl;
	cout << "5 - Заменить каждый отрицательный элемент массива на 0" << endl;
}

int input()
{
	int i = 0;
	cin >> i;
	return i;
}

int choiceForAdd()
{
	cout << "Выберете, куда добавятся числа:" << endl;
	cout << "1 - в конец" << endl;
	cout << "2 - подряд, начиная с индекса" << endl;
	cout << "3 - на указанные позиции, заменяя значения" << endl;
	int choiceF = input();
	return choiceF;
}

void printArray(ArrayList a)
{
	cout << endl << a.toString() << endl;
}

void choice1(ArrayList& a)//Добавить в список 10 случайных положительных двузначных чисел и вывести список
{
	ArrayList list;
	for (int i = 0; i < 10; ++i)
	{
		list.add(rand() % (99 - 10 + 1) + 10);
	}
	
	switch (int choice = choiceForAdd())
	{
	case 1:
	{
		a.addAll(list);
	}
	break;
	case 2:
	{
		cout << "index = ";
		int index = input();
		a.addAll(index, list);
	}
	break;
	case 3:
	{
		if (a.length() < 10)
		{
			break;
		}
		for (int i = 0; i < 10; ++i)
		{
			a.set(input(), list.get(i));
		}
	}
	break;
	}
	printArray(a);
}

void choice2(ArrayList& a)//Добавить в список 10 случайных отрицательных двузначных чисел и вывести список
{
	ArrayList list;
	for (int i = 0; i < 10; ++i)
	{
		list.add((rand() % (99 - 10 + 1) + 10) * (-1));
	}

	switch (int choice = choiceForAdd())
	{
	case 1:
	{
		a.addAll(list);
	}
	break;
	case 2:
	{
		cout << "index = ";
		int index = input();
		a.addAll(index, list);
	}
	break;
	case 3:
	{
		cout << "Введите индексы" << endl;
		for (int i = 0; i < 10; ++i)
		{
			a.set(input(), list.get(i));
		}
	}
	break;
	}
	printArray(a);
}

void choice3(ArrayList& a)//Поменять местами первый минимальный и последний максимальный элемент и вывести список
{
	int min = a.get(0);
	for (int i = 0; i < a.length(); ++i)
	{
		min = (min > a.get(i + 1) ? a.get(i + 1) : min);
	}
	int max = a.get(0);
	int indexMax = 0;
	for (int i = 0; i < a.length(); ++i)
	{
		max = (max < a.get(i + 1) ? a.get(i + 1) : max);
		indexMax = i;
	}
	a.swap(a.indexOf(min), indexMax);
	printArray(a);
}

void choice4(ArrayList& a)//Перемешать все элементы массива и вывести массив
{
	for (int i = 0; i < a.length(); ++i)
	{
		a.swap(i, rand() % (a.length() + 1));
	}
	printArray(a);
}

void choice5(ArrayList& a)//Заменить каждый отрицательный элемент массива на 0
{
	for (int i = 0; i < a.length(); ++i)
	{
		if (a.get(i) < 0)
		{
			a.set(i, 0);
		}
	}
}

void processChoice(ArrayList& a, int choice)
{
	switch (choice)
	{
	case 1:
	{
		choice1(a);
	}
	break;
	case 2:
	{
		choice2(a);
	}
	break;
	case 3:
	{
		choice3(a);
	}
	break;
	case 4:
	{
		choice4(a);
	}
	break;
	case 5:
	{
		choice5(a);
	}
	break;
	}
}

int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "Russian");

	ArrayList a;
	int choice = -1;
	while (choice != 0)
	{
		system("cls");
		printMenu();
		cin >> choice;
		processChoice(a, choice);
		system("pause");
	}
	return EXIT_SUCCESS;
}