// clang-format off
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
#define pii pair<int, int>
#define mkp make_pair
#define int long long
using namespace std;

inline int read(){
    int x = 0, f = 1; char ch = getchar();
    while(!isdigit(ch)){if(f == '-') f = -1; ch = getchar();}
    while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - 48; ch = getchar();}
    return x * f;
}

const int N = 2e5 + 5; 
int T, n, m, L, l[N], r[N], x[N], v[N];
int ans;
priority_queue<pii> q;


signed main(){
    // freopen("1.out", "w", stdout);
    T = read();
    // (int i = 1; i <= 200; i++) printf("%d : %d\n", i, pre[i]);
    while(T--){
        n = read(), m = read(), L = read();
        ans = 0;
        while(!q.empty()) q.pop();
        for(int i = 1; i <= n; i++){
            l[i] = read(), r[i] = read();
        }
        for(int i = 1; i <= m; i++){
            x[i] = read(), v[i] = read();
        }
        int p = 1;
        bool check = false;
        int sum = 1;
        for(int i = 1; i <= n; i++){
            int k = upper_bound(x + 1, x + 1 + m, l[i] - 1) - x - 1;
            for(; p <= k; p++) q.push(mkp(v[p], x[p]));
            // p++;
            while(sum < r[i] - l[i] + 2 && !q.empty()){
                sum += q.top().first;
                q.pop();
                ans++;
            }
            if(sum < r[i] - l[i] + 2){
                printf("-1\n");
                check = true;
                break;
            }
            // else sum -= (r[i] - l[i] + 2);
        }
        if(check) continue;
        printf("%lld\n", ans);
    }
    return 0;
}