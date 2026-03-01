#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

struct Edge{
	int nxt,to;
}ed[1000005],ed_[1000005];

int n,m;
int head[100005],tot,head_[100005],tot_;

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
int cut[100005],cut_[100005];
int st[100005],top;
int p[100005],cnt;
int root;
vector<int> vdcc[100005];
vector<int> dcc[100005];
vector<int> fab;

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
				if(u!=root || flag>1){
					cut[u]=true;					
					fab.push_back(u);
				}
				int y=0;
				do{
					y=st[top];
					dcc[cnt].push_back(y);
				}while(st[top--]!=v);
				vdcc[u].push_back(cnt);
				dcc[cnt].push_back(u);
			}
		}
		else low[u]=min(low[u],dfn[v]);
	}
}

int siz[200005];
ll ans[200005];

void dfs(int u,int fa){
	bool check=false;
	for(int i=head_[u];i;i=ed_[i].nxt){
		int v=ed_[i].to;
		if(v==fa) continue;
		dfs(v,u);
		check=true;
		if(u>cnt){
			siz[u]+=siz[v];
			ans[u]+=((ll)siz[v]-1)*((ll)n-(ll)siz[v]-1)*2;
		}
		if(u<=cnt){
			siz[u]+=siz[v];
		}
	}
	if(check==false){
		siz[u]=dcc[u].size();
	}
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,u,v;i<=m;i++){
		scanf("%d%d",&u,&v);
		add_edge(u,v);
		add_edge(v,u);
	}
	for(int i=1;i<=n;i++){
		if(!dfn[i]){
			root=i;
			tarjan(i);
		}
	}
	for(int i=0;i<fab.size();i++){
		ans[fab[i]+1+cnt]=2*(n-1);
		for(int j=0;j<vdcc[fab[i]].size();j++){
			add_edge_(fab[i]+1+cnt,vdcc[fab[i]][j]);
			add_edge_(vdcc[fab[i]][j],fab[i]+1+cnt);
		}
	}
	dfs(1,0);
	for(int i=1;i<=n;i++){
		if(cut[i]==0) printf("%d\n",(n-1)*2);
		else printf("%lld\n",ans[i+1+cnt]);
	}
	return 0;
}
