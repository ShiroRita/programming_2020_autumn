#include<iostream>

using namespace std;

int main(int argc, char* argv[])
{
	int h;
	cin >> h;

	int i = 1;
	int f = 1;

	while (i <= h)
	{
		f = f * i;
		++i;
	}
	cout << f << endl;

	return EXIT_SUCCESS;
}