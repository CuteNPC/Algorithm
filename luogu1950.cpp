#include <iostream>
using namespace std;

char a[1005][1005];
int s[1005][1005];
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> (a[i] + 1);
        for (int j = 1; j <= m; j++)
        {
            s[i][j] = s[i - 1][j] + s[i][j - 1] + (a[i][j] == '*') - s[i - 1][j - 1];
        }
    }
    uint64_t ans = 0;
    for (int x1 = 1; x1 <= n; x1++)
    {
        for (int x2 = x1; x2 <= n; x2++)
        {
            int sum = 0;
            for (int j = 1; j <= m; j++)
            {
                int f = (s[x2][j] - s[x2][j - 1]) - (s[x1 - 1][j] - s[x1 - 1][j - 1]);
                if (f)
                {
                    ans += sum * (sum + 1) / 2;
                    sum = 0;
                }
                else
                {
                    sum++;
                }
            }
            ans += sum * (sum + 1) / 2;
        }
    }
    cout << ans << endl;
    return 0;
}