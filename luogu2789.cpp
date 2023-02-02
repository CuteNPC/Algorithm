#include <bits/stdc++.h>
using namespace std;

int v[25];
set<int> s;

void getans(int n)
{
    int ans = 0;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            ans += v[i] * v[j];
        }
    }
    s.insert(ans);
}

void fun(int n, int last)
{
    if (last == 0)
    {
        getans(n);
        return;
    }
    if (n == 0)
    {
        for (int k = 1; k <= last; k++)
        {
            v[n] = k;
            fun(n + 1, last - k);
        }
        return;
    }
    else
    {
        if (last < v[n - 1])
        {
            return;
        }
    }
    for (int k = v[n - 1]; k <= last; k++)
    {
        v[n] = k;
        fun(n + 1, last - k);
    }
    return;
}

int main()
{
    int n;
    cin >> n;
    fun(0, n);
    cout << s.size() << endl;
    return 0;
}