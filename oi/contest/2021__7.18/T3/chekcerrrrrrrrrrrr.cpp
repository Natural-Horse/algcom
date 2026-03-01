#include<iostream>
#include<cstdio>
#define inf 0x7ffff
using namespace std;
struct node
{
    int to,nxt,tpy;
}h[200100];
int n,tot,nxt[200100];
pair<int,int>f[100100][2];
int read()
{
    int aa=0,bb=1;char cc=getchar();
    while(cc>'9'||cc<'0'){if(cc=='-') bb=-1;cc=getchar();}
    while(cc>='0'&&cc<='9'){aa=(aa<<3)+(aa<<1)+(cc^'0');cc=getchar();}
    return aa*bb;
}
int add(int x,int y,int tpy)
{
    h[++tot].to=y;
    h[tot].tpy=tpy;
    h[tot].nxt=nxt[x];
    nxt[x]=tot;
}
pair<int,int> cal(pair<int,int> a,pair<int,int> b)
{
    return make_pair(a.first+b.first,a.second+b.second);
}
void dfs(int x,int fa,int tpy)
{
    pair<int,int>w1,w2;//w1:不以x作为端点   w2：以x作为端点
    w1=make_pair(0,0);w2=make_pair(inf,inf);
    for(int i=nxt[x];i;i=h[i].nxt){
        int y=h[i].to;
        if(y==fa) continue;
        dfs(y,x,h[i].tpy);
        pair<int,int>tmp1=min(cal(w1,f[y][0]),cal(w2,f[y][1]));
        pair<int,int>tmp2=min(cal(w1,f[y][1]),cal(w2,f[y][0]));
        w1=tmp1;w2=tmp2;
    }
    if(tpy==2){
        f[x][0]=min(w1,make_pair(w2.first+1,w2.second));
        f[x][1]=min(make_pair(w1.first+1,w1.second+1),make_pair(w2.first,w2.second+1));
    }
    else if(tpy==1){
        f[x][0]=make_pair(inf,inf);
        f[x][1]=min(make_pair(w1.first+1,w1.second+1),make_pair(w2.first,w2.second+1));
    }
    else if(tpy==0){
        f[x][0]=min(w1,make_pair(w2.first+1,w2.second));
        f[x][1]=make_pair(inf,inf);
    }
}
int main()
{
    n=read();
    int u,v,c,cc;
    for(int i=1;i<n;i++){
        u=read();v=read();c=read();cc=read();
        if(cc==2) add(u,v,2),add(v,u,2);
        else add(u,v,c^cc),add(v,u,c^cc);
    }
    dfs(1,0,2);
    printf("%d %d\n",f[1][0].first/2,f[1][0].second);
    return 0;
}
