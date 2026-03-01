#include<bits/stdc++.h>
#define inf 0x3f3f3f
using namespace std;

const int Maxn = 505;

struct Node{
	int x, y;
};

struct Dom{
	int st, re, len;
}d[Maxn];

int n, m; 
int h[5] = {0, 0, 1, 0, -1};
int l[5] = {0, 1, 0, -1, 0};
int a[Maxn][Maxn];
bool b[Maxn], vis[Maxn];
int st[Maxn], re[Maxn];
queue<Node> q;
vector<int> v[Maxn];
int cnt, ans;
int tot[Maxn];

bool cmp(Dom aa, Dom bb){
	return aa.len < bb.len;
}

void bfs(int pos){
	q.push((Node){1, pos});
	while(!q.empty()){
		Node nd = q.front();
		q.pop();
		int xx = nd.x, yy = nd.y;
		if(xx == n){						
			if(!vis[yy]){
				vis[yy] = true;
				cnt++;
			}
			v[pos].push_back(yy);
		}		
		for(int i = 1; i <= 4; i++){			
			int hh = xx + h[i], ll = yy + l[i];
			if(a[hh][ll] >= a[xx][yy] || hh < 1 || hh > n || ll < 1 || ll > m) continue;
			q.push((Node){hh, ll});				
		}
	}
}

int main(){
	freopen("P1514_2.in", "r", stdin);
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			scanf("%d", &a[i][j]);
		}
	}
	for(int i = 1; i <= m; i++){
		d[i].st = inf;
	}
	for(int i = 1; i <= m; i++){
		bfs(i);
	}
	if(cnt != m){
		printf("0\n%d", m - cnt);
		return 0;
	}
	
	printf("1\n%d", ans);
	return 0;
} 
