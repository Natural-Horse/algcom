#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;

struct Edge{
	int nxt,to;
}ed[10005];

int n,m;
int head[5005],tot;
int q[5005],plc;
bool ed[5005][5005];

void dfs(int u,int fa){
	int jud=inf;
	for(int i=1;i<=5005;i++){
		int v=ed
		if(v==fa || ) continue;
		dfs(v,u);
		jud=min(jud,v);
	}
	q[++plc]=jud;
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,u,v;i<=m;i++){
		scanf("%d%d",&u,&v);
		ed[u][v]=true;
		ed[v][u]=true;
	}
	q[++plc]=1;
	dfs(1,0);
	for(int i=plc;i>=1;--i){
		printf("%d ",q[i]);
	}
	return 0;
}
