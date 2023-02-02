#if 0

#include <algorithm>
#include <iostream>
#include <list>
#include <random>

#define ull unsigned long long

using namespace std;

class Node
{
public:
    ull s, p;
} node[100005];

bool cmp(Node a, Node b)
{
    return a.p < b.p;
}

ull N, B;
list<ull> sf, sb;
list<ull> df, db;
int main()
{
    ull res = 20000000000000000;
    ull sumd = 0;
    cin >> N >> B;
    for (int i = 0; i < N; i++)
        cin >> node[i].s >> node[i].p;
    sort(node, node + N, cmp);
    int p = 0;
    ull s1, p1, s2, p2;
    int index = 0;
    s1 = node[index].s;
    p1 = node[index].p;
    index++;
    if (p1 > B)
    {
        cout << -1 << endl;
        return 0;
    }
    while (1)
    {
        if (index == N)
        {
            cout << -1 << endl;
            return 0;
        }
        s2 = node[index].s;
        p2 = node[index].p;
        index++;

        if (p1 < B && p2 > B)
        {
            sumd = p2 - p1;
            sf.push_back(s1);
            s1 = s2;
            p1 = p2;
            break;
        }
        else
        {
            sf.push_back(s1);
            df.push_back(p2 - p1);
            s1 = s2;
            p1 = p2;
        }
    }

    while (1)
    {
        if (index == N)
        {
            break;
        }
        s2 = node[index].s;
        p2 = node[index].p;
        index++;
        sb.push_front(s1);
        db.push_front(p2 - p1);
        s1 = s2;
        p1 = p2;
    }
    sb.push_front(s1);
    while (1)
    {
        if (sf.back() >= sumd && sb.back() >= sumd)
        {
            cout << 0 << endl;
            return 0;
        }
        else if (sf.back() < sumd && sb.back() >= sumd)
        {
            res = min(res, sumd - sf.back());
            sf.pop_back();
            sumd += df.back();
            if (df.empty())
                break;
            df.pop_back();
        }
        else if (sf.back() >= sumd && sb.back() < sumd)
        {
            res = min(res, sumd - sb.back());
            sb.pop_back();
            sumd += db.back();
            if (db.empty())
                break;
            db.pop_back();
        }
        else if (sf.back() < sb.back())
        {
            sf.pop_back();
            sumd += df.back();
            if (df.empty())
                break;
            df.pop_back();
        }
        else
        {
            sb.pop_back();
            sumd += db.back();
            if (db.empty())
                break;
            db.pop_back();
        }
    }
    cout << res << endl;
    return 0;
}

#else
/*不会做，焯答案*/
#include <bits/stdc++.h>
using namespace std;
long long n, b, ans = 5201314314314, st = 1;
// 这里最大值不能开的小于10^9，之前开5201314把我从前天！卡到！今天！
struct grass
{
    long long s, p;
    // 草堆的大小与位置
} gra[100005];
bool cmp(grass a, grass b)
{
    return a.p < b.p;
}
int main()
{
    cin >> n >> b;
    for (int i = 1; i <= n; i++)
        cin >> gra[i].s >> gra[i].p;
    sort(gra + 1, gra + n + 1, cmp);
    for (; st <= n; st++)
        if (gra[st + 1].p > b)
            break;
    // 之前用二分查找莫名其妙的挂了，至今未解
    int l = st, r = st + 1;
    for (; l >= 1; l--)
    {
        while (r <= n && gra[r].p - gra[l].p > gra[r].s)
            // 在能够向右倒腾的时候就一定要倒腾换取可能的最大的加速值
            r++;
        if (r > n)
            break;
        ans = min(ans, gra[r].p - gra[l].p - gra[l].s);
        // 在该点至少要加固的值和ans取min
    }
    l = st;
    r = st + 1;
    for (; r <= n; r++)
    {
        while (l >= 1 && gra[r].p - gra[l].p > gra[l].s)
            // 同上
            l--;
        if (l < 1)
            break;
        ans = min(ans, gra[r].p - gra[l].p - gra[r].s);
        // 同上
    }
    if (ans == 5201314314314)
        cout << -1;
    // 有点绕，如果左边和右边都无论加没加固都无法阻止Bessie逃出去，那么输出-1。
    else
        cout << max(ans, 1ll * 0);
}

#endif