#include<iostream>

using namespace std;

int main(int argc, char* argv[])
{
	int l;
	int x;
	cin >> x;
	l = x + 1;
	l = l * x;
	l = l * (l - x) + l + 1;
	cout << l << endl;

	return EXIT_SUCCESS;
}