#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long 
using namespace std;

const int n = 3e6;

struct Node{
	int pos, dis;
	int tim;
}sp[n + 5];

int t, tot;
int fa[n + 5];

int find(int x){
	if(fa[x] == x) return x;
	else{
		int fab = find(fa[x]);
		if(sp[x].tim != sp[fa[x]].tim){
			sp[x].pos += sp[fa[x]].pos - 1;
			sp[x].dis = sp[fa[x]].dis;
			sp[x].tim = sp[fa[x]].tim;
		} 
		fa[x] = fab;
		return fa[x];
	} 
}

void merge(int x, int y){
	fa[x] = find(x);
	fa[y] = find(y);
	sp[fa[y]].tim = ++tot;
	sp[fa[x]].pos += sp[fa[y]].dis;
	sp[fa[x]].dis = sp[fa[y]].dis = sp[fa[x]].dis + sp[fa[y]].dis;
	fa[find(x)] = find(y);
}

int main(){
	scanf("%d", &t);
	for(int i = 1; i <= n; i++){
		fa[i] = i;
		sp[i] = (Node){1, 1};
	}
	for(int i = 1; i <= t; i++){
		char op;
		int u, v;
		scanf("\n%c", &op);
		scanf("%d %d", &u, &v);
		if(op == 'M'){
			merge(u, v);
		}
		if(op == 'C'){
			if(find(u) != find(v)){
				printf("-1\n");
			}
			else{
				int ans = abs(sp[u].pos - sp[v].pos) - 1;
				printf("%d\n", ans);
			}
		}
	}
	return 0;
} 
