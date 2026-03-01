#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;

struct Edge{
	int nxt,to;
}ed[4000005],ed_[4000005];

int n;
int head[2005],tot,head_[2005],tot_;
bitset<2005>f[2005];

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

int dfn[2005],low[2005],num;
int vis[2005];
int st[2005],top;
int p[2005],cnt;
long long siz[2005];

void tarjan(int u){
	dfn[u]=low[u]=++num;
	vis[u]=1;
	st[++top]=u;
	for(int i=head[u];i;i=ed[i].nxt){
		int v=ed[i].to;
		if(!dfn[v]){
			tarjan(v);
			low[u]=min(low[u],low[v]);
		}
		else if(vis[v]) low[u]=min(low[u],dfn[v]); 
	}	
	if(low[u]==dfn[u]){
		cnt++;
		int y=0;
		do{
			y=st[top];
			vis[y]=0;
			p[y]=cnt;
			siz[cnt]++;
		}while(st[top--]!=u);
	}
}

int pre[2005];
queue<int> q;

void toposort(){
	for(int i=1;i<=cnt;i++){
		if(pre[i]==0){
			q.push(i);
		}
	}
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int i=head_[u];i;ed_[i].nxt){
			int v=ed_[i].to;
			f[v]|=f[u];
			pre[v]--;
			if(pre[v]==0) q.push(v);
		}
	}
}

long long ans;

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("\n");
		for(int j=1;j<=n;j++){
			char cc;
			scanf("%c",&cc);
			if(cc=='1'){
				add_edge(i,j);
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(!dfn[i]){
			tarjan(i);
		}
	}	
	for(int i=1;i<=n;i++){
		for(int j=head[i];j;j=ed[j].nxt){
			int v=ed[j].to;
			if(p[i]!=p[v]){
				add_edge_(p[v],p[i]);
				pre[p[i]]++;
			}
		}
	}
	for(int i=1;i<=cnt;i++){
		f[i][i]=1;
	}
	toposort();
	for(int i=1;i<=cnt;i++){
		for(int j=1;j<=cnt;j++){
			if(f[i][j]) ans+=siz[i]*siz[j];
		}
	}
	printf("%lld",ans);
	return 0;
}
