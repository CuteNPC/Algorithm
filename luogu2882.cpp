#include <cstring>
#include <iostream>
using namespace std;
char a[5005];
int d[5005];
int d2[5005];

int main()
{
    int n;
    cin >> n;
    a[0] = 'F';
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        d[i] = (a[i] != a[i - 1]);
    }
    a[n + 1] = 'F';
    d[n + 1] = (a[n + 1] != a[n]);
    int ans = 1 << 30;
    int k_;
    for (int k = 1; k <= n; k++)
    {
        memcpy(d2, d, sizeof(d));
        int sum = 0;
        for (int i = 1; i + k <= n + 1; i++)
        {
            if (d2[i])
            {
                d2[i] = !d2[i];
                d2[i + k] = !d2[i + k];
                sum++;
            }
        }
        int f = 1;
        for (int i = n + 2 - k; i <= n; i++)
        {
            if (d2[i])
            {
                f = 0;
                break;
            }
        }
        if (f)
        {
            if (sum < ans)
            {
                ans = sum;
                k_ = k;
            }
        }
    }
    cout << k_ << ' ' << ans << endl;
    return 0;
}