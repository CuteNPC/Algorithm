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

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        DSU dsu(2000005);
        unordered_map<int, int> mpp;
        int size = 0;
        list<pair<int, int>> ls;
        int q;
        cin >> q;
        while (q--)
        {
            int i, j, e;
            cin >> i >> j >> e;
            if (!mpp.count(i))
                mpp[i] = size++;
            if (!mpp.count(j))
                mpp[j] = size++;
            if (e)
                dsu.unite(mpp[i], mpp[j]);
            else
                ls.push_back(make_pair(mpp[i], mpp[j]));
        }
        int f = 1;
        for (auto [i, j] : ls)
        {
            if (dsu.same(i, j))
            {
                f = 0;
                break;
            }
        }
        cout << (f ? "YES" : "NO") << endl;
    }
}