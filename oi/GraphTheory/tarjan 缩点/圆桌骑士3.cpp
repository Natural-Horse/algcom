#include<cstdio>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstring>
#define inf 0x3f3f3f3f
using namespace std;

struct Edge{
	int nxt,to;
}ed[2000005],ed_[2000005];

int n,m;
int head[1005],tot;
bool e[1005][1005];

void add_edge(int u,int v){
	ed[++tot].nxt=head[u];
	ed[tot].to=v;
	head[u]=tot;
}

int dfn[1005],low[1005],num;
int st[1005],top;
int root;
int cnt,p[1005];
bool b[1005];
vector<int> dcc[1005];
int oe[1005],vis[1005],tt;
int ans;
bool re=false;

void dfs(int u,int fa,int tim){
	for(int i=head[u];i;i=ed[i].nxt){
		int v=ed[i].to;
		if(p[v]!=tim || v==fa) continue;		
		if(oe[v]==oe[u] && oe[v]!=0){
			re=true;
			return; 
		}
		if(!oe[v]) oe[v]=oe[u]^1,dfs(v,u,tim);
	}
}

void tarjan(int u){
	dfn[u]=low[u]=++num;
	st[++top]=u;
	for(int i=head[u];i;i=ed[i].nxt){
		int v=ed[i].to;
		if(!dfn[v]){
			tarjan(v);
			low[u]=min(low[u],low[v]);
			if(dfn[u]<=low[v]){
				cnt++;
				int y=0;
				do{
					y=st[top];
					p[y]=cnt;
					dcc[cnt].push_back(y);
				}while(st[top--]!=v); 
				dcc[cnt].push_back(u);
			}
		}
		else low[u]=min(low[u],dfn[v]);
	}
}

void cclear(){
	for(int i=1;i<=n;i++){
		head[i]=0;
		low[i]=0;
		dfn[i]=0;
		p[i]=0;
		b[i]=false;
	}
	for(int i=1;i<=cnt;i++){
		dcc[i].clear();
	}
	memset(e,false,sizeof(e));
	top=0;
	tot=0;
	cnt=0;
	num=0;
	ans=0;
}

int main(){
	scanf("%d %d",&n,&m);
	do{
		cclear();
		for(int i=1,u,v;i<=m;i++){
			scanf("%d %d",&u,&v);
			e[u][v]=true;
			e[v][u]=true;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(!e[i][j] && i!=j){
					add_edge(i,j);
				}
			}
		}
		for(int i=1;i<=n;i++){
			if(!dfn[i]){
				root=i;
				tarjan(i);
			}
		}
		for(int i=1;i<=cnt;i++){
			for(int j=0;j<dcc[i].size();j++){
				p[dcc[i][j]]=i;
				oe[dcc[i][j]]=0;
			}
			oe[dcc[i][0]]=2;
			dfs(dcc[i][0],0,i);
			if(re){
				for(int j=0;j<dcc[i].size();j++){
					b[dcc[i][j]]=true;
				}
			}
			re=false;
		}
		for(int i=1;i<=n;i++){
			if(!b[i]) ans++;
		}
		printf("%d\n",ans);
		scanf("%d %d",&n,&m);
	}while(n!=0 && m!=0);
	return 0;
}
