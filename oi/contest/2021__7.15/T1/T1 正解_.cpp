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
	for(int i = 1; i <= k; i++){
		x[i] = read(), y[i] = read();
		dis[i] = (db)y[i];
	} 
	dis[k+1] = m;
	vis[0] = true;
	for(int i = 1; i <= k + 1; i++){
		db flag = inf;
		int plc = 0;
		for(int j = 1; j <= k+1; j++)
			if(!vis[j] && dis[j] < flag) 
				flag = dis[j], plc = j;
		vis[plc] = true;
		maxn = max(maxn, dis[plc]);
		if(plc == k + 1) break;		
		for(int j = 1; j <= k; j++)
			if(!vis[j])
				dis[j] = min(dis[j], sqrt(((db)x[plc]-(db)x[j]) * ((db)x[plc]-(db)x[j]) + ((db)y[plc]-(db)y[j]) * ((db)y[plc]-(db)y[j])));
		if(!vis[k+1]) dis[k+1] = min(dis[k+1], (db)(m - y[plc]));
	}
	printf("%.8lf", maxn * 0.5);
	return 0;
}
