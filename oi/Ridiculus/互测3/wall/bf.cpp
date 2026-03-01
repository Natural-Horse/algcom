#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
#define db double
using namespace std;

inline ll read(){
	ll x = 0, f = 1; char ch = getchar();
	while(!isdigit(ch)){if(ch == '-') f = -1; ch = getchar();}
	while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - 48; ch = getchar();}
	return x * f;
}

const ll N = 1e6 + 5, mod = 1e13;

int n, m, q, k;
ll w[N], las;
vector<int> s[N];

int main(){
    freopen("data.in", "r", stdin);
    freopen("ans.out", "w", stdout);
    n = read(), m = read(), q = read(), k = read();
    for(int i = 1; i <= n; i++) w[i] = read();
    for(int i = 1, u, v; i <= m; i++){
        u = read(), v = read();
        if(u != v) s[u].push_back(v), s[v].push_back(u);
    }
    for(int i = 1; i <= n; i++){
        sort(s[i].begin(), s[i].end());
        s[i].erase(unique(s[i].begin(), s[i].end()), s[i].end());
    }
    for(int i = 1, op, u; i <= q; i++){
        ll x;
        op = read(), u = read(), x = read();
        x = (x + k*las%mod) % mod;
        if(op == 1){
            w[u] = w[u] + x;
        }
        else{
            ll res = 0;
            int sz = s[u].size();
            for(int j = 0; j < sz; j++) res = (res + w[s[u][j]]) % x;
            printf("%lld\n", res % x);
            las = res;
        }
    }
    return 0;
}

