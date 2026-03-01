#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;

struct Edge{
	int nxt,to;
}ed[605];

int n,m;
int head[305],tot;
int w[305];
int dp[305][305];

void add_edge(int u,int v){
	ed[++tot].nxt=head[u];
	ed[tot].to=v;
	head[u]=tot;
}

void dfs(int u,int fa){
	
	
	
	if(head[u]==0){
		
	}
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,s,k;i<=n;i++){
		scanf("%d %d", &k,&s);
		w[i]=s;
		if(k!=0) add_edge(k,i);		
	}
	dfs()
}
