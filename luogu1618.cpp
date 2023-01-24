#include <iostream>
#include <sstream>
using namespace std;

int main()
{
    int a, b, c;
    int cnt = 0;
    cin >> a >> b >> c;
    if (a > 0 && b > 0 && c > 0)
        ;
    else if (a < 0 && b < 0 && c < 0)
    {
        a = -a;
        b = -b;
        c = -c;
        int temp = a;
        a = c;
        c = temp;
    }
    else
    {
        cout << "No!!!" << endl;
        return 0;
    }
    for (int i = 2; i <= 999; i++)
    {
        if (a % i || b % i || c % i)
            continue;
        a /= i;
        b /= i;
        c /= i;
        i--;
    }
    for (int i = 1; c * i <= 999; i++)
    {
        int ta = a * i;
        int tb = b * i;
        int tc = c * i;
        int s[10] = {0};

        s[ta / 100]++;
        s[(ta / 10) % 10]++;
        s[ta % 10]++;

        s[tb / 100]++;
        s[(tb / 10) % 10]++;
        s[tb % 10]++;

        s[tc / 100]++;
        s[(tc / 10) % 10]++;
        s[tc % 10]++;

        bool flag = 1;
        for (int i = 1; i <= 9; i++)
        {
            flag = flag && (s[i] == 1);
        }
        if (flag)
        {
            cout << ta << ' ' << tb << ' ' << tc << endl;
            cnt++;
        }
    }
    if (!cnt)
        cout << "No!!!" << endl;
    return 0;
}