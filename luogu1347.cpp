#include <bits/stdc++.h>
using namespace std;

int eq, n, m;

class Graph
{
public:
    int n;
    vector<int> vis;
    vector<int> head, next, to;
    vector<int> input;
    Graph(int n_)
    {
        n = n_;
        vis.resize(n + 1, 0);
        head.resize(n + 1, -1);
        input.resize(n + 1, 0);
    }
    void clrvis()
    {
        vis = vector<int>(n + 1, 0);
    }
    void add(int u, int v)
    {
        next.push_back(head[u]);
        head[u] = to.size();
        to.push_back(v);
        input[v]++;
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

    void bfs()
    {
    }

    void top()
    {
        string s;
        int cnt = 0;
        list<int> q;
        for (int i = 0; i < n; i++)
        {
            if (input[i] == 0)
            {
                q.push_back(i);
                vis[i] = 1;
                s.push_back(i + 'A');
            }
        }
        while (!q.empty())
        {
            cnt++;
            list<int> q2 = q;
            q = list<int>();
            for (auto u : q2)
            {
                for (int i = head[u]; ~i; i = next[i])
                {
                    input[to[i]]--;
                }
            }
            for (auto u : q2)
            {
                for (int i = head[u]; ~i; i = next[i])
                {
                    if (vis[to[i]] == 0 && input[to[i]] == 0)
                    {
                        q.push_back(to[i]);
                        vis[to[i]] = 1;
                        s.push_back(to[i] + 'A');
                    }
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (vis[i] == 0)
            {
                cout << "Inconsistency found after " << eq << " relations." << endl;
                exit(0);
            }
        }
        if (cnt == n)
        {
            cout << "Sorted sequence determined after " << eq << " relations: " << s << "." << endl;
            exit(0);
        }
    }
};

int main()
{
    cin >> n >> m;
    Graph g(n);

    for (eq = 1; eq <= m; eq++)
    {
        char char1, char2, c;
        cin >> char1 >> c >> char2;
        g.add(char1 - 'A', char2 - 'A');

        Graph G = g;
        G.top();
    }
    cout << "Sorted sequence cannot be determined." << endl;
}