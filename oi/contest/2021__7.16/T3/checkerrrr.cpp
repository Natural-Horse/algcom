#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<stack>
#include<cmath>
#include<algorithm>
#include<bitset>
#define rint register int
#define read(A) A=init()
#define MAXN 60050
#define MAXM 100050
using namespace std;
inline int init()
{
    int a=0,b=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')b=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){a=(a<<3)+(a<<1)+ch-'0';ch=getchar();}
    return a*b;
}
bitset <MAXN/2> bit[MAXN];
int n,m,mid,du[MAXN];//read
long long ans;//write
int tot,first[MAXN],v[MAXM],nxt[MAXM];//front-star
bool dev,vis[MAXN];
inline void add(int uu,int vv)
{
    v[++tot]=vv,nxt[tot]=first[uu],first[uu]=tot;
}
inline void dfs(int x)
{
    vis[x]=1;
    if(!dev){if(x<=mid)bit[x].set(x);}
    else    {if(x>mid)bit[x].set(x-mid);}
    for(rint i=first[x];i;i=nxt[i])
    {
        if(!vis[v[i]])dfs(v[i]);
        bit[x]|=bit[v[i]];
    }
    return ;
}
int main()
{
    read(n),read(m);
    for(rint i=1,in_u,in_v;i<=m;++i)
        read(in_u),read(in_v),add(in_u,in_v),du[in_v]++;
    mid=n/2;dev=0;
    for(rint i=1;i<=n;++i)if(!du[i])dfs(i);
    for(rint i=1;i<=n;++i)
    {
        ans+=bit[i].count();
        bit[i].reset();
    }
    memset(vis,0,sizeof(vis));
    dev=1;
    for(rint i=1;i<=n;++i)if(!du[i])dfs(i);
    for(rint i=1;i<=n;++i)ans+=bit[i].count();
    cout<<ans-n-m<<endl;
}
