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

const int N = 20, M = 105;

int n, m, k;
int c[M][N], r[M], cnt[M];
ll ans;

int main(){
    n = read(), m = read(), k = read();
    for(int i = 1; i <= m; i++){
        int p = read();
        for(int j = 1; j <= p; j++) {
            int fab = read();
            c[i][fab] = 1;
        }
        char cc = getchar();
        cc == 'o' ? r[i] = 1 : r[i] = 0;
    }
    for(int state = 0; state <= (1 << n) - 1; state++){
        for(int i = state, j = 1; i ; i >>= 1, j++){
            int jud = i & 1;
            for(int p = 1; p <= m; p++){
                if(c[p][j] == 1 && jud == 1) cnt[p]++;
            }
        }
        bool check = true;
        for(int i = 1; i <= m; i++){
            if((cnt[i] >= k && !r[i]) || (cnt[i] < k && r[i])){check = false; break;}
        }
        if(check) ans++;
        for(int i = 1; i <= m; i++) cnt[i] = 0;
    }
    printf("%lld\n", ans);
    return 0;
}