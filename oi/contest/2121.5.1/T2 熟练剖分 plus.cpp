#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
#define ri register long long
#define ld long double
using namespace std;

const int Maxn = 5e3 + 5;
const int mod = 1e9 + 7;

ll n;
ll root;
vector<int> son[Maxn];
bool b[Maxn], bb[Maxn]; 
ll ans;

ll f[Maxn][Maxn];
ll g[Maxn], h[Maxn];
ll size[Maxn];

ll qp(ll x, ll idx){
	ll res = 1;
	while(idx){
		if(idx & 1) res = (res * x) % mod;
		x = (x * x) % mod;
		idx >>= 1;
	}
	return res;
}

void dfs(int u){
	ll jud = son[u].size();
	ll q = qp(jud, mod - 2);
    size[u] = 1;
	for(ri i = 0; i < son[u].size(); i++){
		ll v = son[u][i];
		dfs(v);
		size[u] += size[v];
	}
	for(ri i = 0; i < son[u].size(); i++){
		ll v = son[u][i];
		for(ri j = 0; j <= n; j++) g[j] = 1;
		for(ri j = 0; j < son[u].size(); j++){
			for(ri k = 0; k <= size[son[u][j]] + 1; k++){
				ll gs = g[k]; if(k) gs -= g[k-1];
				ll fs = f[son[u][j]][k]; if(k) fs -= f[son[u][j]][k-1];
				if(v == son[u][j]){
					h[k] = ((gs * f[son[u][j]][k] % mod + fs * g[k] % mod - gs * fs % mod) % mod + mod) % mod;
				}
				else if(k){
					fs = f[son[u][j]][k-1]; if(k > 1) fs -= f[son[u][j]][k-2];
					h[k] = ((fs * g[k] % mod + gs * f[son[u][j]][k-1] % mod - gs * fs % mod) % mod + mod) % mod;
				}
			}
			g[0] = h[0], h[0] = 0;
			for(ri k = 1; k <= size[son[u][j]] + 1; k++){
				g[k] = (g[k-1] + h[k]) % mod;
				h[k] = 0;
			}
		}
		for(ri j = size[u]; j >= 1; --j){
			g[j] = (g[j] - g[j-1] + mod) % mod;
		}
		for(ri j = 0; j <= size[u]; j++){
			f[u][j] = (f[u][j] + g[j] * q % mod) % mod;
		}
	}
	if(!son[u].size()){
		f[u][0] = 1;
	}
	for(ri i = 1; i <= n; i++){
		f[u][i] = (f[u][i-1] + f[u][i]) % mod;
	}
}

int main(){
	scanf("%lld", &n);
	for(ri i = 1, k; i <= n; i++){
		scanf("%lld", &k);
		for(ri j = 1, v; j <= k; j++){
			scanf("%lld", &v);
			son[i].push_back(v);
			b[v] = true;
			bb[i] = true;
		}
	}
	int cnt = 0;
	for(ri i = 1; i <= n; i++){
		if(!b[i]) root = i;
		if(bb[i]) cnt++;
	}
	if(cnt == 1){
		printf("1");
		return 0;
	}
	dfs(root);
	for(ll i = 1; i <= n; i++){
		ans = ((ans + (f[root][i] - f[root][i-1] + mod) * i % mod) % mod) % mod;
	}
	printf("%lld", ans);
	return 0;
} 
