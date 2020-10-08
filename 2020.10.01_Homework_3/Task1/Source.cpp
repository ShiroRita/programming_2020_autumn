#include<iostream>
#include<clocale>
#include<ctime>

using namespace std;

void printMenu()
{
	cout << "МЕНЮ" << endl;
	cout << "0 - Выход из программы" << endl;
	cout << "1 - Ввести несколько элемнетов с клавиатуры" << endl;
	cout << "2 - Добавить в массив n случайных чисел в промежутке от a до b" << endl;
	cout << "3 - Вывести массив на экран" << endl;
	cout << "4 - Поиск индекса элемента" << endl;
	cout << "5 - Добавление массив к массиву" << endl;
	cout << "6 - Объединение массивов" << endl;
	cout << "7 - Вставка элемента в массив" << endl;
	cout << "8 - Удаление нескольких подряд идущих элементов массива" << endl;
	cout << "9 - Поиск подпоследовательности" << endl;
}

int* initArray(int cap)
{
	return (new int[cap + 2]{ 0, cap }) + 2;
}

void deleteArray(int* a_)
{
	delete[](a_ - 2);
}

void expandArray(int*& a_)
{
	int* t = initArray(2 * (*(a_ - 1)));
	for (int i = 0; i < *(a_ - 1); ++i)
	{
		*(t + i) = *(a_ + i);
	}
	*(t - 2) = *(a_ - 2);
	deleteArray(a_);
	a_ = t;
}

void addElement(int*& a_, int x)
{
	if (*(a_ - 2) == *(a_ - 1))
	{
		expandArray(a_);
	}
	*(a_ + *(a_ - 2)) = x;
	++(*(a_ - 2));
}

int input(int& i)
{
	cin >> i;
	return i;
}

void addSomeElements(int*& a_)
{
	cout << "Сколько элементов вы хотите ввести? n = ";
	int n = input(n);
	
	cout << "Вводимые элементы: ";
	for (int i = 0; i < n; ++i)
	{
		int x = input(x);
		addElement(a_, x);
	}
}

int chooseArray(int& a)
{
	cout << "Выберите массив. 1 или 2" << endl;
	return input(a);
}

void choice1(int*& arr1, int*& arr2)
{
	switch (int choiceArr = chooseArray(choiceArr))
	{
	case 1:
		addSomeElements(arr1);
		break;
	case 2:
		addSomeElements(arr2);
		break;
	}
}

void addRandomElements(int*& a_)
{
	cout << "n = " << endl;
	int n = input(n);

	cout << "a = " << endl;
	int max = input(max);

	cout << "b = " << endl;
	int min = input(min);

	for (int i = 0; i < n; ++i)
	{
		addElement(a_, rand() % (max - min + 1) + min);
	}
}

void choice2(int*& arr1, int*& arr2)
{
	switch(int choiceArr = chooseArray(choiceArr))
	{
	case 1:
		addRandomElements(arr1);
		break;
	case 2:
		addRandomElements(arr2);
		break;
	}
}

void printArray(int* a_)
{
	cout << "[" << *(a_ - 2) << "/" << *(a_ - 1) << "] {";
	for (int i = 0; i < *(a_ - 2); ++i)
	{
		cout << *(a_ + i) << (i == *(a_ - 2) - 1 ? "}\n" : ", ");
	}
}

void choice3(int* arr1, int* arr2)
{
	switch(int choiceArr = chooseArray(choiceArr))
	{
	case 1:
		printArray(arr1);
		break;
	case 2:
		printArray(arr2);
		break;
	}
}

int search(int* a_)
{
	int x = input(x);
	int c = 0;
	for (int i = 0; i < *(a_ - 2); ++i)
	{
		c = (x == *(a_ + i) ? c : ++c);
	}
	if (c != *(a_ - 2))
	{
		int j = 0;
		while (x != *(a_ + j))
		{
			++j;
		}
		return j;
	}
	else
	{
		return -1;
	}
}

void choice4(int* arr1, int* arr2)
{
	switch (int choiceArr = chooseArray(choiceArr))
	{
	case 1:
		cout << search(arr1) << endl;
		break;
	case 2:
		cout << search(arr2) << endl;
		break;
	}
}

void add(int*& arr, int* addedArr)
{
	while ((*(arr - 2) + *(addedArr - 2)) < *(arr - 1))
	{
		expandArray(arr);
	}
	for (int i = 0; i < *(addedArr - 2); ++i)
	{
		*(arr + (*(arr - 2)) + i) = *(addedArr + i);
	}
}

void choice5(int*& arr1, int*& arr2)
{
	cout << "Выберите массив, в который добавится невыбранный. 1 или 2" << endl;
	switch (int choiceArr = input(choiceArr))
	{
	case 1:
		add(arr1, arr2);
		break;
	case 2:
		add(arr2, arr1);
		break;
	}
}

int* unify(int* a, int* b)
{
	int* a_ = new int(*(a - 1) + *(b - 1) + 2);
	a_ += 2;
	*(a_ - 1) = *(a - 1) + *(b - 1);
	*(a_ - 2) = *(a - 2) + *(b - 2);
	for (int i = 0; i < (*(a - 1) * 2); i += 2)
	{
		*(a_ + i) = *(a + (i / 2));
	}
	for (int i = 1; i < (*(b - 1) * 2); i += 2)
	{
		*(a_ + i) = *(b + (i / 2));
	}
	return a_;
}

void choice6(int*& arr1, int*& arr2)
{
	cout << "Выберите массив, в который перейдет объединение. 1 или 2" << endl;
	switch(int choiceArr = input(choiceArr))
	{
	case 1:
		deleteArray(arr1);
		arr1 = unify(arr1, arr2);
		break;
	case 2:
		deleteArray(arr2);
		arr2 = unify(arr2, arr1);
		break;
	}
}

int insert(int*& a_)
{
	cout << "index = ";
	int index = input(index);
	cout << "element = ";
	int element = input(element);

	if (index >= *(a_ - 2))
	{
		return 1;
	}
	else
	{
		addElement(a_, element);
		int t = 0;
		for (int j = index; j < *(a_ - 2); ++j)
		{
			t = *(a_ + j + 1);
			*(a_ + j + 1) = *(a_ + index);
			*(a_ + index) = t;
		}
		return 0;
	}
}

void choice7(int*& arr1, int*& arr2)//вставка элемента в массив
{
	switch(int choiceArr = chooseArray(choiceArr))
	{
	case 1:
		insert(arr1);
		break;
	case 2:
		insert(arr2);
		break;
	}
}

int deleteGroup(int*& a_)
{
	cout << "индекс начала последовательности = ";
	int startIndex = input(startIndex);
	cout << "количество элементов = ";
	int n = input(n);
	if (startIndex >= *(a_ - 2))
	{
		return 1;
	}
	if (startIndex + n >= *(a_ - 2))
	{
		return 1;
	}
	else
	{
		for (int i = startIndex; i < startIndex + n; ++i)
		{
			*(a_ + i) = *(a_ + i + n);
		}
		*(a_ - 2) = *(a_ - 2) - n;
		return 0;
	}
}

void choice8(int*& arr1, int*& arr2)//удаление последовательности
{
	switch (int choiceArr = chooseArray(choiceArr))
	{
	case 1:
		deleteGroup(arr1);
		break;
	case 2:
		deleteGroup(arr2);
		break;
	}
}

int subSequence(int* a, int* b)
{
	if (*(a - 2) <= *(b - 2))
	{
		return -1;
	}
	else
	{
		int count = 0;
		int index = 0;
		for (int i = 0; i < *(b - 2); ++i)
		{
			if (*(a + i) == *b)
			{
				for (int j = 0; j < *(b - 2); ++j)
				{
					if (*(a + i + j) == *(b + j))
					{
						++count;
					}
				}
				if (count == *(b - 2))
				{
					index = i;
				}
				else
				{
					index = -1;
				}
			}
		}
		return index;
	}
}

void choice9(int* arr1, int* arr2)//поиск последовательности
{
	int* s_ = initArray(10);
	cout << "Искомая последовательность: ";
	addSomeElements(s_);
	switch (int choiceArr = chooseArray(choiceArr))
	{
	case 1:
		cout << "Индекс начала последовательности " << subSequence(arr1, s_) << endl;
		break;
	case 2:
		cout << "Индекс начала последовательности " << subSequence(arr2, s_) << endl;
		break;
	}
}

void processChoice(int*& arr1, int*& arr2, int choice)
{
	switch (choice)
	{
	case 1:
		choice1(arr1, arr2);
		break;
	case 2:
		choice2(arr1, arr2);
		break;
	case 3:
		choice3(arr1, arr2);
		break;
	case 4:
		choice4(arr1, arr2);
		break;
	case 5:
		choice5(arr1, arr2);
		break;
	case 6:
		choice6(arr1, arr2);
		break;
	case 7:
		choice7(arr1, arr2);
		break;
	case 8:
		choice8(arr1, arr2);
		break;
	case 9:
		choice9(arr1, arr2);
		break;
	}
}

int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "Russian");
	int* a = initArray(10);
	int* b = initArray(10);

	int choice = 0;
	do
	{
		system("cls");
		printMenu();
		cin >> choice;
		processChoice(a, b, choice);
		system("pause");
	} while (choice != 0);

	deleteArray(a);
	deleteArray(b);
	return EXIT_SUCCESS;
}