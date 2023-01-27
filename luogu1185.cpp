#include <bits/stdc++.h>
#include <set>
using namespace std;

int wid[15] = {1, 2};
char A[1024][2048];

set<int> vec[10];

void draw(int h, int d, int w, int p)
{
    A[d][w + wid[h]] = 'o';
    if (h == 0)
        return;

    if (!vec[h - 1].count(2*p))
    {
        for (int i = 1; i <= wid[h - 1]; i++)
        {
            A[d + i][w + wid[h] - i] = '/';
        }
        draw(h - 1, d + wid[h - 1] + 1, w - (h == 1), 2 * p);
    }

    if (!vec[h - 1].count(2 * p + 1))
    {
        for (int i = 1; i <= wid[h - 1]; i++)
        {
            A[d + i][w + wid[h] + i] = '\\';
        }
        draw(h - 1, d + wid[h - 1] + 1, w + wid[h] + 1, 2 * p + 1);
    }
}

int main()
{
    memset(A, ' ', sizeof(A));
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int num1, num2;
        cin >> num1 >> num2;
        vec[n - num1].insert(num2 - 1);
    }
    for (int i = 2; i <= 14; i++)
    {
        wid[i] = wid[i - 1] * 2 + 1;
    }
    for (int i = 0; i <= wid[n - 1]; i++)
    {
        A[i][wid[n]] = '\n';
        A[i][wid[n] + 1] = 0;
    }
    draw(n - 1, 0, 0, 0);
    for (int i = 0; i <= wid[n - 1]; i++)
    {
        printf("%s", A[i]);
    }
    return 0;
}