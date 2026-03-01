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

const int N = 505, M = 5e4 + 5;

struct Edge{
	int nxt, to;
}ed[M << 1];
int n, m, head[N], tot, pre[N];
ll cnt;

void add_edge(int u, int v){
	ed[++tot].nxt = head[u]; ed[tot].to = v; head[u] = tot;
}

int main(){
	n = read(), m = read();
	for(int i = 1, u, v; i <= m; i++){
		u = read(), v = read();
		pre[u]++, pre[v]++;
	}
	for(int i = 1; i <= n; i++){
		if(pre[i] == 1) cnt++;
	}
	ll ans = cnt * (cnt-1) / 2;
	printf("%lld", ans);
	return 0;
}

