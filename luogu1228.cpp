#include <iostream>
using namespace std;

int base2[15] = {1};

void fun(int k, int x, int y, int bx, int by)
{
    if (k == 0)
        return;
    if (x < base2[k - 1])
    {
        if (y < base2[k - 1])
        {
            cout << bx + base2[k - 1] << ' ' << by + base2[k - 1] << ' ' << 1 << endl;
            fun(k - 1, x, y, bx, by);
            fun(k - 1, 0, base2[k - 1] - 1, bx + base2[k - 1], by);
            fun(k - 1, base2[k - 1] - 1, 0, bx, by + base2[k - 1]);
            fun(k - 1, 0, 0, bx + base2[k - 1], by + base2[k - 1]);
        }
        else
        {
            cout << bx + base2[k - 1] << ' ' << by + base2[k - 1] - 1 << ' ' << 2 << endl;
            fun(k - 1, base2[k - 1] - 1, base2[k - 1] - 1, bx, by);
            fun(k - 1, 0, base2[k - 1] - 1, bx + base2[k - 1], by);
            fun(k - 1, x, y - base2[k - 1], bx, by + base2[k - 1]);
            fun(k - 1, 0, 0, bx + base2[k - 1], by + base2[k - 1]);
        }
    }
    else
    {
        if (y < base2[k - 1])
        {
            cout << bx + base2[k - 1] - 1 << ' ' << by + base2[k - 1] << ' ' << 3 << endl;
            fun(k - 1, base2[k - 1] - 1, base2[k - 1] - 1, bx, by);
            fun(k - 1, x - base2[k - 1], y, bx + base2[k - 1], by);
            fun(k - 1, base2[k - 1] - 1, 0, bx, by + base2[k - 1]);
            fun(k - 1, 0, 0, bx + base2[k - 1], by + base2[k - 1]);
        }
        else
        {
            cout << bx + base2[k - 1] - 1 << ' ' << by + base2[k - 1] - 1 << ' ' << 4 << endl;
            fun(k - 1, base2[k - 1] - 1, base2[k - 1] - 1, bx, by);
            fun(k - 1, 0, base2[k - 1] - 1, bx + base2[k - 1], by);
            fun(k - 1, base2[k - 1] - 1, 0, bx, by + base2[k - 1]);
            fun(k - 1, x - base2[k - 1], y - base2[k - 1], bx + base2[k - 1], by + base2[k - 1]);
        }
    }
}

int main()
{
    for (int i = 1; i <= 12; i++)
    {
        base2[i] = base2[i - 1] * 2;
    }
    int k, x, y;
    cin >> k >> x >> y;
    x--;
    y--;
    fun(k, x, y, 1, 1);
}