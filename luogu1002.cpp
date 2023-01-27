#include <iostream>
using namespace std;
#define ull unsigned long long
ull map[25][25];
int horsex, horsey;
int maxx, maxy;

bool fun1(int x, int y)
{
	if (x == horsex && y == horsey)
		return 0;
	if (x == horsex + 1 && y == horsey + 2)
		return 0;
	if (x == horsex + 1 && y == horsey - 2)
		return 0;
	if (x == horsex - 1 && y == horsey + 2)
		return 0;
	if (x == horsex - 1 && y == horsey - 2)
		return 0;
	if (x == horsex - 2 && y == horsey - 1)
		return 0;
	if (x == horsex - 2 && y == horsey + 1)
		return 0;
	if (x == horsex + 2 && y == horsey - 1)
		return 0;
	if (x == horsex + 2 && y == horsey + 1)
		return 0;
	return 1;
}

int main()
{
	cin >> maxx >> maxy;
	cin >> horsex >> horsey;
	map[0][0] = 1;
	for (int i = 1; i <= maxx + maxy; i++)
	{
		for (int j = max(0, i - maxx); j <= min(i, maxy); j++)
		{
			int y = j;
			int x = i - j;
			if (!fun1(x, y))
				continue;
			if (x == 0)
				map[x][y] = map[x][y - 1];
			else if (y == 0)
				map[x][y] = map[x - 1][y];
			else
				map[x][y] = map[x - 1][y] + map[x][y - 1];
		}
	}
	cout << map[maxx][maxy];
	return 0;
}
