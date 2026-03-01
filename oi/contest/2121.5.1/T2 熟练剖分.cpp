#include<iostream>
#include<cstdio>
#include<cmath>
#define LL long long
#define int LL
#define MAXN 50100
#define esp 1e-8
#define mod 1000000007
using namespace std;
struct edge
{
    int u,v,nxt;
    #define u(x) ed[x].u
    #define v(x) ed[x].v
    #define n(x) ed[x].nxt
}ed[5000000];
int first[MAXN],num_e;
#define f(x) first[x]
int n,root;
int du[MAXN],ru[MAXN];
bool b
 
LL poww(LL a,int b);
inline void add(int u,int v)
{
    ++num_e;
    u(num_e)=u;
    v(num_e)=v;
    n(num_e)=f(u);
    f(u)=num_e;
}
inline int read()
{
    int s=0;char a=getchar();
    while(a<'0'||a>'9')a=getchar();
    while(a>='0'&&a<='9'){s=s*10+a-'0';a=getchar();}
    return s;
}
LL f[3010][3010],g[3010],h[3010],size[3010];
 
void dfs(int x)
{
    size[x]=1;
    for(int i=f(x);i;i=n(i))dfs(v(i)),size[x]+=size[v(i)];
    LL q=poww(du[x],mod-2);
    for(int i=f(x);i;i=n(i))//Ã¶¾ÙÖØ¶ù×Ó
    {  
        for(int j=0;j<=n;j++)g[j]=1;
        for(int j=f(x);j;j=n(j))
        {
            for(int k=0;k<=size[v(j)]+1;k++)
            {
                LL gs=g[k];      if(k)gs-=g[k-1];
                LL fs=f[v(j)][k];if(k)fs-=f[v(j)][k-1];
                if(v(j)==v(i))h[k]= ((gs*f[v(j)][k]%mod+fs*g[k]%mod-gs*fs)%mod+mod)%mod;
                else if(k)
                {
                    fs=f[v(j)][k-1];if(k>1)fs-=f[v(j)][k-2];
                    h[k]=(  (gs*f[v(j)][k-1]%mod+fs*g[k]%mod-fs*gs%mod)%mod+mod  )%mod;
                }
            }
            g[0]=h[0],h[0]=0;
            for(int k=1;k<=size[v(j)]+1;k++)g[k]=(g[k-1]+h[k])%mod,h[k]=0;
        }
        for(int j=size[x];j;j--)g[j]=(g[j]-g[j-1]+mod)%mod;
        for(int j=0;j<=size[x];j++)f[x][j]=(f[x][j]+g[j]*q%mod)%mod;
    }
    if(!f(x))f[x][0]=1;
    for(int i=1;i<=n;i++)f[x][i]=(f[x][i-1]+f[x][i])%mod;
}
signed main()
{
    n=read();int a;
    for(int i=1;i<=n;i++)       
    {
        du[i]=read();
        for(int j=1;j<=du[i];j++)
        a=read(),add(i,a),ru[a]++;
    }
    bool pdl=1;
    for(int i=1;i<=n;i++)
    {
        if(du[i]!=1&&du[i]!=0)pdl=0;
        if(!ru[i])root=i;
    }
    dfs(root);
    LL ans=0;
    for(int i=1;i<=n;i++)ans=(ans+i*(f[root][i]-f[root][i-1]+mod)%mod)%mod;
    printf("%lld\n",ans);
}
LL poww(LL a,int b)
{
    LL ans=1;
    while(b)
    {
        if(b&1)ans=(ans*a)%mod;
        a=(a*a)%mod;
        b=b>>1;
    }
    return ans;
}
