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

const int N = 405, M = 5e4 + 5;

int n, m, a[N], b[N];
bool f[N];
bitset<N> g[N];
ll ans;

int main(){
	n = read(), m = read();
	for(int i = 1; i <= m; i++) a[i] = read(), b[i] = read();
	for(int i = 1; i <= n; i++){
		g[i][i] = true;
		f[i] = true; 
		for(int j = m; j >= 1; --j){
			if(g[i][a[j]] && g[i][b[j]]){f[i] = false; break;}
			g[i][a[j]] = g[i][b[j]] = g[i][a[j]] | g[i][b[j]];
		}
	}
	for(int i = 1; i <= n; i++){
		if(f[i]){
			for(int j = i+1; j <= n; j++){
				if(f[j] && (g[i] & g[j])==0) ans++;
			}
		}
	}
	printf("%lld", ans);
	return 0;
}

