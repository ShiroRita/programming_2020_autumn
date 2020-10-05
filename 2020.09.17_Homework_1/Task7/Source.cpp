#include<iostream>

using namespace std;

int main(int argc, char* argv[])
{
	int j;
	int k;
	cin >> j;
	cin >> k;
	int m = 0;

	while (m < k)
	{
		(m == 0 ? j = 1 * j : j *= j);
		++m;
	}

	cout << j << endl;

	return EXIT_SUCCESS;
}