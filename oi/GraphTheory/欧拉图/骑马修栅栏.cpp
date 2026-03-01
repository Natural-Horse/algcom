#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

const int Maxn = 1005;

int m, n;
int a[Maxn][Maxn];
int d[Maxn];
int way[2100], cnt;

void dfs(int u){
	for(int v = 1; v <= n; v++){
		if(a[u][v] >= 1){
			a[u][v]--;
			a[v][u]--;
			dfs(v);
		}		
	}
	way[++cnt] = u;
}

int main(){
//	freopen("P2731_8.in", "r", stdin);
//	freopen("1", "w", stdout);
	scanf("%d", &m);
	for(int i = 1, u, v; i <= m; i++){
		scanf("%d %d", &u, &v);
		a[u][v]++;
		a[v][u]++;
		d[u]++, d[v]++;
		n = max(n, max(u, v));
	}
	int st = 1; 
	for(int i = 1; i <= n; i++){
		if(d[i] % 2){
			st = i;
			break;
		}
	}
	dfs(st);
//	printf("%d", cnt);
	for(int i = cnt; i >= 1; --i){
		printf("%d\n", way[i]);
	}
	return 0;
}
