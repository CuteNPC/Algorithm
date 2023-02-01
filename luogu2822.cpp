#include <cmath>
#include <iostream>
#include <map>
int A[2005][2005];
int S[2005][2005];
using namespace std;
int t, k;

inline int get(int x, int y)
{
    if (x == -1 || y == -1)
        return 0;
    return S[x][y];
}

int main()
{
    cin >> t >> k;

    for (int i = 0; i <= 2000; i++)
    {
        A[i][0] = 1;
        for (int j = 1; j <= i; j++)
            A[i][j] = (A[i - 1][j - 1] + A[i - 1][j]) % k;
    }

    for (int i = 0; i <= 2000; i++)
        for (int j = 0; j <= i; j++)
            A[i][j] = !A[i][j];

    for (int i = 0; i <= 2000; i++)
        for (int j = 0; j <= 2000; j++)
            S[i][j] = (get(i - 1, j) + get(i, j - 1) - get(i - 1, j - 1) + A[i][j]);

    while (t--)
    {
        int num1, num2;
        cin >> num1 >> num2;
        cout << S[num1][num2] << endl;
    }

    return 0;
}