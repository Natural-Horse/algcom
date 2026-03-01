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
int cnt, ans;

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
			d[pos].st = min(d[pos].st, yy);
			d[pos].re = max(d[pos].re, yy);
			if(!vis[yy]){
				vis[yy] = true;
				cnt++;
			}
		}		
		for(int i = 1; i <= 4; i++){			
			int hh = xx + h[i], ll = yy + l[i];
			if(a[hh][ll] >= a[xx][yy] || hh < 1 || hh > n || ll < 1 || ll > m) continue;
			q.push((Node){hh, ll});				
		}	
	}
}

int main(){
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
	for(int i = 1; i <= m; i++){
		if(d[i].re == 0 && d[i].st == inf){
			d[i].len = 0;
			continue;
		} 
		if(d[i].re == 0) d[i].re = d[i].st;
		if(d[i].st == inf) d[i].st = d[i].re;	
		d[i].len = d[i].re - d[i].st + 1;
	}
	sort(d + 1, d + 1 + m, cmp);
	for(int i = 1; i <= m; i++){
		if(d[i].len == 0) continue;
		ans++;
		b[i] = true;
		for(int j = 1; j < i; j++){			
			if(d[i].st <= d[j].st && d[i].re >= d[j].re && b[j]){
				b[j] = false;
				ans--;
			}
		}
	}
	printf("1\n%d", ans);
	return 0;
}
