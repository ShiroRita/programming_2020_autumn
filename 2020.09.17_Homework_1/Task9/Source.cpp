#include<iostream>

using namespace std;

int main(int argc, char* argv[])
{
	int p;
	cin >> p;
	p -= 1;
	p = ~1 << p;
	p = ~p;

	cout << p << endl;

	return EXIT_SUCCESS;
}