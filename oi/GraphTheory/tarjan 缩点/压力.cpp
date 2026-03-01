#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;

struct Edge{
	int nxt,to;
}ed[400005],ed_[400005];

int n,m,q;
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
int root;
int st[100005],top;
int cnt,cut[100005];
vector<int> dcc[100005];

void tarjan(int u){
	dfn[u]=low[u]=++num;
	st[++top]=u;
	int flag=0;
	for(int i=head[u];i;i=ed[i].nxt){
		int v=ed[i].to;
		if(!dfn[v]){
			tarjan(v);
			low[u]=min(low[u],low[v]);
			if(dfn[u]<=low[v]){
				flag++;
				cnt++;
				int y=0;
				do{
					y=st[top];
					dcc[cnt].push_back(y);
				}while(st[top--]!=v);
				dcc[cnt].push_back(u);
			}
		}
		else low[u]=min(low[u],dfn[v]);
	}
}

bool re=false;
int ans[100005];

void dfs(int u,int fa,int tim){
	if(u==tim){
		ans[u]++;
		re=true;
		return;
	}
	for(int i=head_[u];i;i=ed_[i].nxt){
		int v=ed_[i].to;
		if(v==fa) continue;
		dfs(v,u,tim);
		if(re){
			ans[u]++;
			return;
		}
	}
}

int main(){
	scanf("%d %d %d",&n,&m,&q);
	for(int i=1,u,v;i<=m;i++){
		scanf("%d %d",&u,&v);
		add_edge(u,v);
		add_edge(v,u);
	}
	for(int i=1;i<=n;i++){
		if(!dfn[i]){
			root=i;
			tarjan(i);
		}
	}
	for(int i=1;i<=cnt;i++){
		for(int j=0;j<dcc[i].size();j++){
			add_edge_(dcc[i][j],i+n);
			add_edge_(i+n,dcc[i][j]);
			
		}
	}
	for(int i=1,from,to;i<=q;i++){
		scanf("%d %d",&from,&to);
		dfs(from,0,to);
		re=false;
	}
	for(int i=1;i<=n;i++){
		printf("%d\n",ans[i]);
	}
	return 0;
}
