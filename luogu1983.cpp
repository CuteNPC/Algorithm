#define S2
#ifdef S1
#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
    int n;
    int tn;
    vector<int> head, next, to;
    vector<int> vis;
    vector<int> in;
    Graph(int n_, int tn_)
    {
        n = n_;
        tn = tn_;
        head.resize(n + 1, -1);
        vis.resize(n + 1, 0);
        in.resize(n + 1, 0);
    }
    void add(int u, int v)
    {
        next.push_back(head[u]);
        head[u] = to.size();
        to.push_back(v);
        in[v]++;
    }
    bool find_edge(int u, int v)
    {
        for (int i = head[u]; ~i; i = next[i])
        {
            if (to[i] == v)
            {
                return 1;
            }
        }
        return 0;
    }
    int top()
    {
        int cnt = 0;
        list<int> q;
        for (int i = 0; i < n; i++)
        {
            if (in[i] == 0)
            {
                q.push_back(i);
                vis[i] = 1;
            }
        }
        while (!q.empty())
        {
            cnt++;
            list<int> q2 = q;
            q = list<int>();
            for (auto u : q2)
            {
                if (u >= tn)
                {
                    for (int i = head[u]; ~i; i = next[i])
                    {
                        in[to[i]]--;
                    }
                }
            }
            for (auto u : q2)
            {
                if (u >= tn)
                {
                    for (int i = head[u]; ~i; i = next[i])
                    {
                        if (vis[to[i]] == 0 && in[to[i]] == 0)
                        {
                            q2.push_back(to[i]);
                            vis[to[i]] = 1;
                        }
                    }
                }
            }
            /*for (int i = tn; i < n; i++)
            {
                q2.remove(i);
            }*/
            for (auto u : q2)
            {
                if (u >= tn)
                    continue;
                for (int i = head[u]; ~i; i = next[i])
                {
                    in[to[i]]--;
                }
            }
            for (auto u : q2)
            {
                if (u >= tn)
                    continue;
                for (int i = head[u]; ~i; i = next[i])
                {
                    if (vis[to[i]] == 0 && in[to[i]] == 0)
                    {
                        q.push_back(to[i]);
                        vis[to[i]] = 1;
                    }
                }
            }
        }
        return cnt;
    }
};

Graph g(2, 1);
int main()
{
    // ifstream cin("P1983_8.in");
    int n, m;
    cin >> n >> m;
    g = Graph(n + m, n);
    for (int op = n; op < n + m; op++)
    {
        set<pair<int, int>> s;
        vector<int> from, to;
        int t;
        cin >> t;
        int num1, num2;
        cin >> num2;
        to.push_back(num2);
        for (int i = 2; i <= t; i++)
        {
            num1 = num2;
            cin >> num2;
            to.push_back(num2);
            for (int j = num1 + 1; j <= num2 - 1; j++)
            {
                from.push_back(j);
            }
        }
        for (int u : from)
        {
            g.add(u - 1, op);
        }
        for (int v : to)
        {
            g.add(op, v - 1);
        }
    }

    for (int u = 0; u < n; u++)
    {
        for (int i = g.head[u]; ~i; i = g.next[i])
        {
            // printf("%d %d\n", u, g.to[i]);
        }
    }

    cout << g.top() << endl;
    return 0;
}
#endif

#ifdef S2

#include <cstdio>
#include <cstring>
#include <iostream>
#define ZYS 1005
using namespace std;
int n, m, ans, st[ZYS], s, tuopu[ZYS][ZYS], de[ZYS], tt[ZYS], top;
bool is[ZYS], bo[ZYS]; // 用andyzys大佬的名字做数组范围
int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        memset(is, 0, sizeof(is)); // is表示是否是停靠站
        scanf("%d", &s);
        for (int j = 1; j <= s; j++)
            scanf("%d", &st[j]), is[st[j]] = true;
        for (int j = st[1]; j <= st[s]; j++)
            if (!is[j])                      // 枚举站点，若不是已停靠的就小于所有停靠站的等级
                for (int k = 1; k <= s; k++) // 枚举已停靠站点
                    if (!tuopu[j][st[k]])
                        tuopu[j][st[k]] = 1, de[st[k]]++; // tuopu[i][j]表示j>i的级别，如上
    }

    do
    {
        top = 0;
        for (int i = 1; i <= n; i++)
            if (de[i] == 0 && !bo[i])
            {
                tt[++top] = i, bo[i] = true; // 开始将出度为0的点删掉
            }
        for (int i = 1; i <= top; i++)
            for (int j = 1; j <= n; j++)
                if (tuopu[tt[i]][j])
                    tuopu[tt[i]][j] = 0, de[j]--; // 去边去点
        ans++;
    } while (top);
    printf("%d", ans - 1); // 最后一次什么点都没有会多算一次（自行理解）
    return 0;
}

#endif