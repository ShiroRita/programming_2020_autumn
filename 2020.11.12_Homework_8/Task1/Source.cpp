#include<iostream>
#include<ctime>
#include<clocale>
#include"LinkedList.h"
#include "Source.h"
using namespace std;

void printList(LinkedList list)
{
	cout << list << endl << endl;
}

int input()
{
	int i = 0;
	cin >> i;
	return i;
}

void clear(LinkedList& list)
{
	for (int i = list.length(); i > 0; --i)
	{
		list.extractTail();
	}
}

void printMenu()
{
	cout << "  MENU" << endl << endl;
	cout << "0) Exit" << endl;
	cout << "1) From Lesson8" << endl;
	cout << "2) extractHead" << endl;
	cout << "3) extractTail" << endl;
	cout << "4) extract(index)" << endl;
	cout << "5) indexOf" << endl;
	cout << "6) contains" << endl;
	cout << "7) swap" << endl;
	cout << "8) list1 = list2" << endl;
}

void checkProcessMenu()
{
	cout << "1 - clear list" << endl;
	cout << "2 - input an element" << endl;
	cout << "3 - input some elements" << endl;
	cout << "4 - continue without changes" << endl;
}

void extractHeadFn(LinkedList& list)
{
	printList(list);
	cout << "ExtractHead: " << list.extractHead() << endl;
	cout << "list: " << list << endl;
}

void extractTailFn(LinkedList& list)
{
	printList(list);
	cout << "ExtractTail: " << list.extractTail() << endl;
	cout << "list: " << list << endl;
}

void extractFn(LinkedList& list)
{
	printList(list);
	cout << "index: ";
	int index = input();
	cout << "Extract: " << list.extract(index) << endl;
	cout << "list: " << list << endl;
}

void indexOfFn(LinkedList& list)
{
	printList(list);
	cout << "index of ";
	int element = input();
	cout << "index = " << list.indexOf(element) << endl;
}

void containsFn(LinkedList& list)
{
	printList(list);
	cout << "element: ";
	cout << (list.contains(input()) ? "yes" : "no");
}

void swapFn(LinkedList& list)
{
	printList(list);
	cout << "1 - by index numbers" << endl;
	cout << "2 - elements" << endl;
	switch (input())
	{
	case 1:
	{
		cout << "index numbers: " << endl;
		list.swap(input(), input());
		printList(list);
	}
	break;
	case 2:
	{
		cout << "elements: " << endl;
		list.swap(list.indexOf(input()), list.indexOf(input()));
		printList(list);
	}
	break;
	}
	
}

void choice8(LinkedList& list1, LinkedList list2)
{
	printList(list1);
	cout << "list1 = list2: " << endl;
	list1 = list2;
	cout << "list1: " << list1 << endl;
}

void processChoice(int choice, LinkedList& list)
{
	switch (choice)
	{
	case 1:
	{	
		printList(list);

		cout << "1 - addToHead" << endl;
		cout << "2 - addToTail" << endl;
		cout << "3 - add(index, element)" << endl;
		cout << "4 - get(index)" << endl;
		cout << "5 - set(index, element)" << endl;
		
		switch (input())
		{
		case 1:
		{
			cout << "addToHead: ";
			list.addToHead(input());
			printList(list);
		}
		break;
		case 2:
		{
			cout << "addToTail: ";
			list.addToTail(input());
			printList(list);
		}
		break;
		case 3:
		{
			cout << "(add) index = ";
			int index = input();
			cout << "element = ";
			int element = input();
			list.add(index, element);
			printList(list);
		}
		break;
		case 4:
		{
			cout << "get: ";
			cout << list.get(input()) << endl;

		}
		break;
		case 5:
		{
			cout << "(set) index = ";
			int index = input();
			cout << "element = ";
			int element = input();
			list.set(index, element);
			printList(list);
		}
		break;
		}
		
	}
	break;
	case 2: //extractHead
	{
		checkProcessMenu();

		switch (input())
		{
		case 1:
		{
			clear(list);
			extractHeadFn(list);
		}
		break;
		case 2:
		{
			cout << "input an element: ";
			list += input();
			extractHeadFn(list);
		}
		break;
		case 3:
		{
			cout << "amount of elements: ";
			for (int i = input(); i > 0; --i)
			{
				cout << "element ";
				list += input();
			}
			extractHeadFn(list);
		}
		break;
		case 4:
		{
			extractHeadFn(list);
		}
		break;
		}
	}
	break;
	case 3: //extractTail
	{
		checkProcessMenu();

		switch (input())
		{
		case 1:
		{
			clear(list);
			extractTailFn(list);
		}
		break;
		case 2:
		{
			cout << "input an element: ";
			list += input();
			extractTailFn(list);
		}
		break;
		case 3:
		{
			cout << "amount of elements: ";
			for (int i = input(); i > 0; --i)
			{
				cout << "element ";
				list += input();
			}
			extractTailFn(list);
		}
		break;
		case 4:
		{
			extractTailFn(list);
		}
		break;
		}	
	}
	break;
	case 4: //extract
	{
		checkProcessMenu();

		switch (input())
		{
		case 1:
		{
			clear(list);
			extractFn(list);
		}
		break;
		case 2:
		{
			cout << "input an element: ";
			list += input();
			extractFn(list);
		}
		break;
		case 3:
		{
			cout << "amount of elements: ";
			for (int i = input(); i > 0; --i)
			{
				cout << "element ";
				list += input();
			}
			extractFn(list);
		}
		break;
		case 4:
		{
			extractFn(list);
		}
		break;
		}
	}
	break;
	case 5: //indexOf
	{
		checkProcessMenu();

		switch (input())
		{
		case 1:
		{
			clear(list);
			indexOfFn(list);
		}
		break;
		case 2:
		{
			cout << "input an element: ";
			list += input();
			indexOfFn(list);
		}
		break;
		case 3:
		{
			cout << "amount of elements: ";
			for (int i = input(); i > 0; --i)
			{
				cout << "element ";
				list += input();
			}
			indexOfFn(list);
		}
		break;
		case 4:
		{
			indexOfFn(list);
		}
		break;
		}
	}
	break;
	case 6: //contains
	{
		checkProcessMenu();

		switch (input())
		{
		case 1:
		{
			clear(list);
			containsFn(list);
		}
		break;
		case 2:
		{
			cout << "input an element: ";
			list += input();
			containsFn(list);
		}
		break;
		case 3:
		{
			cout << "amount of elements: ";
			for (int i = input(); i > 0; --i)
			{
				cout << "element ";
				list += input();
			}
			containsFn(list);
		}
		break;
		case 4:
		{
			containsFn(list);
		}
		break;
		}
	}
	break;
	case 7://swap
	{
		checkProcessMenu();

		switch (input())
		{
		case 1:
		{
			clear(list);
			swapFn(list);
		}
		break;
		case 2:
		{
			cout << "input an element: ";
			list += input();
			swapFn(list);
		}
		break;
		case 3:
		{
			cout << "amount of elements: ";
			for (int i = input(); i > 0; --i)
			{
				cout << "element ";
				list += input();
			}
			swapFn(list);
		}
		break;
		case 4:
		{
			swapFn(list);
		}
		break;
		}
	}
	break;
	case 8://list1 = list2
	{
		LinkedList list2;
		cout << "amount of elements of list2: ";
		for (int i = input(); i > 0; --i)
		{
			cout << "element ";
			list2 += input();
		}
		cout << "list2: " << list2 << endl << endl;

		cout << "list1: " << list << endl << endl;
		checkProcessMenu();

		switch (input())
		{
		case 1:
		{
			clear(list);
			choice8(list, list2);
		}
		break;
		case 2:
		{
			cout << "input an element: ";
			list += input();
			choice8(list, list2);
		}
		break;
		case 3:
		{
			cout << "amount of elements: ";
			for (int i = input(); i > 0; --i)
			{
				cout << "element ";
				list += input();
			}
			choice8(list, list2);
		}
		break;
		case 4:
		{
			choice8(list, list2);
		}
		break;
		}
	}
	break;
	}
}

int main()
{
	LinkedList list;
	
	srand(time(NULL));
	setlocale(LC_ALL, "Russian");

	int choice = -1;
	while (choice != 0)
	{
		system("cls");
		printList(list);
		cout << endl;
		printMenu();
		cin >> choice;
		processChoice(choice, list);
		system("pause");
	}
	return EXIT_SUCCESS;
}