#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

int n;

class Point
{
public:
    double x;
    double y;
};

Point p[16];
double dist[16][16];

inline double dis(const Point &A, const Point &B)
{
    return sqrt((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y));
}

double dp[65540][16];

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> p[i].x >> p[i].y;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            dist[i][j] = dis(p[i], p[j]);
        }
    }

    for (int i = 1; i < (1 << n); i++)
    {
        for (int iend = 0; iend < n; iend++)
        {
            if (i & (1 << iend))
            {
                dp[i][iend] = INFINITY;
                int j = i - (1 << iend);
                if (j == 0)
                {
                    dp[i][iend] = sqrt(p[iend].x * p[iend].x + p[iend].y * p[iend].y);
                    break;
                }
                for (int jend = 0; jend < n; jend++)
                {
                    if (j & (1 << jend))
                    {
                        dp[i][iend] = min(dp[i][iend], dp[j][jend] + dist[iend][jend]);
                    }
                }
            }
        }
    }
    double ans = INFINITY;
    for (int i = 0; i < n; i++)
    {
        ans = min(ans, dp[(1 << n) - 1][i]);
    }
    cout << fixed << setprecision(2) << ans;
    return 0;
}