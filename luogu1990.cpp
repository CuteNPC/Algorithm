#include <iostream>
using namespace std;

int ans[1000005] = {0, 1, 2, 5};

int main()
{
    int n;
    cin >> n;
    for (int i = 4; i <= n; i++)
        ans[i] = (2 * ans[i - 1] + ans[i - 3]) % 10000;
    cout << ans[n];
    return 0;
}