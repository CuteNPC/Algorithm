#include <climits>
#include <iostream>

using namespace std;

int W[55], B[55], R[55], SW[55], SB[55], SR[55];

int N, M;

int main()
{
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            char c;
            cin >> c;
            switch (c)
            {
            case 'W':
                B[i]++;
                R[i]++;
                break;
            case 'B':
                W[i]++;
                R[i]++;
                break;
            case 'R':
                W[i]++;
                B[i]++;
                break;
            }
        }
    }
    for (int i = 1; i <= N; i++)
    {
        SW[i] = SW[i - 1] + W[i];
        SB[i] = SB[i - 1] + B[i];
        SR[i] = SR[i - 1] + R[i];
    }

    int minnum = INT_MAX;
    for (int i = 1; i <= N - 2; i++)
    {
        for (int j = 3; j <= N; j++)
        {
            minnum = min(minnum, SW[i] + (SB[j - 1] - SB[i]) + SR[N] - SR[j - 1]);
        }
    }
    cout << minnum;
    return 0;
}