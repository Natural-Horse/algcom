#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;

struct Edge{
	int nxt,to;
}ed[100005];

int n;
int head[100005],tot;
queue<int> q;
int s;
int vis[100005];
int dep[100005];
int dis[100005];
int ans;

void add_edge(int u,int v){
	ed[++tot].nxt=head[u];
	ed[tot].to=v;
	head[u]=tot;
}

void bfs1(){
	q.push(1);
	vis[1]=1;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		bool check=false;
		for(int i=head[u];i;i=ed[i].nxt){			
			int v=ed[i].to;
			if(vis[v]==1) continue;
			vis[v]=1;
			dep[v]=dep[u]+1;
			check=true;
			q.push(v);
		}
		if(check==false){
			if(dep[u]>dep[s]){
				s=u;
			}
		}
	}
}

void bfs2(){
	q.push(s);
	vis[s]=2;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		bool check=false;
		for(int i=head[u];i;i=ed[i].nxt){
			int v=ed[i].to;
			if(vis[v]==2) continue;
			vis[v]=2;
			check=true;
			q.push(v);
			dis[v]=dis[u]+1;
		}
		if(check==false){
			ans=max(ans,dis[u]);
		}
	}
}

int main(){
	scanf("%d",&n);
	for(int i=1,l,r;i<=n;i++){
		scanf("%d%d",&l,&r);
		if(l!=0){
			add_edge(i,l);
			add_edge(l,i);
		} 
		if(r!=0){
			add_edge(i,r);
			add_edge(r,i);
		} 
	}
	bfs1();
	bfs2();
	printf("%d",ans);
	return 0;
}
