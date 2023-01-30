#include <bits/stdc++.h>

using namespace std;
struct DSU
{
    vector<size_t> pa, size;

    explicit DSU(size_t size_) : pa(size_), size(size_, 1)
    {
        iota(pa.begin(), pa.end(), 0);
    }

    size_t find(size_t x)
    {
        return pa[x] == x ? x : pa[x] = find(pa[x]);
    }

    void unite(size_t x, size_t y)
    {
        x = find(x), y = find(y);
        if (x == y)
            return;
        if (size[x] < size[y])
            swap(x, y);
        pa[y] = x;
        size[x] += size[y];
    }

    bool same(size_t x, size_t y)
    {
        return find(x) == find(y);
    }
};
int n, m;
vector<int> vis;
vector<int> head, nxt, to;
vector<string> ans;
vector<string> strvec;
list<string> ls;
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
bool judge()
{
    for (int i = 1; i <= n; i++)
        if (vis[i] == 0)
            return 0;
    return 1;
}
string getans()
{
    string ans;
    for (auto elem : ls)
    {
        ans += ".";
        ans += elem;
    }
    return ans;
}
int dfs(int u)
{
    if (vis[u])
        return 0;
    /*visit*/
    ls.push_back(strvec[u - 1]);
    /*visit*/
    vis[u] = true;

    int cnt = 0;
    for (int i = head[u]; ~i; i = nxt[i])
    {
        cnt += dfs(to[i]);
    }
    if (cnt == 0)
    {
        if (judge())
        {
            ans.push_back(getans());
            cout << ans[0].c_str() + 1 << endl;
            exit(0);
        }
    }
    vis[u] = false;
    ls.pop_back();
    return cnt;
}
int main()
{
    cin >> n;
    DSU dsu(n);
    vector<int> in(100), out(100);
    for (int i = 1; i <= n; i++)
    {
        string str;
        cin >> str;
        strvec.push_back(str);
    }
    sort(strvec.begin(), strvec.end());
    nxt.clear();
    to.clear();
    head.resize(n + 1, -1);
    for (int i = 0; i < n; i++)
    {
        string str = strvec[i];
        char c = str[str.size() - 1];
        in[str[0] - 'a']++;
        out[str[str.size() - 1]-'a']++;
        for (int j = n - 1; j >= 0; j--)
        {
            if (strvec[j][0] == c)
            {
                dsu.unite(i, j);
                add(i + 1, j + 1);
            }
        }
    }
    char star = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (!dsu.same(i, i + 1))
        {
            cout << "***" << endl;
            exit(0);
        }
    }
    for (char i = 'a'; i <= 'z'; i++)
    {
        if (in[i - 'a'] > out[i - 'a'])
        {
            out[i - 'a']++;
            star = i;
            break;
        }
    }
    int f = 0;
    for (int i = 0; i < 26; i++)
    {
        if (in[i] > out[i])
        {
            cout << "***" << endl;
            exit(0);
        }
        if (in[i] < out[i])
        {
            if (f)
            {
                cout << "***" << endl;
                exit(0);
            }
            else
            {
                f = 1;
            }
        }
    }
    /*
    for (int i = 0; i < n; i++)
    {
        cout << strvec[i] << endl;
    }
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (find_edge(i, j))
                cout << i << ' ' << j << endl;
        }
    }
    */
    for (int start = 1; start <= n; start++)
    {
        if (star)
        {
            if (strvec[start - 1][0] != star)
                continue;
        }
        vis = vector<int>(n + 1, false);
        dfs(start);
    }
    if (ans.size() == 0)
    {
        cout << "***" << endl;
    }
    else
    {
        sort(ans.begin(), ans.end());
        cout << ans[0].c_str() + 1 << endl;
    }
    return 0;
}