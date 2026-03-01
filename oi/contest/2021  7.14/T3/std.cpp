
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
#define int long long
using namespace std;
const int MAXN=1e5+5;
int t,n,d[MAXN],ans=0;
int to[MAXN<<1],nxt[MAXN<<1],pre[MAXN],val[MAXN<<1],cnt=0;
inline void add(int u,int v,int w){
	cnt++,to[cnt]=v,nxt[cnt]=pre[u],pre[u]=cnt,val[cnt]=w;
}
int f[MAXN][19],deep[MAXN],dis[MAXN];
void dfs(int x){
	for(int i=1;i<=18;i++){
		if(f[x][i-1])
		f[x][i]=f[f[x][i-1]][i-1];
	}
	for(int i=pre[x];i;i=nxt[i]){
		if(to[i]!=f[x][0]){
			deep[to[i]]=deep[x]+1;
			dis[to[i]]=dis[x]+val[i];
			f[to[i]][0]=x;
			dfs(to[i]);
		}
	}
}
int LCA(int x,int y){
	if(deep[x]<deep[y]) swap(x,y);
	for(int i=18;i>=0;i--)
		if(deep[f[x][i]]>=deep[y])
			x=f[x][i];
	if(x==y) return x;
	for(int i=18;i>=0;i--)
		if(f[x][i]!=f[y][i])
			x=f[x][i],y=f[y][i];
	return f[x][0];
}
struct node{
	int val,id;
	friend bool operator < (node a,node b){
		return a.val>b.val;
	}
}p[MAXN];
bool vis[MAXN];
int fa[MAXN];
struct data{
	int d,st,ed;
}q[MAXN];
int find(int x){
	return fa[x]=(fa[x]==x?x:find(fa[x]));
}
void unionn(int x,int y){
	x=find(x),y=find(y);
	if(x!=y){
		fa[y]=x;
		data mx;
		if(q[x].d>q[y].d) mx=q[x];
		else mx=q[y];
		int lca=LCA(q[x].st,q[y].st);
		int dist=dis[q[x].st]+dis[q[y].st]-2*dis[lca];
		if(mx.d<dist) mx=(data){dist,q[x].st,q[y].st};
		lca=LCA(q[x].st,q[y].ed);
		dist=dis[q[x].st]+dis[q[y].ed]-2*dis[lca];
		if(mx.d<dist) mx=(data){dist,q[x].st,q[y].ed};
		lca=LCA(q[x].ed,q[y].ed);
		dist=dis[q[x].ed]+dis[q[y].ed]-2*dis[lca];
		if(mx.d<dist) mx=(data){dist,q[x].ed,q[y].ed};
		lca=LCA(q[x].ed,q[y].st);
		dist=dis[q[x].ed]+dis[q[y].st]-2*dis[lca];
		if(mx.d<dist) mx=(data){dist,q[x].ed,q[y].st};
		q[x]=mx;
	}
}
signed main(){
	scanf("%lld",&t);
    while(t--){
		memset(dis,0,sizeof(dis));
		memset(pre,0,sizeof(pre));
		memset(f,0,sizeof(f));
		memset(deep,0,sizeof(deep));
		memset(vis,0,sizeof(vis));
		ans=0;cnt=0;
        scanf("%lld",&n);
        for(int i=1;i<=n;++i){
			fa[i]=i;
			q[i]=(data){0,i,i};
			scanf("%lld",&d[i]);
			p[i]=(node){d[i],i};
		}
		for(int i=1,u,v,w;i<n;++i){
			scanf("%lld%lld%lld",&u,&v,&w);
			add(u,v,w),add(v,u,w);
		}
		sort(p+1,p+n+1);
		deep[1]=1;
		dfs(1);
		for(int i=1;i<=n;++i){
			int x=p[i].id;
			vis[x]=1;
			fo)r(int j=pre[x];j;j=nxt[j]){
				int y=to[j];
				if(!vis[y]) continue;
				unionn(x,y;
			}
			ans=max(ans,q[x].d*d[x]);
		}
		printf("%lld\n",ans);
    }
	return 0;
}
/*
1
3
1 2 3
1 2 1
1 3 2
*/ 
