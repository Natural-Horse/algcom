#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;

struct Edge{
	int nxt,to,len;
}ed[50005];

int n,m;
int head[1505],tot;
int dis[1505],vis[1505];
queue<int> q;

void add_edge(int u,int v,int w){
	ed[++tot].nxt=head[u];
	ed[tot].to=v;
	ed[tot].len=w;
	head[u]=tot;
}

void spfa(){
	for(int i=1;i<=n;i++){
		dis[i]=-inf;
	} 
	vis[1]=1;
	dis[1]=0;
	q.push(1);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		vis[u]=0;
		for(int i=head[u];i;i=ed[i].nxt){
			int v=ed[i].to;
			int w=ed[i].len;
			if(dis[u]+w>dis[v]){
				dis[v]=dis[u]+w;
				if(!vis[v]){
					q.push(v);
					vis[v]=1;
				}
			}
		}
	}
	
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,u,v,w;i<=m;i++){
		scanf("%d%d%d",&u,&v,&w);
		add_edge(u,v,w);
	}
	spfa();
	if(dis[n]==-inf) printf("-1");
	else printf("%d",dis[n]);
	return 0;
}
