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

const int N = 205;

int n, p;
ll f[N][N], g[N][N], ans, inv[N];  
//g[i][j] i个点的森林,深度不超过j的概率
//f[i][j] i个点的树,深度不超过j的概率 
int main(){
	n = read(), p = read();
	inv[1] = inv[0] = 1;
	for(int i = 2; i <= n; i++) inv[i] = inv[p%i] * (p-p/i) % p;
	for(int i = 0; i <= n; i++) g[0][i] = 1; 
	for(int i = 1; i <= n; i++){
		for(int j = 0; j <= n; j++){
			if(j) f[i][j] = g[i-1][j-1];
			else if(i == 1) f[i][j] = 1;
			for(int k = 1; k <= i; k++){
				g[i][j] = (g[i][j] + g[i-k][j]*f[k][j]%p*inv[i]%p)%p; 
			}
		}
	}
	for(int i = 1; i <= n; i++){
		ans = (ans + (f[n][i]-f[n][i-1]+p)%p * i %p)%p;
	}
	printf("%lld", ans);
	return 0;
}

