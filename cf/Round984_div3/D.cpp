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

const int N = 2e3 + 5;

int T, n, m, cnt, ans;
char a[N][N], las[5], tmp[N << 2];

bool check(){
    if(las[1] == '1' && las[2] == '5' && las[3] == '4' && las[4] == '3') return true;
    else return false;
}

int main(){
    // freopen("ans.out", "w", stdout);
    T = read();
    while (T--){
        ans = 0, cnt = 0;
        n = read(), m = read();
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                a[i][j] = getchar();
            }
            getchar();
        }
        for(int l = 1; l <= min((n + 1) >> 1, (m + 1) >> 1); l++){
            cnt = 0;
            int x = l, y = l, len = 0;
            bool fab1 = false, fab2 = false, fab3 = false;
            for(y = l; y <= m - l + 1; y++){
                tmp[++len] = a[x][y];
                if(cnt < 3){las[++cnt] = a[x][y]; continue;}
                las[4] = a[x][y];
                if(check()) ans++;
                las[1] = las[2], las[2] = las[3], las[3] = las[4], las[4] = 0;
            }
            y--;
            for(x = l + 1; x <= n - l + 1; x++){
                fab1 = true;
                tmp[++len] = a[x][y];
                if(cnt < 3){las[++cnt] = a[x][y]; continue;}
                las[4] = a[x][y];
                if(check()) ans++;
                las[1] = las[2], las[2] = las[3], las[3] = las[4], las[4] = 0;
            }
            x--;
            for(y = m - l; y >= l && fab1 == true; --y){
                fab2 = true;
                tmp[++len] = a[x][y];
                if(cnt < 3){las[++cnt] = a[x][y]; continue;}
                las[4] = a[x][y];
                if(check()) ans++;
                las[1] = las[2], las[2] = las[3], las[3] = las[4], las[4] = 0;
            }
            y++;
            for(x = n - l; x > l && fab2 == true; --x){
                fab3 = true;
                tmp[++len] = a[x][y];
                if(cnt < 3){las[++cnt] = a[x][y]; continue;}
                las[4] = a[x][y];
                if(check()) ans++;
                las[1] = las[2], las[2] = las[3], las[3] = las[4], las[4] = 0;
            }
            x++;
            for(int i = len - 2; i <= len && (fab1 && fab2); i++){
                int plc1 = (i % len == 0 ? len : i % len);
                int plc2 = ((i+1) % len == 0 ? len : (i+1) % len);
                int plc3 = ((i+2) % len == 0 ? len : (i+2) % len);
                int plc4 = ((i+3) % len == 0 ? len : (i+3) % len);
                las[1] = tmp[plc1], las[2] = tmp[plc2];
                las[3] = tmp[plc3], las[4] = tmp[plc4];
                if(check()) ans++;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}