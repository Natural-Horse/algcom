// clang-format off
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
#define pii pair<int, int>
#define mkp make_pair
// #define int long long
using namespace std;

inline int read(){
    int x = 0, f = 1; char ch = getchar();
    while(!isdigit(ch)){if(f == '-') f = -1; ch = getchar();}
    while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - 48; ch = getchar();}
    return x * f;
}

const int N = 1e4 + 5; 
int T, n, cnt[3], s[N], ans[N];


signed main(){
    // freopen("1.out", "w", stdout);
    T = read();
    // (int i = 1; i <= 200; i++) printf("%d : %d\n", i, pre[i]);
    while(T--){
        // memset(s, 0x3f, sizeof s);
        cnt[0] = cnt[1] = 0;
        n = read();
        // int jud = 0, las = 0;
        int plc = 0;
        for(int i = 1; i < n; i++){
            printf("? %d %d\n", i, n);
            fflush(stdout);
            cin >> ans[i];
            if(!plc && ans[i] == 0) plc = i;
            if(i == 1) continue;
            if(ans[i-1] - ans[i] == 0){
                cnt[1]++, s[i-1] = 1;
            }
            else{
                cnt[0]++, s[i-1] = 0;
            }
            // las = jud;
        }
        int jud = 0;
        for(int i = plc; i; --i){
            if(ans[i] > 0){jud = ans[i]; break;}
        }
    }
    return 0;
}