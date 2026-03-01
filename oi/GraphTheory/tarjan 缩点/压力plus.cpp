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
int st[100005],top;
int cnt;
int root;
vector<int> dcc[100005];

void tarjan(int u){
	dfn[u]=low[u]=++num;
	st[++top]=u;
	for(int i=head[u];i;i=ed[i].nxt){
		int v=ed[i].to;
		if(!dfn[v]){
			tarjan(v);
			low[u]=min(low[u],low[v]);
			if(dfn[u]<=low[v]){
				cnt++;
				int y=0;
				do{
					y=st[top];
					dcc[cnt].push_back(y);
					add_edge_(y,cnt+n);
					add_edge_(cnt+n,y);
				}while(st[top--]!=v);
				dcc[cnt].push_back(u);
				add_edge_(u,cnt+n);
				add_edge_(cnt+n,u);
			}
		}
		else low[u]=min(low[u],dfn[v]);
	}
}

struct Quest{
	int from,to,lca;
}qst[100005];

struct Node{
	int to,num;
};

int f[200005],fa[200005];
int vis[200005];
vector<Node> p[200005];
int diff[200005];
int ans[200005];

int find(int x){
	if(f[x]==x) return x;
	else return f[x]=find(f[x]);
}

void merge(int u,int v){
	f[find(u)]=find(v);
}

void LCA(int u,int father){
	f[u]=u;
	vis[u]=1;
	for(int i=head_[u];i;i=ed_[i].nxt){
		int v=ed_[i].to;
		if(v==father) continue;		
		fa[v]=u;
		LCA(v,u);
		merge(v,u);
	}
	for(int i=0;i<p[u].size();i++){
		Node x=p[u][i];
		int num=x.num;
		int v=x.to;
		if(vis[v]){
			qst[num].lca=find(v);
		}
	}
}

void dfs(int u,int father){
	ans[u]=diff[u];
	for(int i=head_[u];i;i=ed_[i].nxt){
		int v=ed_[i].to;
		if(v==father) continue;
		dfs(v,u);
		ans[u]+=ans[v];
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
	for(int i=1,from,to;i<=q;i++){		
		scanf("%d %d",&from,&to);	
		qst[i].from=from,qst[i].to=to;
		p[from].push_back((Node){to,i});
		p[to].push_back((Node){from,i});
	}
	LCA(1,0);
	for(int i=1;i<=q;i++){
		int u=qst[i].from;
		int v=qst[i].to;
		int anc=qst[i].lca;
		diff[u]++,diff[v]++,diff[anc]--,diff[fa[anc]]--;
	}	
	dfs(1,0);
	for(int i=1;i<=n;i++){
		printf("%d\n",ans[i]);
	}
	return 0;
}
