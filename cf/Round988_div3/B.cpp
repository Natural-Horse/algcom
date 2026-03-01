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
int b[N];

signed main(){
    // freopen("1.out", "w", stdout);
    T = read();
    while(T--){
        n = read();
        ans = 0;
        for(int i = 1; i <= n; i++){
            a[i] = read(); b[a[i]]++;
        }
        bool check = false;
        sort(a + 1, a + 1 + n);
        for(int i = 1; i <= n; i++){
            if((n - 2) % a[i] == 0 && b[(n-2)/a[i]] >= 1){
                cout << a[i] << ' ' << (n-2) / a[i] << endl;
                check = true;
                break;
            }
        }
        for(int i = 1; i <= n; i++) b[i] = 0;
        if(check)  continue;

    }
    return 0;
}