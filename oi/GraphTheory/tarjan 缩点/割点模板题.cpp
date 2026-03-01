#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;

struct Edge{
	int nxt,to;
}ed[200005];

int n,m,root;
int head[20005],tot;
int dfn[20005],low[20005],num;
int cut[20005],cnt;

void add_edge(int u,int v){
	ed[++tot].nxt=head[u];
	ed[tot].to=v;
	head[u]=tot;
}

void tarjan(int u){
//	freopen("1.txt","w",stdout);
	dfn[u]=low[u]=++num;
	int flag=0;
	for(int i=head[u];i;i=ed[i].nxt){
		int v=ed[i].to;
		if(!dfn[v]){
			tarjan(v);
			low[u]=min(low[u],low[v]);
			if(low[v]>=dfn[u]){
				flag++;
				if(u!=root || flag>1){
					if(!cut[u])cnt++;
					cut[u]=1;					
				}
			}
		}
		else low[u]=min(low[u],dfn[v]);
	}
}

int main(){
	scanf("%d%d",&n,&m);
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
	printf("%d\n",cnt);
	for(int i=1;i<=n;i++){
		if(cut[i]==1) printf("%d ",i);
	}
	return 0;
}
