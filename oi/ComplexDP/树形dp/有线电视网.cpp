#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;

struct Edge{
	int nxt,to,len;
}ed[6005];

int n,m;
int head[3005],tot;
int dp[3005][3005];
int maxn;
int ans; 

void add_edge(int u,int v,int w){
	ed[++tot].nxt=head[u];
	ed[tot].to=v;
	ed[tot].len=w;
	head[u]=tot;
}
		
void dfs2(int u,int fa){
	for(int i=head[u];i;i=ed[i].nxt){
		int v=ed[i].to;
		if(v==fa) continue;
		int w=ed[i].len;
		dfs2(v,u);
		for(int j=m;j>=0;--j){
			for(int k=0;k<=j;k++){
				dp[u][j]=max(dp[u][j],dp[u][j-k]+dp[v][k]-w);
			}
		}
	}
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,k;i<=n-m;i++){
		scanf("%d",&k);
		for(int j=1,v,w;j<=k;j++){
			scanf("%d%d",&v,&w);
			add_edge(i,v,w);
			add_edge(v,i,w);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			dp[i][j]=-inf;
		}
	}
	for(int i=n-m+1,mon;i<=n;i++){
		scanf("%d",&mon);
		dp[i][1]=mon; 
		maxn+=mon;
	}	
	dfs2(1,0);
	for(int i=m;i>=0;i--){
		if(dp[1][i]>=0){
			ans=i;
			break;
		}
	}
	printf("%d",ans);
	return 0;
} 
