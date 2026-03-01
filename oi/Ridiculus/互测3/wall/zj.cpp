#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define db double
using namespace std;
#define int __int128
#define ll __int128
#define LL long long

inline ll read(){
	ll x = 0, f = 1; char ch = getchar();
	while(!isdigit(ch)){if(ch == '-') f = -1; ch = getchar();}
	while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - 48; ch = getchar();}
	return x * f;
}

const ll N = 1e6 + 5, mod = 1e13;

int n, m, q, k;
ll w[N], p[N], las;
bool b[N];
vector<int> s[N], v[N];

signed main(){
     freopen("a.in", "r", stdin);
     freopen("a.ans", "w", stdout);
    n = read(), m = read(), q = read(), k = read();
    int jud = 0;
    for(int i = 1; i <= n; i++) w[i] = read();
    for(int i = 1, u, v; i <= m; i++){
        u = read(), v = read();
        s[u].push_back(v), s[v].push_back(u);
    }
    for(int i = 1; i <= n; i++){
        sort(s[i].begin(), s[i].end());
        s[i].erase(unique(s[i].begin(), s[i].end()), s[i].end());
        int sz = s[i].size();
        jud = max(jud, sqrt((LL)sz));
    }
    for(int i = 1; i <= n; i++){
        int sz = s[i].size();
        sz < jud ? b[i] = true : b[i] = false;
    }
    for(int i = 1; i <= n; i++){
        int sz = s[i].size();
        for(int j = 0; j < sz; j++){
            if(!b[s[i][j]]) v[i].push_back(s[i][j]);
            else p[i] = p[i] + w[s[i][j]];
        }
    }
    for(int i = 1, op, u; i <= q; i++){
        ll x;
        op = read(), u = read(), x = read();
        x = (x + las * k % mod) % mod;
        if(op == 1){
            if(b[u]){
                int sz = s[u].size();
                for(int j = 0; j < sz; j++) p[s[u][j]] = p[s[u][j]] + x;
            }
            else w[u] = w[u] + x;
        }
        else{
            ll res = p[u] % x;
            int sz = v[u].size();
            for(int j = 0; j < sz; j++) res = (res + w[v[u][j]]) % x;
            printf("%lld\n", (LL)res);
            las = res;
        }
    }
    return 0;
}
