#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

const int Maxn = 1e6+5;

struct Card{
	int a, b;
}c[Maxn];

int n, m;
int ans = inf;

bool cmp(Card aa, Card bb){
	return aa.a < bb.a;
}

void dfs(int cnt, int l, int r, int rana, int ranb, int maxn, int minn){
	int juda = c[l].b - c[l].a;
	int judb = c[r].a - c[r].b;
	ans = min(ans, maxn - minn);
	if(r == l + 1 || r == l || cnt == m || (juda <= 0 && judb <= 0)){		
		return;
	}
	if(judb > 0 && judb > juda){
		int prea = rana, preb = ranb;
		ranb = max(ranb, c[r].b);
		rana = min(rana, c[r].b);
		maxn = max(c[r-1].a, ranb);
		minn = min(c[l].a, rana);
		dfs(cnt + 1, l, r - 1, rana, ranb, maxn, minn);
		ranb = preb, rana = prea;
	}
	else if(juda > 0){
		int prea = rana, preb = ranb;
		ranb = max(ranb, c[l].b);
		rana = min(rana, c[l].b);
		maxn = max(c[r].a, ranb);
		minn = min(c[l+1].a, rana);
		dfs(cnt + 1, l + 1, r, rana, ranb, maxn, minn);
		ranb = preb, rana = prea;
	}
}

int main(){
//	freopen("card.in", "r", stdin);
//	freopen("card.out", "w", stdout);
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++){
		scanf("%d", &c[i].a);
	}
	for(int i = 1; i <= n; i++){
		scanf("%d", &c[i].b);
	}
	sort(c + 1, c + 1 + n, cmp);
	dfs(0, 1, n, inf, 0, c[n].a, c[1].a);
	printf("%d", ans);
	return 0;
} 
