#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

const int Maxn = 2e5+5;

struct Pos{
	int l, r;
}pos[Maxn];

struct Node{
	int r;
	bool operator < (const Node &x) const{
		return r > x.r;
	}
};

int n, m;
int l[Maxn], r[Maxn];
bool b[2 * Maxn];
priority_queue<Node> q;
int cnt;

bool cmp(Pos a, Pos b){
	return a.l > b.l;
}

int main(){
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++){
		scanf("%d %d", &pos[i].l, &pos[i].r);
	}
	for(int i = 1; i <= m; i++){
		b[i] = true;
	}
	sort(pos + 1, pos + 1 + n, cmp);
	for(int i = 1; i <= n; i++){	
		
	}
	printf("%d", cnt);
	return 0;
} 
