#include <iostream>
using namespace std;

int n;
int cnt = 0;
int a[10];
int ok;
void fun(int place, int sum)
{
    if (place == 10)
    {
        if (sum == n)
        {
            cnt++;
            if (ok)
            {
                for (int i = 0; i <= 9; i++)
                {
                    cout << a[i] << ' ';
                }
                cout << endl;
            }
        }
        return;
    }

    if (sum >= n)
        return;
    a[place] = 1;
    fun(place + 1, sum + 1);

    if (sum >= n - 1)
        return;
    a[place] = 2;
    fun(place + 1, sum + 2);

    if (sum >= n - 2)
        return;
    a[place] = 3;
    fun(place + 1, sum + 3);
}

int main()
{
    cin >> n;
    fun(0, 0);
    cout << cnt << endl;
    ok = 1;
    fun(0, 0);
    return 0;
}