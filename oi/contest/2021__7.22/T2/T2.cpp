#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

int read(){
	int x = 0,f = 1;char ch = getchar();
	while (ch < '0' || ch > '9'){if (ch == '-') f = -1; ch = getchar();}
	while (ch >= '0' && ch <= '9'){x = x*10 + ch - 48; ch = getchar();}
	return x * f;
}

const int N = 2e5 + 5;

int n, m, k;
ll a[N], b[N], na, nb, w[N];
bool vis[N], d[N], aa[N], bb[N];
vector<ll> ti;
ll ans;

void dfs(int u, int sum1, int sum2, int tot, ll val){
	if(sum1 >= k && sum2 >= k && tot == m){
		ans = min(ans, val);
		return;
	}
	if(u > n) return;
	if(d[u]) dfs(u+1, sum1+1, sum2+1, tot+1, val+w[u]);
	else if(aa[u]) dfs(u+1, sum1+1, sum2, tot+1, val+w[u]);
	else if(bb[u]) dfs(u+1, sum1, sum2+1, tot+1, val+w[u]);
	else dfs(u+1, sum1, sum2, tot+1, val+w[u]);
	dfs(u+1, sum1, sum2, tot, val);
}

int main(){
	n = read(), m = read(), k = read();
	for(int i = 1; i <= n; i++) w[i] = read();
	na = read();
	for(int i = 1; i <= na; i++){
		a[i] = read(), vis[a[i]] = true;
		aa[a[i]] = true;
	}
	nb = read();
	for(int i = 1; i <= nb; i++){
		b[i] = read();
		if(vis[b[i]]) ti.push_back(b[i]), d[i] = true;
		vis[b[i]] = true;
		bb[b[i]] = true;
	}
	if(n <= 20){
		ans = inf;
		dfs(1, 0, 0, 0, 0);
		printf("%lld", ans);
		return 0;
	}
	else if(!ti.size()){
		ans = 0;
		sort(a + 1, a + 1 + na);
		sort(b + 1, b + 1 + nb);
		for(int i = 1; i <= k; i++) ans += a[i] + b[i];
		printf("%lld", ans);
		return 0;
	} 
	else{
		printf("-1");
		return 0;
	}
}

