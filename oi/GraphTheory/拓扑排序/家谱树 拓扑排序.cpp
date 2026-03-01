#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;

struct Edge{
	int nxt,to;
}ed[10005];

int n;
int head[105],tot;
int pre[105];
queue<int> q;
int ans[105],cnt;

void add_edge(int u,int v){
	ed[++tot].nxt=head[u];
	ed[tot].to=v;
	head[u]=tot;
}

void topsort(){
	for(int i=1;i<=n;i++){
		if(pre[i]==0) q.push(i);
	}
	while(!q.empty()){
		int u=q.front();
		q.pop();
		ans[++cnt]=u;
		for(int i=head[u];i;i=ed[i].nxt){
			int v=ed[i].to;
			pre[v]--;
			if(pre[v]==0){
				q.push(v);
			}
		}
	}
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		for(int j=1,k;;j++){
			scanf("%d",&k);
			if(k==0) break;
			add_edge(i,k);
			pre[k]++;
		}		
	}
	topsort();
	for(int i=1;i<=cnt;i++){
		printf("%d ",ans[i]);
	}
	return 0;
}
