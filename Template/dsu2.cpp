#include <bits/stdc++.h>
using namespace std;
/*并查集模板*/
struct DSU
{
    vector<size_t> pa, size;

    explicit DSU(size_t size_) : pa(size_ * 2), size(size_ * 2, 1)
    {
        iota(pa.begin(), pa.begin() + size_, size_);
        iota(pa.begin() + size_, pa.end(), size_);
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
    void erase(size_t x)
    {
        --size[find(x)];
        pa[x] = x;
    }
    void move(size_t x, size_t y)
    {
        auto fx = find(x), fy = find(y);
        if (fx == fy)
            return;
        pa[x] = fy;
        --size[fx], ++size[fy];
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