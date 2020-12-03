#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

double myFunction(double x, int n)
{
	double d = 1.0;
	double result = 1.0;
	while (n != 0)
	{
		d *= (-1) * x;
		result += d;
		setprecision(9);
		--n;
	}
	return result;
}

int main()
{
	double x = 0;
	int n = 0;
	cin >> x >> n;
	cout << setprecision(9) << myFunction(x, n) << endl;
	cout << setprecision(9) << 1 / (1 + x) << endl;

	return 0;
}