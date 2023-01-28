#include <bits/stdc++.h>
using namespace std;

bool su(int num)
{
    for (int i = 2; i <= sqrt(num + 1); i++)
    {
        if (!(num % i))
            return 0;
    }
    return 1;
}

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
    DSU dsu(100005);
    int a, b, p;
    cin >> a >> b >> p;

    for (int pi = p; pi <= b; pi++)
    {
        if (su(pi))
        {
            for (int pj = ((a + pi - 1) / pi) * pi; pj + pi <= b; pj += pi)
            {
                dsu.unite(pj, pj + pi);
            }
        }
    }
    set<int> s;
    for (int i = a; i <= b; i++)
    {
        s.insert(dsu.find(i));
    }
    cout << s.size() << endl;

    return 0;
}