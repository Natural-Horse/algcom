#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

inline int read(){
	int x = 0, f = 1; char ch = getchar();
	while(!isdigit(ch)){if(ch == '-') f = -1; ch = getchar();}
	while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - 48; ch = getchar();}
	return x * f;
}

const int N = 1e6 + 5;

struct List{
	int l, r;
}pos[N];
ll n, k, a[N], ans;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
bool vis[N];

void del(int x){
	pos[pos[x].l].r = pos[x].r;
	pos[pos[x].r].l = pos[x].l;
	pos[x].l = pos[x].r = 0;
	vis[x] = false;
}

int main(){
	n = read(), k = read();
	for(int i = 1; i <= n; i++) a[i] = read();
	for(int i = 1; i < n; i++){
		q.push(make_pair(a[i+1]-a[i], i));
		if(i == 1) pos[i].l = 0, pos[i].r = 2;
		else if(i == n-1) pos[i].l = n-2, pos[i].r = 0;
		else pos[i].l = i-1, pos[i].r = i+1;
		vis[i] = true;
	}
	for(int i = 1; i < n; i++) a[i] = a[i+1] - a[i];
	a[0] = a[n] = inf;
	for(int i = 1; i <= k; i++){
		while(!vis[q.top().second]) q.pop();
		pair<int,int> u = q.top(); q.pop();
		int plc = u.second; 
		int x = pos[plc].l, y = pos[plc].r;
		ll val = u.first; ans += val;
		q.push(make_pair(a[y]+a[x]-a[plc], plc));
		a[plc] = a[y] + a[x] - a[plc];
		del(x), del(y);
	}
	printf("%lld\n", ans);
	return 0;
}

