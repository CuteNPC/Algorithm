#include <iostream>
#define ull unsigned long long
using namespace std;

int num[100005];

class Color
{
    ull n = 0;
    ull sumindex = 0;
    ull sumnum = 0;
    ull summul = 0;

public:
    void add(ull index, ull num)
    {
        n++;
        sumindex = (sumindex + index) % 10007;
        sumnum = (sumnum + num) % 10007;
        summul = (summul + index * num) % 10007;
    }
    ull getres()
    {
        return ((n - 2) * summul + sumindex * sumnum) % 10007;
    }
};

Color odd[100005];
Color even[100005];

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> num[i];
    for (int i = 1; i <= n; i++)
    {
        int color;
        cin >> color;
        if (i % 2)
        {
            odd[color].add(i, num[i]);
        }
        else
        {
            even[color].add(i, num[i]);
        }
    }
    ull ans = 0;
    for (int i = 1; i <= m; i++)
    {
        ans += odd[i].getres() + even[i].getres();
    }
    cout << ans % 10007;
}