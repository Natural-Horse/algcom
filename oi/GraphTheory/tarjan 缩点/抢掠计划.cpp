#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;

struct Edge{
	int nxt,to;
}ed[500005];

struct EDge{
	int nxt,to,len;
}ed_[500005];

int n,m;
int head[500005],tot,head_[500005],tot_;
int w[500005],w_[500005];
int s,pp;
bool b[500005],bb[500005];
int dfn[500005],low[500005],num;
int vis[500005];
int st[500005],top;
int p[500005],cnt;
int dp[500005];
int ans;
queue<int> q;

void add_edge(int u,int v){
	ed[++tot].nxt=head[u];
	ed[tot].to=v;
	head[u]=tot;
}

void add_edge_(int u,int v,int ww){
	ed_[++tot_].nxt=head_[u];
	ed_[tot_].to=v;	
	ed_[tot_].len=ww;
	head_[u]=tot_;
}

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
		else if(vis[v]){
			low[u]=min(low[u],dfn[v]);
		}
	}
	if(low[u]==dfn[u]){
		cnt++;
		do{
			int y=st[top];
			p[y]=cnt;
			vis[y]=0;
			w_[cnt]+=w[y];
		}while(st[top--]!=u);
		dp[cnt]=w_[cnt];
	}
}

int dis[500005];

void spfa(){
	for(int i=1;i<=cnt;i++){
		dis[i]=-inf;
	}
	dis[p[s]]=w_[p[s]];
	q.push(p[s]);
	vis[p[s]]=2;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		vis[u]=0;
		for(int i=head_[u];i;i=ed_[i].nxt){
			int v=ed_[i].to;
			int w=ed_[i].len;
			if(dis[v]<dis[u]+w){
				dis[v]=dis[u]+w;
				if(bb[v]==true) ans=max(ans,dis[v]);
				if(!vis[v]){
					q.push(v);
					vis[v]=2;
				}
			}
		}
	}
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,u,v;i<=m;i++){
		scanf("%d%d",&u,&v);
		add_edge(u,v);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&w[i]);
	}
	scanf("%d %d",&s,&pp);
	for(int i=1,a;i<=pp;i++){
		scanf("%d",&a);
		b[a]=true;
	}
	for(int i=1;i<=n;i++){
		if(!dfn[i]) tarjan(i);
	}
	for(int i=1;i<=n;i++){
		if(b[i]==true) bb[p[i]]=true;
		for(int j=head[i];j;j=ed[j].nxt){
			int v=ed[j].to;
			if(p[i]!=p[v]){
				add_edge_(p[i],p[v],w_[p[v]]);
			}
		}
	}
	spfa();
	printf("%d",ans);
	return 0;
} 
