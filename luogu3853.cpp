#include <iostream>
#include <set>
using namespace std;

multiset<int, greater<int>> myset;

int k;

bool solution(int m)
{
    int sum = 0;
    for (auto num : myset)
    {
        if (num <= m)
            break;
        sum += (num - 1) / m;
    }
    return sum <= k;
}

int main()
{
    int ll, n, num1, num2;
    cin >> ll >> n >> k >> num1;

    for (int i = 2; i <= n; i++)
    {
        cin >> num2;
        myset.insert(num2 - num1);
        num1 = num2;
    }

    myset.insert(0);
    int l = 0, r = *myset.begin();
    while (1)
    {
        int m = (l + r) / 2;
        if (solution(m))
            r = m;
        else
            l = m;
        if (r - l == 1)
            break;
    }
    cout << r;

    return 0;
}