// clang-format off
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

inline int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while (!isdigit(ch))
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (isdigit(ch))
    {
        x = (x << 3) + (x << 1) + ch - 48;
        ch = getchar();
    }
    return x * f;
}

const int N = 1e4 + 5;

int n, T, nxt[N], las[N], fa[N], ter[N];

int main()
{
    T = read();
    while (T--)
    {
        n = read();
        fflush(stdout);
        int m = 1;
        fa[1] = 0;
        for (int i = 2; i < n; i++)
        {
            printf("? 1 %d\n", i);
            fflush(stdout);
            int res = 0;
            cin >> res;
            if (res == 0)
                break;
            m = i;
            fa[i] = 0, ter[i] = i;
            if (i > 1)
                {nxt[i - 1] = i, las[i] = i - 1;}
        }
        nxt[m] = 1, las[1] = m, ter[1] = m + 1, fa[m + 1] = 1;
        int tmp = nxt[1];
        for (int i = m + 2; i < n; i++)
        {
            int res = 0;
            printf("? %d %d\n", tmp, i);
            fflush(stdout);
            cin >> res;
            while (res)
            {
                nxt[las[tmp]] = nxt[tmp];
                las[nxt[tmp]] = las[tmp];
                tmp = nxt[tmp];
                printf("? %d %d\n", tmp, i);
                fflush(stdout);
                cin >> res;
            }
            fa[i] = ter[tmp];
            ter[tmp] = i;
            tmp = nxt[tmp];
        }
        printf("! ");
        for (int i = 1; i < n; i++)
            printf("%d ", fa[i]);
        printf("\n");
        fflush(stdout);
    }
    return 0;
}