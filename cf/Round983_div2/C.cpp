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
int T, n, a[N], cnt;
multiset<int> s;

signed main(){
    T = read();
    while(T--){
        if(!s.empty()) s.clear();
        n = read(); cnt = 0;
        for(int i = 1; i <= n; i++){
            a[i] = read();
            s.insert(a[i]);
        }
        int t1 = *s.begin(), t3 = *s.rbegin();
        s.erase(s.begin());
        int t2 = *s.begin();
        while(t1 + t2 <= t3){
            t1 = *s.lower_bound(t3 - t2 + 1);
            s.insert(t1);
            cnt++;
            t1 = *s.begin(), t3 = *s.rbegin();
            s.erase(s.begin());
            t2 = *s.begin();

        }
        printf("%lld\n", cnt);
    }
    return 0;
}