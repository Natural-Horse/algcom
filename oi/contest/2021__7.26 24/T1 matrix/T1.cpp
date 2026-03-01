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

const int N = 12;

int n, m, a[N][N], w[N][N]; 
int f[N][1 << N][1 << N], b[N], s[N][1 << N], ans = inf;
vector<int> g[N][1 << N];

void init(){
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(a[i][j]) b[i] |= 1 << (j-1);
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < (1 << m); j++){
			int jud = 0;
			for(int k = 0; k < m; k++){
				if((1 << k) & j) jud += w[i][k+1];
			}
			s[i][j] = jud;
		}
	}
	for(int i = 0; i < (1 << m); i++){
		g[0][i].push_back((1<<m)-1);
		f[0][i][(1<<m)-1] = 0;
	} 
}

int main(){
	n = read(), m = read();
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++) scanf("%1d", &a[i][j]);
	}
	for(int i = 1; i <= n; i++){
		for(int j = m; j >= 1; --j) w[i][j] = read();
	}
	memset(f, 0x3f, sizeof(f));
	init();
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < (1 << m); j++){
			for(int k = 0; k < (1 << m); k++){
				for(int l = 0; l < g[i-1][k].size(); l++){
					int las = g[i-1][k][l];
					int se = j | ((1<<m)-1-las);
					int val = inf;
					val = min(val, s[i][se] + f[i-1][k][las]);
					int jud = 0;
					jud = jud | b[i] | se | (se >> 1);
					if(se != 0){
						jud = jud | (se << 1) & ((1 << m) - 1);
					}
					if(i != 1) jud |= k;
					if(i == n){
						if(jud == (1<<m)-1) ans = min(ans, val);
					}
					g[i][se].push_back(jud);
					f[i][se][jud] = val;
				}
			}
		}
	}
	printf("%d", ans);
	return 0;
}

