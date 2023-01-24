#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;
int main()
{
    ull zheng = 0, chang = 0;
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            int r = (n - i + 1) * (m - j + 1);
            if (i == j)
                zheng += r;
            else
                chang += r;
        }
    }
    cout << zheng << ' ' << chang;
    return 0;
}