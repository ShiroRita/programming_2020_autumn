#include<iostream>

using namespace std;

int main(int argc, char* argv[])
{
	int w;
	cin >> w;
	int e = 0;
	for (int q = 100001; q < 1000000; ++q)
	{
		int i6 = q % 10;
		int i5 = (q / 10) % 10;
		int i4 = (q / 100) % 10;
		int i3 = (q / 1000) % 10;
		int i2 = (q / 10000) % 10;
		int i1 = q / 100000;

		if (i1 + i2 + i3 == i4 + i5 + i6)
		{
			if (i1 + i2 + i3 == w)
			{
				cout << i1 << i2 << i3 << i4 << i5 << i6 << " ";
			}
		}
	}
	cout << endl;
	return EXIT_SUCCESS;
}