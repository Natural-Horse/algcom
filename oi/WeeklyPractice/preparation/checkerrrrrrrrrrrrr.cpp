#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

typedef long long ll;
typedef unsigned long long ull;

int getintRes; 
inline int getint()
{
    static char ch; 
    while ((ch = getchar()) < '0' || ch > '9'); 
    getintRes = ch - '0'; 
    while ((ch = getchar()) >= '0' && ch <= '9')
        getintRes = getintRes * 10 + ch - '0'; 
    return getintRes; 
}

inline void read(int &x)
{
    static char ch; 
    while ((ch = getchar()) < '0' || ch > '9'); 
    x = ch - '0'; 
    while ((ch = getchar()) >= '0' && ch <= '9')
        x = x * 10 + ch - '0'; 
}

inline int getmin(const int &a, const int &b) {return a < b ? a : b;}

const int MaxN = 55; 
const int MaxM = 5e4 + 10; 
const int MaxB = 1e4 + 10; 
const int INF = ~0u >> 1; 

struct cyxPair
{
    int delta, count; 
    cyxPair() {}
    cyxPair(const int &d, const int &c):
        delta(d), count(c) {}
    inline bool operator < (const cyxPair &rhs) const
    {
        return delta < rhs.delta; 
    }
}c[MaxM]; 

int n, m, b; 
int a[MaxM], h[MaxN], c0[MaxM]; 
int minAns = INF, numAns; 

#define p(x, y) cyxPair(x, y)

int main()
{
    read(m), read(b), read(h[0]), read(n); 
    for (int i = 1; i <= m; ++i) read(a[i]); 
    for (int i = 1; i <= n; ++i) read(h[i]); 
    for (int i = 1; i <= m; ++i) read(c0[i]); 
    
    int totCount, totAns, tmp;  
    for (int now = 1; now <= n; ++now)
    {
        static int i; 
        totCount = b, totAns = 0; 
        for (i = 1; i <= m; ++i)
            read(tmp), c[i] = p(c0[i] - tmp, a[i]), totAns += tmp * a[i]; 
        std::sort(c + 1, c + m + 1); 
        for (i = 1; i <= m; ++i)
            if (totCount >= c[i].count)
                totCount -= c[i].count, totAns += c[i].delta * c[i].count; 
            else
                break; 
        if (totCount > 0)
            totAns += totCount * c[i].delta; //当我们有剩余的煤要送但不满该煤矿总量，我们也要将剩下的送出
        totAns += h[0] + h[now]; 
        if (totAns < minAns)
            minAns = totAns, numAns = now; 
    }
    printf("%d\n%d\n", numAns, minAns); 
    return 0; 
}
