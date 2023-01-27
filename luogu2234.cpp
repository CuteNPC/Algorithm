#include <bits/stdc++.h>
using namespace std;
set<int> s;

int main()
{
    int sum = 0;
    int n;
    cin >> n;
    while (n--)
    {
        int num;
        cin >> num;
        if (s.size() == 0)
        {
            s.insert(num);
            sum += num;
            continue;
        }
        auto [it, flag] = s.insert(num);
        if (!flag)
            continue;
        int left, right;
        if (it == s.begin())
            left = INT_MAX;
        else
        {
            auto it2 = it;
            it2--;
            left = abs((*it2) - num);
        }
        if (++it == s.end())
            right = INT_MAX;
        else
        {
            right = abs((*it) - num);
        }
        sum += min(left, right);
    }
    cout << sum;
}
