#include <bits/stdc++.h>
using namespace std;
class things
{
public:
    int x, y, z;
};
class cmp
{
public:
    bool operator()(const things &a, const things &b)
    {
        return a.z < b.z;
    }
};
priority_queue<things, vector<things>, cmp> pq;
/*并查集模板*/

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
int main()
{
    int n, m;
    cin >> n >> m;
    DSU dsu(2 * n);
    for (int i = 1; i <= m; i++)
    {
        things tmp;
        cin >> tmp.x >> tmp.y >> tmp.z;
        pq.push(tmp);
    }
    while (!pq.empty())
    {
        int x = pq.top().x;
        int y = pq.top().y;
        if (dsu.same(x, y))
        {
            cout << pq.top().z << endl;
            return 0;
        }
        dsu.unite(x, y + n);
        dsu.unite(x + n, y);
        pq.pop();
    }
    cout << 0 << endl;
    return 0;
}