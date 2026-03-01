// clang-format off
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f3f3f3f3f
#define ll long long
using namespace std;

inline ll read(){
    ll x = 0, f = 1; char ch = getchar();
    while(!isdigit(ch)){if(ch == '-') f = -1; ch = getchar();}
    while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - 48; ch = getchar();}
    return x * f;
}

const int N = 1e3 + 5;

ll T, n, h[N][N], a[N], b[N];
ll ans, f1[N][2], f2[N][2];

bool check(bool ish, int idx, int lasadd){
    if(ish){
        for(int i = 1; i <= n; i++)
            if(h[idx][i] == h[idx-1][i] + lasadd) return false;
        return true;
    }
    else{
        for(int i = 1; i <= n; i++)
            if(h[i][idx] == h[i][idx-1] + lasadd) return false;
        return true;
    }
}

int main(){
    T = read();
    while(T--){
        memset(f1, 0x3f, sizeof f1);
        memset(f2, 0x3f, sizeof f2);
        ans = 0;
        n = read();
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                h[i][j] = read();
            }
        }
        for(int i = 1; i <= n; i++) a[i] = read();
        for(int i = 1; i <= n; i++) b[i] = read(); 
        f1[1][0] = 0, f1[1][1] = a[1];
        bool jud = false;
        for(int i = 2; i <= n; i++){
            jud = false;
            if(check(1, i, 0)) f1[i][0] = min(f1[i][0], f1[i-1][0]), f1[i][1] = min(f1[i][1], f1[i-1][1] + a[i]), jud = true;
            if(check(1, i, 1)) f1[i][0] = min(f1[i][0], f1[i-1][1]), jud = true;
            if(check(1, i, -1)) f1[i][1] = min(f1[i][1], f1[i-1][0] + a[i]), jud = true;
            // if(!jud) break;
        }
        // if(!jud){printf("-1\n"); continue;}
        f2[1][0] = 0, f2[1][1] = b[1];
        for(int i = 2; i <= n; i++){
            jud = false;
            if(check(0, i, 0)) f2[i][0] = min(f2[i][0], f2[i-1][0]), f2[i][1] = min(f2[i][1], f2[i-1][1] + b[i]), jud = true;
            if(check(0, i, 1)) f2[i][0] = min(f2[i][0], f2[i-1][1]), jud = true;
            if(check(0, i, -1)) f2[i][1] = min(f2[i][1], f2[i-1][0] + b[i]), jud = true;
            // if(!jud) break;
        }
        // if(!jud){printf("-1\n"); continue;}
        ans = min(f1[n][0], f1[n][1]) + min(f2[n][0], f2[n][1]);
        if(ans >= inf) printf("-1\n");
        else cout << ans << endl;
    }
    return 0;
}