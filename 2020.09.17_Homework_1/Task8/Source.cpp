#include<iostream>

using namespace std;

int main(int argc, char* argv[])
{
	int o;
	cin >> o;
	o -= 1;
	o = 2 << o;

	cout << o << endl;

	return EXIT_SUCCESS;
}