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
int cut[100005];
int st[100005],top;
int cnt;
int root;
vector<int> dcc[100005];
vector<int> vdcc;

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
					if(cut[u]==0) vdcc.push_back(u);
					cut[u]=true;										
				}
				int y=0;
//				printf("第%d个点双：",cnt);
				do{
					y=st[top];
					dcc[cnt].push_back(y);
//					printf("%d ",y);
				}while(st[top--]!=v);
				dcc[cnt].push_back(u);
//				printf("%d\n",u);
			}
		}
		else low[u]=min(low[u],dfn[v]);
	}
}

int siz[200005];
ll ans[200005];

void dfs1(int u,int fa){
	bool check=false;	
	for(int i=head_[u];i;i=ed_[i].nxt){
		int v=ed_[i].to;
		if(v==fa) continue;
		dfs1(v,u);
		if(u>cnt){
			siz[u]+=siz[v];
			ans[u]+=((ll)siz[v])*((ll)n-(ll)siz[v]-1);
		}
		if(u<=cnt){
			siz[u]+=siz[v];
		}
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
	for(int i=1;i<=cnt;i++){
//		printf("\n第%d个点双：",i);
		siz[i]=dcc[i].size();
		for(int j=0;j<dcc[i].size();j++){
			if(cut[dcc[i][j]]==1){
				siz[dcc[i][j]+1+cnt]=1;
				siz[i]--;
				ans[dcc[i][j]+1+cnt]=2*(n-1);
				add_edge_(i,dcc[i][j]+cnt+1);
				add_edge_(dcc[i][j]+cnt+1,i);
			}
		}
	}
	dfs1(1,0);
	for(int i=0;i<vdcc.size();i++){
		int u=vdcc[i]+1+cnt;
		ans[u]+=((ll)n-(ll)siz[u])*((ll)siz[u]-1);
	}
	for(int i=1;i<=n;i++){
		if(cut[i]==0) printf("%d\n",(n-1)*2);
		else printf("%lld\n",ans[i+1+cnt]);
	}
	return 0;
}
