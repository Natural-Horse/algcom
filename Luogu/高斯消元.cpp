// clang-format off
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
#define db double
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

const int N = 105;

int n, plc[N];
db a[N][N], ans[N];

int main()
{
    n = read();
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n + 1; j++)
            a[i][j] = read();
    }
    for (int i = 1; i <= n; i++)
    {
        int jud = 0;
        db fab = 0;
        for (int j = 1; j <= n; j++)
            if (fabs(a[i][j]) > fabs(fab))
                fab = a[i][j], jud = j;
        //        printf("%d\n", jud);
        if (!jud)
        {
            printf("No Solution\n");
            return 0;
        }
        for (int j = 1; j <= n + 1; j++)
            if (j != jud)
                a[i][j] /= a[i][jud];
        a[i][jud] = 1;
        for (int j = 1; j <= n; j++)
        {
            if (j == i)
                continue;
            for (int k = 1; k <= n + 1; k++)
                if (k != jud)
                    a[j][k] -= a[i][k] * a[j][jud];
            a[j][jud] = 0;
        }
        plc[i] = jud;
        //        for(int j = 1; j <= n; j++){
        //            for(int k = 1; k <= n+1; k++) printf("%.2lf ", a[j][k]);
        //            printf("\n");
        //        }
    }
    //      for(int i = 1; i <= n; i++) if(!a[i][plc[i]]){printf("No Solution\n"); return 0;}
    for (int i = 1; i <= n; i++)
        ans[plc[i]] = a[i][n + 1];
    for (int i = 1; i <= n; i++)
        printf("%.2lf\n", ans[i]);
    return 0;
}
