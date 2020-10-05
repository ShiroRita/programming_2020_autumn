#include<iostream>

using namespace std;

int main(int argc, char* argv[])
{
	int a;
	cin >> a;
	int b;
	cin >> b;

	int c = 0;

	while ((a - b) >= 0)
	{
		++c;
		a = a - b;
	}

	cout << c << endl;

	return EXIT_SUCCESS;
}