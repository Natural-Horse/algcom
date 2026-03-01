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
int vis[100005];
int root;
vector<int> dcc[100005];
int siz[200005];
ll ans[200005];

void tarjan(int u){
	dfn[u]=low[u]=++num;
	st[++top]=u;
	siz[u]=1;
	ans[u]=2*(n-1);
	int flag=0;
	for(int i=head[u];i;i=ed[i].nxt){
		int v=ed[i].to;		
		if(!dfn[v]){
			vis[v]=u;
			tarjan(v);
			low[u]=min(low[u],low[v]);
			if(dfn[u]<=low[v]){
				flag++;
				if(u!=root || flag>1){
					cut[u]=1;
				}				
				int y=0;
				do{
					y=st[top];
					if(y!=v) siz[v]+=siz[y];					
				}while(st[top--]!=v);
				ans[u]+=(ll)siz[v]*((ll)n-(ll)siz[v]-1);
				siz[u]+=siz[v];
			}
		}
		else low[u]=min(low[u],dfn[v]);
	
	}
	if(cut[u]==1){
		ans[u]+=((ll)n-(ll)siz[u])*((ll)siz[u]-1);
	}
	else ans[u]=(n-1)*2;
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
	for(int i=1;i<=n;i++){
//		if(cut[i]==0) printf("%d\n",(n-1)*2);
		printf("%lld\n",ans[i]);
	}
	return 0;
}
