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

void addSomeElements(int*& a_)
{
	cout << "Введите несколько элементов. Введение 0 остановит ввод" << endl;
	int x = -1;
	do
	{
		cin >> x;
		addElement(a_, x);

	} while (x != 0);
}

void choice1(int*& arr1, int*& arr2)
{
	cout << "Выберите массив. 1 или 2" << endl;
	int choiceArr;
	cin >> choiceArr;
	if (choiceArr == 1)
	{
		addSomeElements(arr1);
	}
	else
	{
		addSomeElements(arr2);
	}
}

void addRandomElements(int*& a_, int n, int min, int max)
{
	for (int i = 0; i < n; ++i)
	{
		addElement(a_, rand() % (max - min + 1) + min);
	}
}

void choice2(int*& arr1, int*& arr2)
{
	cout << "Выберите массив. 1 или 2" << endl;
	int choiceArr;
	cin >> choiceArr;

	cout << "n = " << endl;
	int n;
	cin >> n;

	cout << "a = " << endl;
	int a;
	cin >> a;

	cout << "b = " << endl;
	int b;
	cin >> b;


	if (choiceArr == 1)
	{
		addRandomElements(arr1, n, a, b);
	}
	else
	{
		addRandomElements(arr2, n, a, b);
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
	cout << "Выберите массив. 1 или 2" << endl;
	int choiceArr;
	cin >> choiceArr;
	if (choiceArr == 1)
	{
		printArray(arr1);
	}
	else
	{
		printArray(arr2);
	}
}

int search(int* a_)
{
	int x;
	cin >> x;
	int i = 0;
	while (x != *(a_ + i))
	{
		++i;
	}
	return *(a_ + i);
}

void choice4(int* arr1, int* arr2)
{
	cout << "Выберите массив. 1 или 2" << endl;
	int choiceArr;
	cin >> choiceArr;
	if (choiceArr == 1)
	{
		cout << search(arr1) << endl;
	}
	else
	{
		cout << search(arr2) << endl;
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
	int choiceArr;
	cin >> choiceArr;
	if (choiceArr == 1)
	{
		add(arr1, arr2);
	}
	else
	{
		add(arr2, arr1);
	}
}

int* unify(int* a, int* b)
{
	int* a_ = new int(*(a - 1) + *(b - 1) + 2);
	a_ += 2;
	*(a_ - 1) = *(a - 1) + *(b - 1);
	*(a_ - 2) = *(a - 1) + *(b - 1);
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
	int choiceArr;
	cin >> choiceArr;
	if (choiceArr == 1)
	{
		deleteArray(arr1);
		arr1 = unify(arr1, arr2);
	}
	else
	{
		deleteArray(arr2);
		arr2 = unify(arr2, arr1);
	}
}

int insert(int*& a_)
{
	cout << "index = ";
	int index;
	cin >> index;
	cout << "element = ";
	int element;
	cin >> element;

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
	cout << "Выберите массив. 1 или 2" << endl;
	int choiceArr;
	cin >> choiceArr;
	if (choiceArr == 1)
	{
		insert(arr1);
		while (insert(arr1) == 1)
		{
			cout << "Данные некорректны";
			insert(arr1);
		}
	}
	else
	{
		insert(arr2);
		while (insert(arr2) == 1)
		{
			cout << "Данные некорректны";
			insert(arr2);
		}
	}
}

int deleteGroup(int*& a_)
{
	cout << "индекс начала последовательности = ";
	int startIndex;
	cin >> startIndex;
	cout << "количество элементов = ";
	int n;
	cin >> n;
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
		int i = startIndex;
		for (i; i < startIndex + n; ++i);
		{
			*(a_ + i) = *(a_ + i + 1);
		}
		*(a_ - 2) = *(a_ - 2 - n);
		return 0;
	}
}

void choice8(int*& arr1, int*& arr2)//удаление последовательности
{
	cout << "Выберите массив. 1 или 2" << endl;
	int choiceArr;
	cin >> choiceArr;
	if (choiceArr == 1)
	{
		deleteGroup(arr1);
		while (deleteGroup(arr1) == 1)
		{
			cout << "Данные некорректны";
			deleteGroup(arr1);
		}
	}
	else
	{
		deleteGroup(arr2);
		while (deleteGroup(arr2) == 1)
		{
			cout << "Данные некорректны";
			deleteGroup(arr2);
		}
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
	cout << "Выберите массив. 1 или 2" << endl;
	int choiceArr;
	cin >> choiceArr;
	cout << "Введите искомую последовательность. Введение 0 остановит ввод" << endl;
	int x = -1;
	int* s_ = initArray(10);
	do
	{
		cin >> x;
		addElement(s_, x);
	} while (x != 0);

	if (choiceArr == 1)
	{
		cout << "Индекс начала последовательности " << subSequence(arr1, s_) << endl;
	}
	else
	{
		cout << "Индекс начала последовательности " << subSequence(arr2, s_) << endl;
	}
}

void processChoice(int*& arr1, int*& arr2, int choice)
{
	switch (choice)
	{
	case 1:
		choice1(arr1, arr2);
	case 2:
		choice2(arr1, arr2);
	case 3:
		choice3(arr1, arr2);
	case 4:
		choice4(arr1, arr2);
	case 5:
		choice5(arr1, arr2);
	case 6:
		choice6(arr1, arr2);
	case 7:
		choice7(arr1, arr2);
	case 8:
		choice8(arr1, arr2);
	case 9:
		choice9(arr1, arr2);
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