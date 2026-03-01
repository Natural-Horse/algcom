#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;

struct Edge{
	int nxt,to;
}ed[1000005];

int n,m;     //n锦囊妙计数,m题数 
int head[1005],tot;
int match[1005],vis[1005];
int tt,cnt;

void add_edge(int u,int v){
	ed[++tot].nxt=head[u];
	ed[tot].to=v;
	head[u]=tot;
}

bool dfs(int u,int tim){
	for(int i=head[u];i;i=ed[i].nxt){
		int v=ed[i].to;
		if(vis[v]==tim) continue;
		vis[v]=tim;
		if(!match[v] || dfs(match[v],tim)){
			match[v]=u;
			return true;
		}
	}
	return false;
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		if(x==y) add_edge(i,x);
		else{
			add_edge(i,x);
			add_edge(i,y);
		}
	}
	for(int i=1;i<=m;i++){
		tt++;
		if(dfs(i,tt)) cnt++;
	}
	printf("%d",cnt);
	return 0;
}
