#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

struct Edge{
	int nxt,to;
}ed[200005];

int n,m;
int head[100005],tot;

void add_edge(int u,int v){
	ed[++tot].nxt=head[u];
	ed[tot].to=v;
	head[u]=tot;
}

int root; 
int dfn[100005],low[100005],num;
int st[100005],top;
int cut[100005],cnt;
vector<int> dcc[100005];
int jud[100005];
int nidaye;

void tarjan(int u){
	dfn[u]=low[u]=++num;
	st[++top]=u;
	int flag=0;
	for(int i=head[u];i;i=ed[i].nxt){
		int v=ed[i].to;
		if(!dfn[v]){
			tarjan(v);
			low[u]=min(low[u],low[v]);
			if(dfn[u]<=low[v]){
				flag++;
				if(u!=root || flag>1){
					cut[u]=1;
				}
				cnt++;
				int y=0;
				do{
					y=st[top];
					dcc[cnt].push_back(y);
				}while(st[top--]!=v);
				dcc[cnt].push_back(u);
			}
		}
		else low[u]=min(low[u],dfn[v]);
	}
}

ll ans,sum=1;
ll siz[100005];

void clear(){
	for(int i=1;i<=n;i++){
		head[i]=0;
		dfn[i]=0;
		low[i]=0;
		cut[i]=0;
		st[i]=0;
	}
	for(int i=1;i<=cnt;i++){
		jud[i]=0;
		dcc[i].clear();
		siz[i]=0;
	}
	tot=0,ans=0,sum=1,top=0,cnt=0,num=0,n=0,root=0;
}

int main(){
	scanf("%d",&m);
	do{
		clear();
		nidaye++;
		for(int i=1,u,v;i<=m;i++){
			scanf("%d %d",&u,&v);
			add_edge(u,v);
			add_edge(v,u);
			n=max(n,u);
			n=max(n,v);
		}
		for(int i=1;i<=n;i++){
			if(!dfn[i]){
				root=i;
				tarjan(i);
			}
		}
		if(cnt==1){
			sum*=(ll)n*((ll)n-1)/2;
			printf("Case %d: 2 %d\n",nidaye,n*(n-1)/2);
			scanf("%d",&m);
			continue;
		}
		for(int i=1;i<=cnt;i++){
			siz[i]=(ll)dcc[i].size();
			for(int j=0;j<dcc[i].size();j++){
				int node=dcc[i][j];
				if(cut[node]==1) jud[i]++;
			}
		}
		for(int i=1;i<=cnt;i++){
			if(jud[i]==1){
				ans++;
				sum*=(siz[i]-1ll);
			}
			if(jud[i]==0){
				ans+=2;
				sum*=siz[i]*(siz[i]-1)/2;
			}
		}
		printf("Case %d: %lld %lld\n",nidaye,ans,sum);
		scanf("%d",&m);
	}while(m!=0);
	return 0;
}
