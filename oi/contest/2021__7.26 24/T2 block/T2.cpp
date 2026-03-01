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

const int N = 22;

int n;
int v[N], k[N], pre[N], ans;
bool b[N];
pair<int,int> nd[N];
int q[N], cnt, ansq[N];

void dfs(int u){
	if(u > n){
		ans++;
		if(ans == 1){
			for(int i = 1; i <= cnt; i++){
				ansq[i] = q[i];
			}
		}
		return;
	}
	for(int i = 1; i <= n; i++){
		if(b[i]) continue;
		if(nd[i].first > pre[nd[i].second]){
			for(int j = 1; j <= nd[i].second; j++){
				pre[j]++;
			}
			b[i] = true;
			q[++cnt] = i;
			dfs(u+1);
			--cnt;
			b[i] = false;
			for(int j = 1; j <= nd[i].second; j++){
				pre[j]--;
			}
		}
	}
}

int main(){
	n = read();
	for(int i = 1; i <= n; i++){
		k[i] = read(), v[i] = read();
		nd[i] = make_pair(k[i], v[i]);
	} 
	sort(nd + 1, nd + 1 + n);
	dfs(1);
	printf("%d\n", ans);
	for(int i = 1; i <= n; i++){
		printf("%d %d\n", k[ansq[i]], v[ansq[i]]);
	}
	return 0;
}

