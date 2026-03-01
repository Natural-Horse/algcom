#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;

struct Edge{
	int nxt,to;
}ed[400005],ed_[400005];

int n,m;
int head[100005],tot,head_[200005],tot_;

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

int dfn[100005],low[100005],num;
int st[100005],top;
int root,cnt,all;
int cut[100005];
long long siz[200005],w[200005];

void tarjan(int u){
	dfn[u]=low[u]=++num;
	st[++top]=u;
	all++;
	int flag;
	for(int i=head[u];i;i=ed[i].nxt){
		int v=ed[i].to;
		if(!dfn[v]){
			tarjan(v);
			low[u]=min(low[u],low[v]);
			if(dfn[u]<=low[v]){
				cnt++;
				flag++;
				if(u!=root || flag>1){
					cut[u]=1;
				}
				int y=0;
				do{
					y=st[top];
					w[cnt]++;
					add_edge_(y,cnt);
					add_edge_(cnt,y);
				}while(st[top--]!=v);
				add_edge_(cnt,u);
				add_edge_(u,cnt);	
				w[cnt]++;		
			}
		}
		else low[u]=min(low[u],dfn[v]);
	}
}

long long ans;

void dfs(int u,int fa){
	if(u<=n) siz[u]=1;
	for(int i=head_[u];i;i=ed_[i].nxt){
		int v=ed_[i].to;
		if(v==fa) continue;
		dfs(v,u);
		ans+=2*w[u]*siz[u]*siz[v];
		siz[u]+=siz[v];
	}
	ans+=2*w[u]*siz[u]*(all-siz[u]);
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,u,v;i<=m;i++){
		scanf("%d%d",&u,&v);
		add_edge(u,v);
		add_edge(v,u);
		w[u]=w[v]=-1;
	}
	cnt=n;
	for(int i=1;i<=n;i++){
		if(!dfn[i]){			
			all=0;
			root=i;
			tarjan(i);
			top--;
			dfs(i,0);
		}
	}
	printf("%lld",ans);
	return 0;
}
