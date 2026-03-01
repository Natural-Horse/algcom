#include<bits/stdc++.h>
using namespace std;
struct rec{long long x,a;int id;}e[100001];
int n,k;
int eftr[100001],now;
long long p[100001],t[100001];
int fa[100001][21],minn[100001][21];
int ans[100001];
pair<int,int> tr[100001];
bool cmp(rec a,rec b){return a.x<b.x;}
int lowbit(int x){return x&-x;}
bool getmin(pair<int,int> a,pair<int,int> b)
{
    if(a.first!=b.first)return a.first<b.first;
    int minx=a.second,miny=b.second,x=a.second,y=b.second;
    for(int i=19;i>=0;i--)
        if(fa[x][i]!=fa[y][i])
        {
            minx=min(minx,minn[x][i]);
            miny=min(miny,minn[y][i]);
            x=fa[x][i];y=fa[y][i];
        }
    return minx>miny;
}
void efadd(int x,int w){for(int i=x;i<=n;i+=lowbit(i))eftr[i]=max(eftr[i],w);}
int efask(int x){int res=0;for(int i=x;i;i-=lowbit(i))res=max(res,eftr[i]);return res;}
void add(int x,pair<int,int> w){for(int i=x;i<=n;i+=lowbit(i))if(getmin(tr[i],w))tr[i]=w;}
pair<int,int> ask(int x){pair<int,int> res=make_pair(0,0);for(int i=x;i;i-=lowbit(i))if(getmin(res,tr[i]))res=tr[i];return res;}
bool judge(int x)
{
    memset(eftr,0,sizeof(eftr));
    for(int i=1;i<=n;i++)t[i]=p[i]=2*e[i].x+e[i].a*x*x;
    sort(t+1,t+n+1);
    for(int i=1;i<=n;i++)
    {
        p[i]=lower_bound(t+1,t+n+1,p[i])-t;
        efadd(p[i],efask(p[i]-1)+1);
    }
    now=efask(n);
    return now>=k;
}
void build(int x,int father)
{
    fa[x][0]=minn[x][0]=father;
    for(int i=1;i<=19;i++)
    {
        fa[x][i]=fa[fa[x][i-1]][i-1];
        minn[x][i]=min(minn[x][i-1],minn[fa[x][i-1]][i-1]);
    }
}
int main()
{
    memset(minn,0x3f,sizeof(minn));
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld%lld",&e[i].x,&e[i].a);
        e[i].id=i;
    }
    sort(e+1,e+n+1,cmp);
    int lft=1,rht=86400,res=1;
    while(lft<=rht)
    {
        int mid=(lft+rht)>>1;
        if(judge(mid)){lft=mid+1;res=mid;}
        else rht=mid-1;
    }
    judge(res);
    printf("%d\n",res);
    if(now>k){puts("-1");return 0;}
    for(int i=1;i<=n;i++)t[i]=p[i]=2*e[i].x+e[i].a*res*res;
    sort(t+1,t+n+1);
    for(int i=1;i<=n;i++)
    {
        p[i]=lower_bound(t+1,t+n+1,p[i])-t;
        pair<int,int> flag=ask(p[i]-1);
        build(e[i].id,flag.second);
        add(p[i],make_pair(flag.first+1,e[i].id));
    }
    int now=ask(n).second;
    for(int i=1;i<=k;i++)
    {
        ans[i]=now;
        now=fa[now][0];
    }
    sort(ans+1,ans+k+1);
    for(int i=1;i<=k;i++)printf("%d\n",ans[i]);
    return 0;
}
