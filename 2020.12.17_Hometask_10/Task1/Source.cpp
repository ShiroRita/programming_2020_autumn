#include<iostream>
#include<ctime>

using namespace std;

void printArray(int** data, int n)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			printf("%2d ", data[i][j]);
		}
		cout << endl;
	}
}

int main()
{
	

	int n = 0;
	cout << "input n = ";
	cin >> n;

	int** data = new int* [n];
	for (int i = 0; i < n; ++i)
	{
		data[i] = new int[n];
	}


	cout << endl << 1 << endl;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			data[i][j] = i + j + 1;
		}
	}
	printArray(data, n);


	cout << endl << 2 << endl;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			data[i][j] = 2 * n - (i + j + 1);
		}
	}
	printArray(data, n);


	cout << endl << 3 << endl;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			data[i][j] = j + 1;
		}
	}
	printArray(data, n);


	cout << endl << 4 << endl;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (j <= i)
			{
				data[i][j] = j + 1;
			}
			else
			{
					data[i][j] = i + 1;
			}
		}
	}
	printArray(data, n);



	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			data[i][j] = 0;
		}
	}

	


	cout << endl << 5 << endl;

	int t = 0;

	int i = 0;
	int j = 0;
	int p = n;
	int k = 0;
	while (data[i][j] == 0)
	{
		while (j < p)
		{
			data[i][j] = ++t;
			++j;
		}
		--j;
		++i;
		while (i < p)
		{
			data[i][j] = ++t;

			++i;
		}
		--i;
		--j;
		while (j >= k)
		{
			data[i][j] = ++t;

			--j;
		}
		--i;
		++j;
		while (i > k)
		{
			data[i][j] = ++t;

			--i;
		}
		++j;
		++i;
		--p;
		++k;
	}
	printArray(data, n);

	
	for (int i = 0; i < n; ++i)
	{
		delete[] data[i];
	}
	delete[] data;

	return 0;
}