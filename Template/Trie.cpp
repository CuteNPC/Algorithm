#include <cstring>
#include <iostream>
using namespace std;

/*Tire树模板*/
struct Trie
{
    int nex[100000][26], cnt;
    bool exist[100000]; // 该结点结尾的字符串是否存在

    void insert(char *s, int l)
    { // 插入字符串
        int p = 0;
        for (int i = 0; i < l; i++)
        {
            int c = s[i] - 'a';
            if (!nex[p][c])
                nex[p][c] = ++cnt; // 如果没有，就添加结点
            p = nex[p][c];
        }
        exist[p] = 1;
    }

    bool find(char *s, int l)
    { // 查找字符串
        int p = 0;
        for (int i = 0; i < l; i++)
        {
            int c = s[i] - 'a';
            if (!nex[p][c])
                return 0;
            p = nex[p][c];
        }
        return exist[p];
    }
};

Trie tree;
int main()
{
    while (1)
    {
        char op;
        char buf[8192];
        cin >> op >> buf;
        int l = strlen(buf);
        if (op == 'i')
            tree.insert(buf, l);
        else
            cout << ((tree.find(buf, l)) ? "YES" : "NO") << endl;
    }
}