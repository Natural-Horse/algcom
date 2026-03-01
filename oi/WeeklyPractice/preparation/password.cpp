#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

const int Maxn = 1e5 + 5;
const int Maxm = 105;

int n, m, k;
int x[Maxn], b[Maxn];
int dis[30][Maxn];
bool vis[Maxn];
int f[(1 << 20) + 5];
int num[30], plc[30], cnt;
int e[Maxn], st, jud;

queue<int> q;

void spfa(){
	for(int i = 1; i <= cnt; i++){
		memset(vis, false, sizeof(vis));
		dis[num[i]][plc[i]] = 0;
		vis[plc[i]] = true;
		q.push(plc[i]);
		while(!q.empty()){
			int u = q.front();
			q.pop();
			vis[u] = false;
			for(int j = 1; j <= k; j++){
				if(u - e[j] >= 0 && dis[num[i]][u-e[j]] > dis[num[i]][u] + 1){
					dis[num[i]][u-e[j]] = dis[num[i]][u] + 1;
					if(!vis[u-e[j]]){
						vis[u-e[j]] = true;
						q.push(u-e[j]);
					}
				}
				if(u + e[j] <= n && dis[num[i]][u+e[j]] > dis[num[i]][u] + 1){
					dis[num[i]][u+e[j]] = dis[num[i]][u] + 1;
					if(!vis[u+e[j]]){
						vis[u+e[j]] = true;
						q.push(u+e[j]);
					}
				}
			}
		}
	}
}

int main(){
	scanf("%d %d %d", &n, &m, &k);
	for(int i = 1; i <= m; i++){
		int jud;
		scanf("%d", &jud);
		x[jud] = 1;
	}
	for(int i = 1; i <= k; i++) scanf("%d", &e[i]);
	for(int i = 0; i <= n; i++){
		x[i] = x[i] ^ x[i+1];
	} 	
	for(int i = 0; i <= n; i++){
		if(x[i]){
			cnt++;
			num[cnt] = cnt;
			plc[cnt] = i;
		}
	}
	int lim = (1 << cnt) - 1;
	memset(dis, inf, sizeof(dis));
	spfa();
	memset(f, inf, sizeof(f));
	f[0] = 0;
	for(int i = 0; i <= lim; i++){
		int juda = 1, judb = 1;
		while((i >> (juda-1)) & 1) juda++;
		for(judb = juda + 1; judb <= cnt; judb++){
			if(!((i >> (judb-1)) & 1)){
				f[i|(1 << (juda-1))|(1 << (judb-1))] = min(f[i|(1 << (juda-1))|(1 << (judb-1))], f[i] + dis[juda][plc[judb]]);
			}
		}
	}
	if(f[lim] >= inf) printf("-1");
	else printf("%d", f[lim]);
	return 0;
} 
