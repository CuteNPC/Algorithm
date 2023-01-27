#include<iostream>
using namespace std;
#define ull unsigned long long

int main()
{
	int n;
	cin >> n;

	ull num = 1;
	for (int i = 1; i <= n; i++)
	{
		num *= 2 * i * (2 * i - 1);
		num /= (i * i);
	}
	cout << num / (n + 1);
}