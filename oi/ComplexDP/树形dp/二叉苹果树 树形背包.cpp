#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;

struct Edge{
	int nxt,to,len; 
}ed[205];

int n,q;
int head[105],tot;
int dp[105][105];

void add_edge(int u,int v,int w){
	ed[++tot].nxt=head[u];
	ed[tot].to=v;
	ed[tot].len=w;
	head[u]=tot;
}

void dfs(int u,int fa){
	for(int i=head[u];i;i=ed[i].nxt){
		int v=ed[i].to;
		if(v==fa) continue;
		int w=ed[i].len;
		dfs(v,u);
		for(int j=q;j>=1;j--){
			for(int k=j-1;k>=0;k--){
				dp[u][j]=max(dp[u][j],w+dp[v][k]+dp[u][j-k-1]);
			}
		}
	}
}

int main(){
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n-1;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		add_edge(u,v,w);
		add_edge(v,u,w);
	}
	dfs(1,0);
	printf("%d",dp[1][q]);
	return 0;
}
