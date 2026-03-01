#include<bits/stdc++.h>
using namespace std;

const int maxn=90+10,maxmask=1<<20/2+1;
int n,m,d,d1,d2,ans;
bitset<maxn> g0[maxn],g1[maxn],dp[maxmask],f[maxmask];

int main(){
	freopen("y.in","r",stdin);
	freopen("y.out","w",stdout);
	scanf("%d%d%d",&n,&m,&d);
	for(int i=1,u,v,c;i<=m;++i){
		scanf("%d%d%d",&u,&v,&c);
		if(c)
			g1[u][v]=g1[v][u]=true;
		else
			g0[u][v]=g0[v][u]=true;
	}
	d2=d/2;d1=d-d2;
	for(int u=n;u;--u){
		for(int i=0;i<maxmask;++i)
			dp[i].reset();
		dp[1][u]=true;
		for(int x=1;x<1<<d1;++x)
			for(int v=1;v<=n;++v)
				if(dp[x][v]){
					dp[x<<1]|=g0[v];
					dp[x<<1|1]|=g1[v];
				}
		for(int x=0;x<1<<d1;++x)
			f[x][u]=dp[1<<d1|x].any();
	}
	for(int i=0;i<1<<d1;++i)
		for(int j=0;j<1<<d2;++j)//最后的dp数组状态都是由1为开头拓展而来的 
			if((dp[1<<d2|j]&f[i]).any())
				++ans;
	printf("%d\n",ans);
	return 0;
}
