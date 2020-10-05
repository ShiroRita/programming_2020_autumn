#include<iostream>

using namespace std;

int main(int argc, char* argv[])
{
	int r;
	cin >> r;
	int s = 2;
	int z = 0;

	for (s; s <= r; ++s)
	{
		z = 0;
		for (int u = 2; u < s; ++u)
		{
			(s % u == 0 ? ++z : z);
		}
		if (z == 0)
		{
			cout << s << " ";
		}
	}
	cout << endl;

	return EXIT_SUCCESS;
}