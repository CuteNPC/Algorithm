#define S4

#ifdef S1
#include <bits/stdc++.h>
using namespace std;
char buf[32];
unordered_set<string> s[1005];
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        int n2;
        scanf("%d", &n2);
        for (int j = 1; j <= n2; j++)
        {
            scanf("%s", buf);
            s[i].insert(string(buf));
        }
    }
    int m;
    scanf("%d", &m);
    for (int i = 1; i <= m; i++)
    {
        scanf("%s", buf);
        for (int i = 1; i <= n; i++)
        {
            if (s[i].count(string(buf)))
                printf("%d ", i);
        }
        printf("\n");
    }
    return 0;
}
#endif

#ifdef S2
#include <bits/stdc++.h>
using namespace std;
char buf[32];
unordered_map<string, set<int>> mp;
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        int n2;
        scanf("%d", &n2);
        for (int j = 1; j <= n2; j++)
        {
            scanf("%s", buf);
            mp[string(buf)].insert(i);
        }
    }
    int m;
    scanf("%d", &m);
    for (int i = 1; i <= m; i++)
    {
        scanf("%s", buf);
        for (auto num : mp[string(buf)])
            printf("%d ", num);
        printf("\n");
    }
    return 0;
}
#endif

#ifdef S3
#include <bits/stdc++.h>
using namespace std;
struct Trie
{
    int nex[5000005][26], cnt;
    unordered_map<int, set<int>> mp; // 该结点结尾的字符串是否存在

    void insert(char *s, int l, int num)
    { // 插入字符串
        int p = 0;
        for (int i = 0; i < l; i++)
        {
            int c = s[i] - 'a';
            if (!nex[p][c])
                nex[p][c] = ++cnt; // 如果没有，就添加结点
            p = nex[p][c];
        }
        mp[p].insert(num);
    }

    set<int> find(char *s, int l)
    { // 查找字符串
        int p = 0;
        for (int i = 0; i < l; i++)
        {
            int c = s[i] - 'a';
            if (!nex[p][c])
                return set<int>();
            p = nex[p][c];
        }
        return mp[p];
    }
};

Trie tr;

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int n2;
        cin >> n2;
        for (int j = 1; j <= n2; j++)
        {
            char buf[32];
            cin >> buf;
            tr.insert(buf, strlen(buf), i);
        }
    }

    int m;
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        char buf[32];
        cin >> buf;
        for (auto num : tr.find(buf, strlen(buf)))
        {
            cout << num << ' ';
        }
        cout << endl;
    }

    return 0;
}

#endif

#ifdef S4
#include <bits/stdc++.h>
using namespace std;
struct Trie
{
    int nex[5000005][26], cnt;
    unordered_multimap<int, int> mp; // 该结点结尾的字符串是否存在

    void insert(char *s, int l, int num)
    { // 插入字符串
        int p = 0;
        for (int i = 0; i < l; i++)
        {
            int c = s[i] - 'a';
            if (!nex[p][c])
                nex[p][c] = ++cnt; // 如果没有，就添加结点
            p = nex[p][c];
        }
        mp.insert(make_pair(p, num));
    }

    auto find(char *s, int l)
    { // 查找字符串
        int p = 0;
        for (int i = 0; i < l; i++)
        {
            int c = s[i] - 'a';
            if (!nex[p][c])
                return make_pair(mp.end(), mp.end());
            p = nex[p][c];
        }
        return mp.equal_range(p);
    }
};

Trie tr;

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int n2;
        cin >> n2;
        for (int j = 1; j <= n2; j++)
        {
            char buf[32];
            cin >> buf;
            tr.insert(buf, strlen(buf), i);
        }
    }

    int m;
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        char buf[32];
        cin >> buf;
        auto [start, end] = tr.find(buf, strlen(buf));
        set<int> s;
        for (auto it = start; it != end; it++)
            s.insert(it->second);
        for (auto num : s)
            cout << num << ' ';
        cout << endl;
    }

    return 0;
}

#endif