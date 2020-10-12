#include<iostream>
#include<clocale>
#include<ctime>
#include"ArrayList.h"

using namespace std;

void printMenu()
{
	cout << "����" << endl;
	cout << "0 - ����� �� ���������" << endl;
	cout << "1 - ������� ������ �� �����" << endl;
	cout << "2 - �������� �������" << endl;
	cout << "3 - �������� ������� � �������" << endl;
	cout << "4 - ������� ������� �� �������" << endl;
	cout << "5 - ����� �������" << endl;
	cout << "6 - �������� ��������� ���������" << endl;
	cout << "7 - �������� ��������� ���������, ������� � ��������� �������" << endl;
}

int input(int& i)
{
	cin >> i;
	return i;
}

void addElement(ArrayList& a)
{
	int element = input(element);
	if (a.add(element) != true)
	{
		while (a.add(element) != true)
		{
			a.add(element);
		}
	}
}

void addElementToIndex(ArrayList& a)
{
	int element = input(element);
	int index = input(index);

	if (a.add(element, index) != true)
	{
		while (a.add(element, index) != true)
		{
			a.add(element, index);
		}
	}
}

void deleteElement(ArrayList& a)
{
	int index = input(index);

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
	int element = input(element);
	cout << a.indexOf(element) << endl;
}

void sIndex(ArrayList a)
{
	int index = input(index);
	cout << a.get(index) << endl;
}

void search(ArrayList a)
{
	cout << "1 - ����� �� �����������" << endl;
	cout << "2 - ����� �� �������" << endl;
	switch (int choice = input(choice))
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
	cout << "���������� �������� ���������: ";
	int n = input(n);
	ArrayList list(n);
	cout << "������� ��������: ";
	for (int i = 0; i < n; ++i)
	{
		addElement(list);
	}

	if (a.addAll(list) != true)
	{
		while (a.addAll(list) != true)
		{
			a.addAll(list);
		}
	}
}

void addSomeElementsFromIndex(ArrayList& a)
{
	cout << "���������� �������� ���������: ";
	int n = input(n);
	cout << "������ ��������� �������: ";
	int index = input(index);
	ArrayList list(n);
	cout << "������� ��������: ";
	for (int i = 0; i < n; ++i)
	{
		addElement(list);
	}

	if (a.addAll(index, list) != true)
	{
		while (a.addAll(index, list) != true)
		{
			a.addAll(index, list);
		}
	}
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
