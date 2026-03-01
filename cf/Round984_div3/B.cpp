// clang-format off
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
#define pii pair<int, int>
using namespace std;

inline int read(){
    int x = 0, f = 1; char ch = getchar();
    while (!isdigit(ch)){if (f == '-') f = -1; ch = getchar();}
    while (isdigit(ch)){x = (x << 3) + (x << 1) + ch - 48; ch = getchar();}
    return x * f;
}

const int N = 2e5 + 5;

int T, n, k, b[N], c[N], maxb;
int cost[N], ans;

bool cmp(int aa, int bb){return aa > bb;}

int main(){
    T = read();
    while (T--){
        n = read(), k = read();
        ans = maxb = 0;
        memset(cost, 0, sizeof cost);
        for(int i = 1; i <= k; i++){
            b[i] = read(), c[i] = read();
            cost[b[i]] += c[i];
            maxb = max(maxb, b[i]);
        }
        sort(cost + 1, cost + 1 + maxb, cmp);
        for(int i = 1; i <= n && i <= maxb; i++){
            ans += cost[i];
        }
        printf("%d\n", ans);
    }
    return 0;
}