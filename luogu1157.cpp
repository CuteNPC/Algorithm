#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;
int n;
int selnum[15];
int flgnum[15] = {0};

void print()
{
    for (int i = 0; i < n; i++)
        cout << setw(5) << selnum[i];
    cout << endl;
}

void fun(int plc)
{
    if (plc == n)
        print();
    for (int i = 1; i <= n; i++)
    {
        if (flgnum[i] == 1)
            continue;
        selnum[plc] = i;
        flgnum[i]++;
        fun(plc + 1);
        flgnum[i]--;
    }
}

int main()
{
    cin >> n;
    fun(0);
    return 0;
}