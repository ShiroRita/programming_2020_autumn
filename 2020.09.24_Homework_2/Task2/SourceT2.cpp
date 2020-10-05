#include<iostream>
using namespace std;
void printMenu()
{
	cout << "MENU" << endl;
	cout << "0 - Выход из программы" << endl;
	cout << "1 - Добавить в массив n случайных чисел в промежутке от x1 до x2" << endl;
	cout << "2 - Развернуть массив" << endl;
	cout << "3 - Поменять элементы массива местами в парах" << endl;
	cout << "4 - Циклический сдвиг вправо на 1" << endl;
	cout << "5 - Развернуть две половинки массива. z - индекс элемента, разделяющего половинки." << endl;
}
void show(int*& a_, int& i_exist)
{
	for (int i = 0; i < i_exist; ++i)
	{
		cout << a_[i] << " ";
	}
	cout << " - array" << endl;
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
void addRand(int*& a_, int& cap, int& i_exist, int r_min, int n_, int r_max) //1
{
	if (i_exist + n_ <= cap)
	{
		for (int j = i_exist; j < i_exist + n_; ++j)
		{
			a_[j] = rand() % (r_max - r_min + 1) + r_min;
		}
	}
	else
	{
		while (i_exist + n_ > cap)
		{
			enlargeArray(a_, cap);
		}
		for (int j = i_exist; j < i_exist + n_; ++j)
		{
			a_[j] = rand() % (r_max - r_min + 1) + r_min;
		}
	}
	i_exist = i_exist + n_;
	show(a_, i_exist);
}
void turn(int*& a_, int cap, int i_exist) //2
{
	int t = 0;
	for (int j = 0; j < i_exist; ++j)
	{
		t = a_[j];
		a_[j] = a_[i_exist - 1 - j];
		a_[i_exist - 1 - j] = t;
	}
}
void movePairs(int*& a_, int i_exist) //3
{
	int t = 0;
	for (int j = 0; j < i_exist - 1; j += 2)
	{
		t = a_[j + 1];
		a_[j + 1] = a_[j];
		a_[j] = t;
	}
}
void moveArray(int*& a_, int& i_exist) //4
{
	int t = 0;
	for (int j = 1; j < i_exist; ++j)
	{
		t = a_[0];
		a_[0] = a_[j];
		a_[j] = t;
	}
}
void turnParts(int*& a_, int& i_exist, int& n_) //5, a[n] принадлежит второй половинке
{
	int t = 0;
	for (int j = 0; j < n_; ++j)
	{
		t = a_[j];
		a_[j] = a_[n_ - 1 - j];
		a_[n_ - 1 - j] = t;
	}
	for (int j = n_; j < i_exist; ++j)
	{
		t = a_[j];
		a_[j] = a_[i_exist - 1 - j + n_];
		a_[i_exist - 1 - j + n_] = t;
	}
}

void menu(int*& a_, int& cap, int& ch, int& i_exist)
{
	cin >> ch;
	switch (ch)
	{
	case 1:
		int n;
		cout << "n=";
		cin >> n;
		int x1;
		cout << "x1=";
		cin >> x1;
		int x2;
		cout << "x2=";
		cin >> x2;

		addRand(a_, cap, i_exist, x1, n, x2);
	case 2:
		turn(a_, cap, i_exist);
	case 3:
		movePairs(a_, i_exist);
	case 4:
		moveArray(a_, i_exist);
	case 5:
		int z;
		cin >> z;
		turnParts(a_, i_exist, z);
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int c = 5;
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
		show(a, i_ex);
		printMenu();
		menu(a, c, choice, i_ex);
	}
	return 0;
}