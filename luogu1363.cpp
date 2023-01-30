#include <bits/stdc++.h>
using namespace std;

bool mp[1505][1505];
int n, m;
int sx, sy;
map<pair<int, int>, pair<int, int>> mmp;

bool dfs(int x, int y, int px, int py)
{
    if (x == -1)
    {
        x += n;
        px--;
    }
    if (y == -1)
    {
        y += m;
        py--;
    }
    if (x == n)
    {
        x -= n;
        px++;
    }
    if (y == m)
    {
        y -= m;
        py++;
    }
    if (mp[x][y] == 0)
        return 0;
    if (mmp.count(make_pair(x, y)))
    {
        if (mmp[make_pair(x, y)] != make_pair(px, py))
        {
            return 1;
        }
        return 0;
    }
    mmp[make_pair(x, y)] = make_pair(px, py);
    if (dfs(x - 1, y, px, py) ||
        dfs(x + 1, y, px, py) ||
        dfs(x, y - 1, px, py) ||
        dfs(x, y + 1, px, py))
        return 1;
    return 0;
}

int main()
{
    ios::sync_with_stdio(false);
    while (cin >> n >> m)
    {
        memset(mp, 0, sizeof(mp));
        mmp.clear();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                char c;
                cin >> c;
                mp[i][j] = (c != '#');
                if (c == 'S')
                {
                    sx = i;
                    sy = j;
                }
            }
        }

        cout << (dfs(sx, sy, 0, 0) ? "Yes" : "No") << endl;
    }
    return 0;
}