#include <bits/stdc++.h>
#include <algorithm>
#define inf 0x7fffffff
#define ll long long 
#define db double
#define int long long
using namespace std;

inline int read(){
    int x = 0, f = 1; char ch = getchar();
    while(!isdigit(ch)){if(ch == '-') f = -1; ch = getchar();}
    while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - 48; ch = getchar();}
    return x * f;
}

const int N = 2e5 + 5;

int n, T, h, d, ans;

void reset(){
    ans = inf;
}

void pre_work(){

}

int check(ll x){
    // x 总段数
    ll len = d / x;
    // if(len * x < d) len++;
    // x = seg_cnt + (d % len == 0);
    ll long_seg_cnt = d - x * len;
    ll wound_total = (1 + len) * len / 2 * x + long_seg_cnt * (len + 1);
    return d + max(x - 1, wound_total - h + 1);
}

void solve(){
    int l = 1, r = d;
    // if(l)
    // cout << check(r) << endl;
    // for(int i = l; i <= r; i++) cout << check(i) << " ";
    while(l + 2 < r){
        int seg = (r - l) / 3;
        int pt1 = l + seg, pt2 = r - seg;
        int c1 = check(pt1);
        int c2 = check(pt2);
        if(c1 > c2) ans = min(ans, c2), l = pt1;
        else if(c1 < c2) ans = min(ans, c1), r = pt2;
        else l = pt1, r = pt2;
    }
    ans = min(ans, check(l));
    ans = min(ans, check(r));
    ans = min(ans, check(l + 1));
}

signed main(){
    T = read();
    int count = T;
    while(T--){
        h = read(), d = read();
        reset();
        solve();
        // printf("Test %d : ", count - T);
        printf("%lld\n", ans);
    }
    return 0;
}