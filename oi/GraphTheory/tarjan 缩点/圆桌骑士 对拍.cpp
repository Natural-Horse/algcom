#include<bits/stdc++.h>
using namespace std;
#define N 1005
#define M 1000005
#define ri register int
int stk[N],top=0,bel[N],low[N],dfn[N],n,m,hate[N][N],can[N];
int tot=0,head[N],nex[M],to[M],Ti=0,cnt=0,c[N],cut[N];
vector<int> dcc[N];
void add(int a,int b) { to[++tot]=b; nex[tot]=head[a]; head[a]=tot; }
void init()
{
    tot=0,Ti=0,cnt=0;
    memset(hate,0,sizeof(hate));
    for(ri i=1;i<=n;++i) can[i]=low[i]=dfn[i]=stk[i]=head[i]=c[i]=bel[i]=0,dcc[i].clear();
}
int fl;
void tarjan(int u,int rt)
{
    dfn[u]=low[u]=++Ti; stk[++top]=u;
    if(u==rt && head[u]==0){
        dcc[++cnt].push_back(u);
        return ;
    }
    for(ri i=head[u];i;i=nex[i]){
        int v=to[i];
        if(!dfn[v]){
            tarjan(v,rt);
            low[u]=min(low[u],low[v]);
            if(dfn[u]<=low[v]){
                if(fl>1 || u!=rt) cut[u]=true;//判断割点 
                cnt++; int tmp;
                do{
                    tmp=stk[top];
                    top--;
                    dcc[cnt].push_back(tmp);
                }while(tmp!=v);
                dcc[cnt].push_back(u);//u记得把它本身也加入点双之间 
            }
        }
        else low[u]=min(low[u],dfn[v]);
    }
}

void dfs(int u,int col,int now)
{
    c[u]=col;
    for(ri i=head[u];i;i=nex[i]){
        int v=to[i];
        if(bel[v]!=now) continue;
        if(c[v] && c[v]==c[u]) { fl=1; return ; }
        if(!c[v]) dfs(v,3-col,now);//1 2 col
    }
}
int main()
{
    int a,b;
    while(1){
        scanf("%d%d",&n,&m);
        if(n==0 && m==0) break;
        init();
        for(ri i=1;i<=m;++i) scanf("%d%d",&a,&b),hate[a][b]=1,hate[b][a]=1;
        for(ri i=1;i<=n;++i)
         for(ri j=i+1;j<=n;++j)
          if(!hate[i][j])
           add(i,j),add(j,i);
        for(ri i=1;i<=n;++i) if(!dfn[i]) tarjan(i,i);
        /*for(ri i=1;i<=cnt;++i){输出点双 
            printf("i:%d\n",i);
            for(ri j=0;j<dcc[i].size();++j) printf("%d ",dcc[i][j]);
        }*/
        for(ri i=1;i<=cnt;++i){
            fl=0;
            for(ri j=0;j<dcc[i].size();++j)
            bel[dcc[i][j]]=i,c[dcc[i][j]]=0;
            dfs(dcc[i][0],1,i);
            if(fl){
                for(ri j=0;j<dcc[i].size();++j)
                can[dcc[i][j]]=true;
            }
        }
        int ans=0;
        for(ri i=1;i<=n;++i) if(!can[i]) ans++;
        printf("%d\n",ans);/**/
    }
    return 0;
}
