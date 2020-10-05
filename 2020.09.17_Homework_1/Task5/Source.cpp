#include<iostream>

using namespace std;

int main(int argc, char* argv[])
{
	int d;
	cin >> d;
	int e = 1;
	int n = 0;
	for (e; e * e < d; ++e)
	{
		if (d % e == 0)
		{
			++n;
		}
	}
	n *= 2;
	if (e * e == d)
	{
		++n;
	}
	cout << n << endl;
	return EXIT_SUCCESS;
}