#include<iostream>
#include<string>
using namespace std;

string fun1()
{
	string result;
	while (1)
	{
		char c = cin.get();
		switch (c)
		{
		case ']':
		case -1:
		case '\n':
			return result;
		case '[':
		{
			int num;
			cin >> num;
			string cyc = fun1();
			for (int i = 1; i <= num; i++)
				result += cyc;
			break;
		}
		default:
			result.push_back(c);
		}
	}
}

int main()
{
	cout << fun1();
}