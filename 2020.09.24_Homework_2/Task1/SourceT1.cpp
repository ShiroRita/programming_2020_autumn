#include<iostream>
using namespace std;
void printMenu()
{
	cout << "MENU" << endl;
	cout << "0 - Выход из программы" << endl;
	cout << "1 - Добавить число в массив" << endl;
	cout << "2 - Вывести массив на экран" << endl;
	cout << "3 - Найти номер максимального элемента массива" << endl;
	cout << "4 - Найти минимальный элемент массива" << endl;
	cout << "5 - Посчитать сумму элементов массива" << endl;
	cout << "6 - Вывести массив в обратном порядке" << endl;
}

void enlargeArray(int*& a_, int& cap)
{
	int newCap = cap * 2;
	int* t = new int[newCap];
	for (int j = 0; j < cap; ++j)
	{
		t[j] = a_[j];
	}
	delete[] a_;
	a_ = t;
	cap = newCap;
}

void show(int*& a_, int& i_exist)//2
{
	for (int i = 0; i < i_exist; ++i)
	{
		cout << a_[i] << " ";
	}
	cout << endl;
}
void add(int*& a_, int& cap, int& i_exist)//1
{
	i_exist += 1;
	int n;
	cin >> n;
	if (i_exist <= cap)
	{
		a_[i_exist - 1] = n;
	}
	else
	{
		while (i_exist > cap)
		{
			enlargeArray(a_, cap);
		}
		a_[i_exist - 1] = n;
	}
}
int NmaxArray(int*& a_, int& i_exist)//3
{
	int maxN = 0;
	for (int i = 0; i < i_exist; ++i)
	{
		maxN = (a_[maxN] < a_[i] ? i : maxN);
	}
	return maxN;
}
int minArray(int*& a_, int& i_exist)//4
{
	int min = 0;
	for (int i = 0; i < i_exist; ++i)
	{
		min = (min > a_[i] ? a_[i] : min);
	}
	return min;
}
int sumArray(int*& a_, int& i_exist)//5
{
	int sum = 0;
	for (int i = 0; i < i_exist; ++i)
	{
		sum += a_[i];
	}
	return sum;
}
void showTurn(int*& a_, int& i_exist)//6
{
	for (int i = 0; i < i_exist; ++i)
	{
		cout << a_[i_exist - 1 - i] << " ";
	}
}

void menu(int& ch, int*& a_, int& cap, int& i_exist)
{
	cin >> ch;

	switch (ch)
	{
	case 1:
		add(a_, cap, i_exist);
		cin >> a_[i_exist - 1];
	case 2:
		show(a_, i_exist);
	case 3:
		cout << NmaxArray(a_, i_exist) << endl;
	case 4:
		cout << minArray(a_, i_exist) << endl;
	case 5:
		cout << sumArray(a_, i_exist) << endl;
	case 6:
		showTurn(a_, i_exist);
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int c = 1;
	int* a = new int[c];
	int i_ex = 1;
	for (int i = 0; i < i_ex; ++i)
	{
		a[i] = i;
	}

	int choice = -1;

	while (choice != 0)
	{
		system("cls");
		printMenu();
		menu(choice, a, c, i_ex);
	}
	return 0;
}