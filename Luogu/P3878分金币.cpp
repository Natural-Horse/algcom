#include <bits/stdc++.h>
#define inf LONG_LONG_MAX
#define ll long long 
using namespace std;

inline ll read(){
    ll x = 0, f = 1; char ch = getchar();
    while(!isdigit(ch)){if(ch == '-') f = -1; ch = getchar();}
    while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - 48; ch = getchar();}
    return x * f;
}

const int N = 35, M = 1e6 + 5;

struct Nd{
    ll cnt;
    ll val;
    void clear(){cnt = 0; val = 0;}
    bool operator < (const Nd &bb) const{
        if(cnt == bb.cnt) return val < bb.val;
        else return cnt < bb.cnt;
    }
}nd[M];

int n, T;
ll val[M], tot, seg[N][2];
ll vis[M], ans;

Nd getval(int s){
    ll res = 0, pt = 1, cnt = 0;
    while(s){res += (s & 1) * val[pt]; cnt += (s & 1), s >>= 1, pt++;}
    return (Nd){cnt, res};
}

void reset(){
    tot = 0;
    for(int i = 1; i <= n; i++) seg[i][0] = inf, seg[i][1] = -1;
    ans = inf;
}

void init(){
    for(int s = 0; s <= (1 << (n/2)) - 1; s++){
        nd[s] = getval(s);
    }
    sort(nd + 1, nd + 1 + (1 << (n / 2)) - 1);
    for(int i = 0; i <= (1 << (n/2)) - 1; i++){
        seg[nd[i].cnt][0] = min(seg[nd[i].cnt][0], (ll)i);
        seg[nd[i].cnt][1] = max(seg[nd[i].cnt][1], (ll)i);
    }
}

void dfs(int s){
    if(s >= (1 << (n / 2 + (n & 1)))) return;
    Nd tmpr = getval(s << (n / 2));
    int ptl = lower_bound(nd + seg[n/2-tmpr.cnt][0], nd + seg[n/2-tmpr.cnt][1], (Nd){n / 2 - tmpr.cnt, tot / 2 - tmpr.val}) - nd;
    Nd tmpl = nd[ptl];
    ll tmp_ans = abs(((tmpl.val + tmpr.val) << 1) - tot);
    ans = min(ans, tmp_ans);
    // vis[s] = min(vis[s], tmp_ans);
    dfs(s + 1);
}

int main(){
    T = read();
    while(T--){
        n = read();
        reset();
        for(int i = 1; i <= n; i++){
            val[i] = read();
            tot += val[i];
        }
        init();
        dfs(0);
        printf("%lld\n", ans);
    }
    return 0;
}