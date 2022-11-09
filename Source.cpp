#include<iostream>
#include<iomanip>
#include<time.h>

using namespace std;

void Input(int* a, const int n, int i)
{
	if (i < n)
	{
		cout << "a = [ " << i << " ];" << endl;
		int t;
		cin >> t;
		a[i] = t;
		Input(a, n, i + 1);
		return;
	}
	cout << endl;
}

void Print(int* a, const int n, int i)
{
	cout << setw(4) << a[i];
	if (i < n - 1)
	{
		Print(a, n, i + 1);
	}
	else
		cout << endl;

}

void Count(int* a, const int n, int i, int k)
{
	if (a[k] < a[k + 1])
	{
		int t = a[k];
		a[k] = a[k + 1];
		a[k + 1] = t;
	}
	if (k < n - i - 1)
		Count(a, n, i, k + 1);

	if (i < n - 1)
		Count(a, n, i + 1, 0);
}

int main()
{
	srand(time(0));

	int n;
	cout << "n = "; cin >> n;

	int* a = new int[n];

	Input(a, n, 0);
	Print(a, n, 0);
	Count(a, n, 0, 0);
	Print(a, n, 0);

	return 0;
}
