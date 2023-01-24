#include <cmath>
#include <iostream>
using namespace std;
int n, k;
int num[25];
int cnt = 0;

bool fun2(int num)
{
    int mnum = sqrt(num + 1);
    for (int i = 2; i <= mnum; i++)
    {
        if (!(num % i))
            return 0;
    }
    return 1;
}

void fun(int n2, int k2, int num2)
{
    if (n2 == n)
    {
        if (k2 == k)
        {
            cnt += fun2(num2);
        }
        return;
    }
    if (n - (n2 + 1) >= k - k2)
        fun(n2 + 1, k2, num2);
    fun(n2 + 1, k2 + 1, num2 + num[n2]);
}

int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
    }
    fun(0, 0, 0);
    cout << cnt;
}