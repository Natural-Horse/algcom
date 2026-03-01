#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;

struct Edge{
	int nxt,to;
}ed[2000005];

int n;
int head[1000005],tot;
int dep[1000005];
int cnt[1000005];
int dp[1000005];
long long ans=-inf,plc;

void add_edge(int u,int v){
	ed[++tot].nxt=head[u];
	ed[tot].to=v;
	head[u]=tot;
}

void dfs1(int u,int fa){
//	bool check=false;
	dp[u]=0;
	for(int i=head[u];i;i=ed[i].nxt){
		int v=ed[i].to;
		if(v==fa) continue;
//		check=true;
		dep[v]=dep[u]+1;
		dfs1(v,u);
		cnt[u]+=cnt[v];	
		dp[u]+=dp[v]+cnt[v];
	}
//	if(check==false){
//		cnt[u]=1;
//		dp[u]=1;
//	}
}

void dfs2(int u,int fa){
	for(int i=head[u];i;i=ed[i].nxt){
		int v=ed[i].to;
		if(v==fa) continue;
		dp[v]=dp[u]+cnt[u]-2*cnt[v];
		cnt[v]=cnt[u];
//		if(ans<dp[v]){
//			plc=v;
//			ans=dp[v];
//		}
		dfs2(v,u);
	}
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n-1;i++){
		int u,v;
		scanf("%d %d",&u,&v);
		add_edge(u,v);
		add_edge(v,u);
		cnt[i]=1;
	}
	cnt[n]=1;
	dep[1]=1;
	ans=dp[1];
	plc=1;
	dfs1(1,0);
	dfs2(1,0);
	for(int i=1;i<=n;i++){
		if(dp[i]>ans){
			ans=dp[i];
			plc=i;
		}
	}
	printf("%lld",plc);
	return 0;
} 
