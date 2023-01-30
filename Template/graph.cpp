#define S4

#ifdef S1

#include <iostream>
#include <vector>

using namespace std;

struct Edge
{
    int u, v;
};

int n, m;
vector<Edge> e;
vector<int> vis;

bool find_edge(int u, int v)
{
    for (int i = 1; i <= m; ++i)
    {
        if (e[i].u == u && e[i].v == v)
        {
            return true;
        }
    }
    return false;
}

void dfs(int u)
{
    if (vis[u])
        return;
    /*visit*/
    cout << u << ' ' << endl;
    /*visit*/
    vis[u] = true;
    for (int i = 1; i <= m; ++i)
    {
        if (e[i].u == u)
        {
            dfs(e[i].v);
        }
    }
}

int main()
{
    cin >> n >> m;

    vis.resize(n + 1, false);
    e.resize(m + 1);

    for (int i = 1; i <= m; ++i)
        cin >> e[i].u >> e[i].v;
    dfs(1);
    return 0;
}

#endif

#ifdef S2
#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> vis;
vector<vector<int>> adj;

bool find_edge(int u, int v)
{
    return adj[u][v];
}

void dfs(int u)
{
    if (vis[u])
        return;
    vis[u] = true;
    for (int v = 1; v <= n; ++v)
    {
        if (adj[u][v])
        {
            dfs(v);
        }
    }
}

int main()
{
    cin >> n >> m;

    vis.resize(n + 1, false);
    adj.resize(n + 1, vector<int>(n + 1, false));

    for (int i = 1; i <= m; ++i)
    {
        int u, v;
        cin >> u >> v;
        adj[u][v] = true;
    }

    return 0;
}
#endif

#ifdef S3
#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> vis;
vector<vector<int>> adj;

bool find_edge(int u, int v)
{
    for (int i = 0; i < adj[u].size(); ++i)
    {
        if (adj[u][i] == v)
        {
            return true;
        }
    }
    return false;
}

void dfs(int u)
{
    if (vis[u])
        return;
    vis[u] = true;
    for (int i = 0; i < adj[u].size(); ++i)
        dfs(adj[u][i]);
}

int main()
{
    cin >> n >> m;

    vis.resize(n + 1, false);
    adj.resize(n + 1);

    for (int i = 1; i <= m; ++i)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    return 0;
}

#endif

#ifdef S4
#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> vis;
vector<int> head, nxt, to;

void add(int u, int v)
{
    nxt.push_back(head[u]);
    head[u] = to.size();
    to.push_back(v);
}

bool find_edge(int u, int v)
{
    for (int i = head[u]; ~i; i = nxt[i])
    { // ~i 表示 i != -1
        if (to[i] == v)
        {
            return true;
        }
    }
    return false;
}

void dfs(int u)
{
    if (vis[u])
        return;
    /*visit*/
    cout << u << ' ' << endl;
    /*visit*/
    vis[u] = true;
    for (int i = head[u]; ~i; i = nxt[i])
        dfs(to[i]);
}

int main()
{
    cin >> n >> m;

    vis.resize(n + 1, false);
    head.resize(n + 1, -1);

    for (int i = 1; i <= m; ++i)
    {
        int u, v;
        cin >> u >> v;
        add(u, v);
    }
    dfs(0);
    return 0;
}

#endif
