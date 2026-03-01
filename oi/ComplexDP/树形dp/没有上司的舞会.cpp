#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;

struct Edge{
	int nxt,to;
}ed[12005];

int n,r[6005];
int head[6005],tot;
int dp[6005][2];
int ans;

void add_edge(int u,int v){
	ed[++tot].nxt=head[u];
	ed[tot].to=v;
	head[u]=tot;
}

void dfs(int u,int fa){
	dp[u][0]=0;
	for(int i=head[u];i;i=ed[i].nxt){
		int v=ed[i].to;
		if(v==fa) continue;
		dfs(v,u);
		dp[u][0]+=max(dp[v][1],dp[v][0]);
//		ans=max(ans,dp[u][0]);
		dp[u][1]+=dp[v][0];
//		ans=max(ans,dp[u][1]);
	}
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&r[i]);
		dp[i][1]=r[i];
//		dp[i][0]=0;
	}
	for(int i=1,u,v;i<=n-1;i++){
		scanf("%d %d",&u,&v);
		add_edge(v,u);
		add_edge(u,v);	
	}
	dfs(1,0);
	printf("%d",max(dp[1][0],dp[1][1]));
	return 0;
} 
