// clang-format off
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
#define int long long
using namespace std;

inline int read(){
    int x = 0, f = 1; char ch = getchar();
    while(!isdigit(ch)){if(f == '-') f = -1; ch = getchar();}
    while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - 48; ch = getchar();}
    return x * f;
}

const int N = 2e5 + 5; 
int T, n, a[N], ans;

signed main(){
    // freopen("1.out", "w", stdout);
    T = read();
    while(T--){
        n = read(); ans = inf;
        for(int i = 1; i <= n; i++) a[i] = read();
        sort(a + 1, a + 1 + n);
        if(n == 3 && a[1] + a[2] <= a[3]){
            cout << 1 << endl;
            continue;
        }
        for(int i = 1, k = 3; i <= n-2; i++){
            int j = i + 1; bool check = false;
            while(a[k] < a[i] + a[j] && k <= n) k++, check = true; 
            if(!check) continue;
            k--;
            ans = min(ans, i - 1 + n - k);
        }
        cout << ans << endl;
    }
    return 0;
}