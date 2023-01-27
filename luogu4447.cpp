#include <iostream>
#include <map>
#include <queue>
#define ull unsigned long long
#define maxs(a, b) (a = max(a, b))
#define mins(a, b) (a = min(a, b))
using namespace std;
map<int, int> mp;
queue<int> q;
int main()
{
    int minsz = 1 << 30;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int num;
        cin >> num;
        mp[num]++;
        mp[num + 1]--;
    }

    for (auto elem : mp)
    {
        if (elem.second > 0)
        {
            for (int i = 1; i <= elem.second; i++)
            {
                q.push(elem.first);
            }
        }
        else if (elem.second < 0)
        {
            for (int i = 1; i <= -elem.second; i++)
            {
                mins(minsz, elem.first - q.front());
                q.pop();
            }
        }
    }
    cout << minsz;
    return 0;
}