#include<iostream>
#include"LinkedList.h"
using namespace std;

void printList(LinkedList list)
{
	cout << list << endl;
}

/*int input()
{
	int i = 0;
	cin >> i;
	return i;
}*/

void clear(LinkedList& list)
{
	for (int i = list.length(); i > 0; --i)
	{
		list.extractTail();
	}
}

int main()
{
	LinkedList list;
	printList(list);
	cout << endl << "index of 7: " << list.indexOf(7) << endl;

	list += 9; list += 8; list += 7; list += 6; list += 5; list += 4;

	cout << endl << "index of 7: " << list.indexOf(7) << endl;
	cout << "index of 3: " << list.indexOf(3) << endl;
	cout << endl;
	
	cout << list << " -> " << list.extractTail();

	cout << endl << list.extractHead() << " <- ";
	printList(list);
	clear(list);
	printList(list);

	cout << endl << "extractHead empty: " << list.extractHead() << endl;
	printList(list);

	cout << endl << "extractTail empty: " << list.extractTail() << endl;
	printList(list);

	cout << endl <<"extract index3 empty: " << list.extract(3) << endl;
	printList(list);

	list += 9; list += 8; list += 7; list += 6; list += 5; list += 4;

	cout << endl << "extract index3: " << list.extract(3) << endl;
	cout << endl << "extract index8: " << list.extract(8) << endl;
	printList(list);
	cout << endl;

	LinkedList list2;
	list2 += 1; list2 += 2; list2 += 3; list2 += 4; list2 += 5; list2 += 6;
	cout << "list2:" << endl;
	printList(list2);
	cout << endl;

	list = list2;
	cout << "list = list2:" << endl;
	printList(list);
	cout << endl;

	clear(list);
	printList(list);

	list = list2;
	cout << "list{empty} = list2:" << endl;
	printList(list);
	cout << endl;

	clear(list); list += 1;
	printList(list);
	cout << "list = list2:" << endl;
	printList(list);
	cout << endl;


	
	cout <<"list -= 3, 3 - index:" << endl;
	list -= 3;
	printList(list);
	cout << endl;

	clear(list);
	printList(list);
	cout << "list{empty} -= 3:" << endl;

	list -= 3;
	printList(list);
	cout << endl;

	list += 8;
	printList(list);
	cout << "list -= 3:" << endl;
	list -= 3;
	printList(list);
	cout << endl;


	/*int i1 = input();
	int i2 = input();
	list.swap(i1, i2);*/
	/*printList(list);*/

	return 0;
}