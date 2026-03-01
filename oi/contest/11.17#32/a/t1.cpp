#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
#define int long long
using namespace std;

inline int read(){
    int x = 0, f = 1; char ch = getchar();
    while(!isdigit(ch)){if(ch == '-') f = -1; ch = getchar();}
    while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - 48; ch = getchar();}
    return x * f;
}

const int N = 1e5 + 5;

int n, w, a[N], ansa, ansb;

ll get_min(){
    if(w >= a[n]) return w - a[1];
    else if(a[1] <= w && w <= a[n]) return a[n] - a[1];
    else return a[n] - w;
}
ll get_max(int d){
    int tmp = w, l = 1, r = n, res = 0;
    for(int i = 1; i <= n; i++){
        if(i % 2 == d){
            res += max(abs(a[l]-w), abs(a[l]-tmp));
            tmp = a[l], l++;
        }
        else {
            res += max(abs(a[r]-w), abs(a[r]-tmp));
            tmp = a[r], r--;
        }
    }
    return res;
}

signed main(){
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    n = read(), w = read();
    for(int i = 1; i <= n; i++) a[i] = read();
    sort(a + 1, a + 1 + n);
    ansa = get_min();
    ansb = max(get_max(0), get_max(1));
    printf("%lld %lld\n", ansa, ansb);
}

