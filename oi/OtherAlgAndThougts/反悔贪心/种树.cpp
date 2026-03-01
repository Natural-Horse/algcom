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
ll n, m, a[N], ans;
bool vis[N];
priority_queue<pair<int,int>> q;

void del(int x){
	pos[pos[x].l].r = pos[x].r;
	pos[pos[x].r].l = pos[x].l;
	vis[x] = false, pos[x] = {0, 0};
}

int main(){
	n = read(), m = read();
	for(int i = 1; i <= n; i++){
		a[i] = read();
		if(i == 1) pos[i].l = n, pos[i].r = 2;
		else if(i == n) pos[i].l = n-1, pos[i].r = 1;
		else pos[i].l = i-1, pos[i].r = i+1;
		q.push(make_pair(a[i], i));
		vis[i] = true;
	}
	if(m * 2 > n){
		printf("Error!\n");
		return 0;
	}
	for(int i = 1; i <= m; i++){
		while(!vis[q.top().second]) q.pop();
		pair<int, int> u = q.top(); q.pop();
		ll plc = u.second, val = u.first;
		ans += val;
		int x = pos[plc].l, y = pos[plc].r;
		q.push(make_pair(a[x] + a[y] - a[plc], plc));
		a[plc] = a[x] + a[y] - a[plc];
		del(x), del(y);
	}
	printf("%lld\n", ans);
	return 0;
}

