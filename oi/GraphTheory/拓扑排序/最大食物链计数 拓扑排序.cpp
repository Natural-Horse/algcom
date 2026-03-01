#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;

struct Edge{
	int nxt,to;
}ed[500005];

int n,m;            //n生物数量,m关系数量 
int head[5005],tot;
int pre[5005];
long long dp[5005];
queue<int> q;
long long ans;

void add_edge(int u,int v){
	ed[++tot].nxt=head[u];
	ed[tot].to=v;
	head[u]=tot;
}

void topsort(){
	for(int i=1;i<=n;i++){
		if(pre[i]==0){
			q.push(i);
			dp[i]=1;
		}
	}
	while(!q.empty()){
		int u=q.front();
		q.pop();
		if(head[u]==0){
			ans+=dp[u];
			ans%=80112002;
		}
		for(int i=head[u];i;i=ed[i].nxt){
			int v=ed[i].to;
			dp[v]+=dp[u];
			
			pre[v]--;
			if(pre[v]==0){
				q.push(v);
			}
		}
	}
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		pre[y]++;
		add_edge(x,y);
	}
	topsort();
	ans%=80112002;
	printf("%lld",ans);
	return 0;
}
