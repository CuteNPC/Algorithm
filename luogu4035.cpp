#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        unordered_set<int> s;
        int n;
        scanf("%d", &n);
        while (n--)
        {
            int num;
            scanf("%d", &num);
            if (!s.count(num))
            {
                s.insert(num);
                printf("%d ", num);
            }
        }
        printf("\n");
    }
    return 0;
}