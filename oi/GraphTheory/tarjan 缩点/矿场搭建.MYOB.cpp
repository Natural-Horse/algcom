#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;

struct Edge{
	int nxt,to;
}ed[200005],ed_[200005];

int n,m;
int head[50005],tot,head_[50005],tot_;

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

int root; 
int dfn[50005],low[50005],num;
int st[50005],top;
int cut[50005],cnt;
vector<int> dcc[50005];
int jud[50005];
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
				int y;
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

long long maxn,ans,sum=1;

int main(){
	scanf("%d",&m);
	do{
		memset(head,0,sizeof(head));
		memset(head_,0,sizeof(head_));
		memset(dfn,0,sizeof(dfn));
		memset(low,0,sizeof(low));
		memset(cut,0,sizeof(cut));
		memset(jud,0,sizeof(jud));		
		for(int i=1;i<=cnt;i++){
			dcc[i].clear();
		}
		tot=0,tot_=0,ans=0,sum=1,top=0,cnt=0,num=0,n=0;
		
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
			printf("Case %d: 2 %d\n",nidaye,n*(n-1)/2);
			scanf("%d",&m);
			continue;
		}
		for(int i=1;i<=cnt;i++){
			for(int j=0;j<dcc[i].size();j++){
				int node=dcc[i][j];
				if(cut[node]==1) jud[i]++;
			}
		}
		for(int i=1;i<=cnt;i++){
			if(jud[i]==1){
				ans++;
			}
		}
		for(int i=1;i<=cnt;i++){
			if(jud[i]==1){
				sum*=((long long)dcc[i].size()-1);
			}
		}
		printf("Case %d: %lld %lld\n",nidaye,ans,sum);
		scanf("%d",&m);
	}while(m!=0);
	return 0;
}
