#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long 
using namespace std;

struct Edge{
	int nxt,to;
}ed[4000005],ed_[4000005];

int n;
int head[2005],tot,head_[2005],tot_;

void add_edge(int u,int v){
	ed[++tot].nxt=head[u];
	ed[tot].to=v;
	head[u]=tot;
}

void add_edge_(int u,int v){
	ed_[++tot_].nxt=head_[u];
	ed_[tot_].to=v;
	head_[u]=tot_;
}

int dfn[2005],low[2005],num;
int st[2005],top;
int vis[2005];
int p[2005],cnt;
int siz[2005];

void tarjan(int u){
	dfn[u]=low[u]=++num;
	vis[u]=1;
	st[++top]=u;
	for(int i=head[u];i;i=ed[i].nxt){
		int v=ed[i].to;
		if(!dfn[v]){
			tarjan(v);
			low[u]=min(low[u],low[v]);
		}
		else if(vis[v]) low[u]=min(low[u],dfn[v]);
	}
	if(dfn[u]==low[u]){
		int y=0;
		cnt++;
		do{
			y=st[top];
			p[y]=cnt;
			vis[y]=0;
			siz[cnt]++;
		}while(st[top--]!=u);
	} 
}

ll ans;
int check[2005];
ll sum[2005];

void dfs(int u,int tim){
	sum[tim]+=siz[u];
	for(int i=head_[u];i;i=ed_[i].nxt){
		int v=ed_[i].to;
		if(check[v]==tim) continue;
		check[v]=tim;
		dfs(v,tim);		
	}
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("\n");
		for(int j=1;j<=n;j++){
			char cc;
			scanf("%c",&cc);
			if(cc=='1') add_edge(i,j);
		}
	}
	for(int i=1;i<=n;i++){
		if(!dfn[i]){
			tarjan(i);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=head[i];j;j=ed[j].nxt){
			int v=ed[j].to;
			if(p[i]!=p[v]){
//				dp[p[i]]=siz[p[i]];
//				dp[p[v]]=siz[p[v]];
				add_edge_(p[i],p[v]);
			}
		}
	}
//	toposort();
	for(int i=1;i<=n;i++){
		if(sum[p[i]]!=0){
			ans+=sum[p[i]];
			continue;
		}		
		dfs(p[i],p[i]);
		ans+=sum[p[i]];
	}
	printf("%lld",ans);
	return 0;
} 
