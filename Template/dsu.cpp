#include <bits/stdc++.h>
using namespace std;
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
    DSU dsu(10);
    dsu.unite(1, 2);
    dsu.unite(4, 6);
    dsu.unite(1, 6);
    cout << dsu.same(2, 4) << endl;
    dsu.unite(3, 5);
    cout << dsu.same(3, 6) << endl;
}