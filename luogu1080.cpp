#include <algorithm>
#include <climits>
#include <iostream>
#define ull unsigned long long
using namespace std;

class Person
{
public:
    int a, b;
    ull mul, res;
};
inline bool operator<(const Person &x, const Person &y) { return x.a * x.b < y.a * y.b; }

Person person[1005];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i <= n; i++)
        cin >> person[i].a >> person[i].b;
    sort(person + 1, person + n + 1);
    person[0].mul = 1;
    ull maxnum = 0;
    for (int i = 1; i <= n; i++)
    {
        person[i].mul = person[i - 1].mul * person[i - 1].a;
        maxnum = max(maxnum, person[i].mul / person[i].b);
    }
    cout << maxnum;

    return 0;
}