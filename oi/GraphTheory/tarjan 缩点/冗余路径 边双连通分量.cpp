#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

struct Edge{
	int nxt,to;
}ed[20005],ed_[20005];

int n,m;
int head[5005],tot=1,head_[5005],tot_;

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

int dfn[5005],low[5005],num;
int st[5005],top;
int p[5005],cnt=1;
int ecc[20005];
vector<int> root;

void tarjan(int u,int ine){
	if(p[u]==0) p[u]=1;
	dfn[u]=low[u]=++num;
	st[++top]=u;
	for(int i=head[u];i;i=ed[i].nxt){
		int v=ed[i].to;
		if(!dfn[v]){
			tarjan(v,i);
			low[u]=min(low[u],low[v]);
			if(low[v]>dfn[u]){
				cnt++;
				ecc[i]=ecc[i^1]=1;
				int y=0;
				do{
					y=st[top];
					p[y]=cnt;
				}while(st[top--]!=v);
			}
		}
		else if(i!=(1^ine)) low[u]=min(low[u],dfn[v]);
	}
}

int in[5005];

void build(){
	for(int i=2;i<=tot;i++){
		if(ecc[i]==1){
			int u=p[ed[i].to];
			int v=p[ed[i^1].to];
			add_edge_(u,v);
			in[u]++;
		}
	}
}

ll ans; 
ll leaf;

void dfs(int u,int fa){
	bool check=false;
	for(int i=head_[u];i;i=ed_[i].nxt){
		int v=ed_[i].to;
		if(v==fa) continue;
		dfs(v,u);
		check=true;
	}
	if(check==false) leaf++;
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		add_edge(u,v);
		add_edge(v,u);
	}
	for(int i=1;i<=n;i++){
		if(!dfn[i]){
			tarjan(i,0);
			root.push_back(i);
		}
	}
	build();
	for(int i=1;i<=cnt;i++){
		if(in[i]==1) leaf++;
	}
	ans+=(leaf+1)/2;
	printf("%lld",ans);
	return 0;
} 
