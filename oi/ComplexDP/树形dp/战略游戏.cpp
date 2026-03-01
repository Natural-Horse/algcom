#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;

struct Edge{
	int nxt,to;
}ed[3005];

int n;
int head[1505],tot;
int dp[1505][2];

void add_edge(int u,int v){
	ed[++tot].nxt=head[u];
	ed[tot].to=v;
	head[u]=tot;
}

void dfs(int u,int fa){
	for(int i=head[u];i;i=ed[i].nxt){
		int v=ed[i].to;
		if(v==fa) continue;
		dfs(v,u);
		dp[u][1]+=min(dp[v][0],dp[v][1]);
		dp[u][0]+=dp[v][1];
	}
}

int main(){
	scanf("%d",&n); 
	for(int i=1,u,k;i<=n;i++){
		scanf("%d%d",&u,&k);
		u++;
		for(int j=1,v;j<=k;j++){
			scanf("%d",&v);
			v++;
			add_edge(u,v);
			add_edge(v,u);
		}
		dp[u][1]=1;
	}
	dp[n][1]=1;
	dfs(1,0);
	printf("%d",min(dp[1][0],dp[1][1]));
	return 0;
}
