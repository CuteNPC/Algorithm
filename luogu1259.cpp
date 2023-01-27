#include <iomanip>
#include <iostream>
using namespace std;

int main()
{
    int n;
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = n; i >= 4; i--)
    {
        cout << setw(i) << setfill('o') << 'o' << setw(i) << setfill('*') << '*' << "--";
        for (int j = i; j < n; j++)
            cout << "o*";
        cout << endl;

        cout << setw(i - 1) << setfill('o') << 'o' << "--" << setw(i - 1) << setfill('*') << '*';
        for (int j = i; j <= n; j++)
            cout << "o*";
        cout << endl;
    }
    cout << "ooo*o**--*";
    for (int i = 1; i <= n - 4; i++)
        cout << "o*";
    cout << endl;
    cout << "o--*o**oo*";
    for (int i = 1; i <= n - 4; i++)
        cout << "o*";
    cout << endl;
    cout << "o*o*o*--o*";
    for (int i = 1; i <= n - 4; i++)
        cout << "o*";
    cout << endl;
    cout << "--o*o*o*o*";
    for (int i = 1; i <= n - 4; i++)
        cout << "o*";
    cout << endl;
}