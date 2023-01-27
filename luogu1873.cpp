#define SOLUTION2

#ifdef SOLUTION1

#include <iostream>
#include <map>
#define ull unsigned long long
using namespace std;

map<ull, ull, greater<ull>> mp;

int main()
{
    ull M, N;
    cin >> N >> M;
    for (ull i = 1; i <= N; i++)
    {
        ull num;
        cin >> num;
        mp[num]++;
    }

    mp[0] = 1;
    ull sum = 0;
    ull sumn = 0;
    auto it = mp.begin();
    auto it2 = mp.begin();
    it2++;

    while (1)
    {
        sumn += it->second;
        if (sum + (it->first - it2->first) * sumn > M)
            break;
        sum += (it->first - it2->first) * sumn;
        it++;
        it2++;
    }

    ull add = ((M - sum) / sumn) + (bool)((M - sum) % sumn);
    cout << it->first - add;
}
#endif

#ifdef SOLUTION2

#include <climits>
#include <iostream>
#include <map>
#define ull unsigned long long
using namespace std;

map<ull, ull, greater<ull>> mp;

ull n, M;

bool solution(ull m)
{
    ull sum = 0;
    for (auto [h, num] : mp)
    {
        if (h <= m)
            break;
        sum += (h - m) * num;
    }
    return M <= sum;
}

int main()
{
    cin >> n >> M;
    for (ull i = 1; i <= n; i++)
    {
        ull num;
        cin >> num;
        mp[num]++;
    }
    mp[0] = 1;
    ull l = 0, r = mp.begin()->first;
    while (1)
    {
        ull m = (l + r) / 2;
        if (solution(m))
            l = m;
        else
            r = m;
        if (r - l == 1)
            break;
    }
    cout << r-1 << endl;
}

#endif