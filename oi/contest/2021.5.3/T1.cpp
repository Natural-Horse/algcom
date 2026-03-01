#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

const int Maxn = 1e5 + 5;

struct Edge{
	int nxt, to;
}ed[Maxn * 2];

int n, m;
int head[Maxn], tot;

void add_edge(int u, int v){
	ed[++tot].nxt = head[u];
	ed[tot].to = v;
	head[u] = tot;
}

int fa[Maxn];
int cnt, cnt_;

int find(int x){
	if(x == fa[x]) return x;
	else return fa[x] = find(fa[x]);
}

void merge(int x, int y){
	fa[find(x)] = find(y);
}

int self[Maxn], d[Maxn];
ll ans1, ans2, ans3;

int main(){
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++){
		fa[i] = i;
	}
	for(int i = 1, u, v; i <= m; i++){
		scanf("%d %d", &u, &v);
		add_edge(u, v);
		add_edge(v, u);
		if(v != u) d[u]++, d[v]++, cnt++;
		else cnt_++;
		self[u]++, self[v]++;
		merge(u, v);
	}
	int jud = 0;
	for(int i = 1; i <= n; i++){
        if(self[i]){
            jud = find(i);
            break;
        }
    }
    for(int i = 1; i <= n; i++){
        if(jud != find(i) && self[i]){
            printf("0\n");
            return 0;
        }
    }
	for(int i = 1; i <= n; i++){
		ans1 += (ll)d[i] * (ll)(d[i] - 1) / 2;
	}
	ans2 = cnt * cnt_;
	ans3 = cnt_ * (cnt_ - 1) / 2;
	ll ans = ans1 + ans2 + ans3;
	printf("%lld", ans);
	return 0;
}
