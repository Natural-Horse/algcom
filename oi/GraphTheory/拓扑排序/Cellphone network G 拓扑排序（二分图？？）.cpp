#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;

struct Edge{
	int nxt,to;
}ed[200005];

int n;
int head[100005],tot;
int dp[100005];
bool b[100005];
queue<int> q;
int match[100005],vis[100005];
int cnt,tt;

void add_edge(int u,int v){
	ed[++tot].nxt=head[u];
	ed[tot].to=v;
	head[u]=tot;
}

void paint(){
	int pp=0;
	dp[1]=1;
	b[1]=true;
	q.push(1);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int i=head[u];i;i=ed[i].nxt){
			int v=ed[i].to;
			pp++;
			if(b[v]) continue;
			dp[v]=1-dp[u];
			q.push(v);
			b[v]=true;
		}
	}
	if(pp>2*(n-1)){
		printf("‰∆"); 
		exit(0);
	}
	
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
	scanf("%d",&n);	
	for(int i=1,x,y;i<=n-1;i++){
		scanf("%d%d",&x,&y);
		add_edge(x,y);
		add_edge(y,x);
	}
	paint();
	for(int i=1;i<=n;i++){
		if(dp[i]){
			tt++;
			if(dfs(i,tt)) cnt++;
		}
	}
	for(int i=1;i<=n;i++){
		if(dp[i]==0){
			printf("%d %d\n",match[i],i);
		}
	}
	printf("%d",cnt);
	return 0;	
}
