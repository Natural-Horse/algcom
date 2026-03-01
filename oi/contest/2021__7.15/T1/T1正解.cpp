#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
#define db double
using namespace std;

int read(){
	int x = 0,f = 1;char ch = getchar();
	while (ch < '0' || ch > '9'){if (ch == '-') f = -1; ch = getchar();}
	while (ch >= '0' && ch <= '9'){x = x*10 + ch - 48; ch = getchar();}
	return x * f;
}

const int N = 6e4 + 5;

struct Node{
	db di;
	int num;
	bool operator < (const Node &x) const{
		return di > x.di;
	}
};

priority_queue<Node> q;

int n, m, k;
int x[N], y[N];
bool vis[N], check;
db dis[N];
db maxn;

db dist(db x1, db x2, db y1, db y2){
	return sqrt((x2-x1) * (x2-x1) + (y2-y1) * (y2-y1));
}

int main(){
	n = read(), m = read(), k = read();
	db flag = inf;
	int plcc = 0;
	for(int i = 1; i <= k; i++){
		x[i] = read(), y[i] = read();
		dis[i] = (db)y[i];
		if(dis[i] < flag) {
			flag = dis[i], plcc = i;
		}
	} 
	dis[k+1] = m;
	vis[0] = true;
	q.push((Node){dis[plcc], plcc});
	while(!q.empty()){
		Node xx = q.top();
		q.pop();
		int plc = xx.num;
		if(vis[plc]) continue;
		vis[plc] = true;
		maxn = max(maxn, dis[plc]);
		if(plc == k+1) break;
		for(int j = 1; j <= k; j++){
			if(vis[j]) continue;
			db d = dist((db)x[plc], (db)x[j], (db)y[plc], (db)y[j]);
			dis[j] = min(dis[j], max(dis[plc], d));
			q.push((Node){dis[j], j});
		}
		dis[k+1] = min(dis[k+1], (db)(m - y[plc]));
		q.push((Node){dis[k+1], k+1});
	}
	printf("%.8lf", maxn * 0.5);
	return 0;
}
