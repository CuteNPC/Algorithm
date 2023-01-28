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
    int n, m;
    cin >> n >> m;
    DSU dsu(2 * n);
    for (int i = 1; i <= m; i++)
    {
        char op;
        int num1, num2;
        cin >> op >> num1 >> num2;
        num1--;
        num2--;
        if (op == 'F')
        {
            dsu.unite(num1, num2);
            //dsu.unite(num1 + n, num2 + n);
        }
        else
        {
            dsu.unite(num1, num2 + n);
            dsu.unite(num1 + n, num2);
        }
    }
    set<int> s;
    for (int i = 0; i < n; i++)
    {
        s.insert(dsu.find(i));
    }
    cout << s.size();
}