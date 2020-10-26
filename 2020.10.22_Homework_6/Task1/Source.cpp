#include<iostream>
#include<clocale>
#include<ctime>
#include "ArrayList.h"
using namespace std;

void printMenu()
{
	cout << "����" << endl;
	cout << "0 - ����� �� ���������" << endl;
	cout << "1 - �������� ������� � ����������" << endl;
	cout << "2 - ������� ������" << endl;
	cout << "3 - ���������, �������� �� ������ ������������" << endl;
	cout << "4 - ����������� ����� ������� �� n ��������� (n>0 - ����� ������, n<0 - ����� �����)" << endl;
	cout << "5 - ���������, ����� �� ������ ����� ������������, ���� �� ���� ������� ���� �������" << endl;
}

int input()
{
	int i = 0;
	cin >> i;
	return i;
}

bool symmetry(ArrayList a)
{
	if (a.length() % 2 != 0)
	{
		return false;
	}
	int sym = 0;
	for (int i = 0; i < a.length() / 2; ++i)
	{
		sym = (a.get(i) != a.get(a.length() - i) ? sym : ++sym);
	}
	return (sym == a.length() % 2 ? true : false);
}

bool symmetryIfRemove(ArrayList a)
{
	cout << "������� ������ ���������� ��������" << endl;
	a.remove(input());
	return symmetry(a);
}

void move(ArrayList& a)
{
	int n = input();
	if (n < 0)
	{
	/*
	n = 5
	0 1 2 3 4 5 6 7
	5 6 7 3 1 2 3 4 t=0
	*/
		n *= (-1);
		int t = a.get(0);
		int c = 0;
		for (int i = 0; i < a.length(); i = (i + n) % a.length())
		{
			a.set((i), a.get((i + n) % a.length()));
			++c;
			if (c == a.length())
			{
				break;
			}
		}
		a.set(a.length() - (n % a.length()), t);
	}
	if (n > 0)
	{
		/*
		n = 5
		0 1 2 3 4 5 6 7   t = 5
		3 4 0 6 7 0 1 2  i=8 j=8
		*/
		int t = a.get(n % a.length());
		int j = 0;
		for (int i = 0; i < a.length(); i++)
		{
			a.set((j + n) % a.length(), a.get(j));
			j = ((j + (a.length() - n % a.length())) % a.length());
		}
		a.set(j - (a.length() - n % a.length()), t);
	}
}

void choice1(ArrayList& a)
{
	cout << "1)� �����; 2)�� ������� (index, element)" << endl;

	switch (input())
	{
	case 1:
		a.add(input());
		break;
	case 2:
		a.add(input(), input());
		break;
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
		cout << a.toString() << endl;
	}
	break;
	case 3:
	{
		if (symmetry(a) == true)
		{
			cout << "������ �����������" << endl;//yes
		}
		else
		{
			cout << "������ �������������" << endl;//no
		}
	}
	break;
	case 4:
	{
		move(a);
	}
	break;
	case 5:
	{
		if (symmetryIfRemove(a) == true)
		{
			cout << "������ �����������" << endl;//yes
		}
		else
		{
			cout << "������ �������������" << endl;//no
		}
	}
	break;
	}
}


int main(int argc, char* argv[])
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