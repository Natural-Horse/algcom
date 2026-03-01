#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

inline int read(){
    int x = 0, f = 1; char ch = getchar();
    while(!isdigit(ch)){if(ch == '-') f = -1; ch = getchar();}
    while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - 48; ch = getchar();}
    return x * f;
}

const int N = 20;

int n, p[N * N + 5], cnt, a[N * N + 5], b[N * N + 5];
ll d[N][N], f[1 << N], ans;

int main(){
    n = read();
    for(int i = 1; i < n; i++){
        for(int j = i+1; j <= n; j++) d[i][j] = d[j][i] = read();
    }
    for(int i = 1; i < n; i++){
        for(int j = i+1; j <= n; j++){
            p[++cnt] = (1 << (i-1)) + (1 << (j-1));
            a[cnt] = i, b[cnt] = j;
        }
    }
    f[0] = 0;
    for(int i = 1; i < (1 << n); i++){
        for(int j = 1; j <= cnt; j++){
            if((i & p[j]) == p[j]) f[i] = max(f[i], f[i-p[j]] + d[a[j]][b[j]]);
            ans = max(ans, f[i]);
        }
    }
    printf("%lld\n", ans);
    return 0;
}