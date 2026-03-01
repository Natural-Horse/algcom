#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define le 0.000001
using namespace std;

struct Edge{
	int nxt;
	double to;
}edge[2505];

int n,m;
double ph,cd,v;
double bul[2505];
int ene[2505],def[2505];
double l,r;
int match[55],vis[55];
int tt;

int head[55],tot;

void add_edge(int u,int v){
	edge[++tot].nxt=head[u];
	edge[tot].to=v;
	head[u]=tot;
}

double dist(double xa,double ya,double xb,double yb){
	return sqrt((xa-xb)*(xa-xb)+(ya-yb)*(ya-yb));
}

bool dfs(int u,double tim,double lim){
	int x=u/n+1;
	int y=u%n;
	for(int i=head[u];i;i=edge[i].nxt){
		int jud=def[i%n];
		int xx=jud/n+1;
		int yy=jud%n;
		if(vis[i]==tim || bul[i]+dist((double)x,(double)y,(double)xx,(double)yy)/v>lim) continue;
		vis[i]=tim;
		if(!match[i] || dfs(match[i],tim,lim)){
			match[i]=u;
			return true;
		}
	}
	return false;
}

bool check(double xx){
	memset(match,0,sizeof(match));
	memset(vis,0,sizeof(vis));
	int cnt=0;
	tt=0;
	for(int i=1;i<=m;i++){
		tt++;
		if(dfs(i,tt,xx)) cnt++;
		if(cnt==m) return true;
	}
	return false;	
}

int main(){
	scanf("%d%d%lf%lf%lf",&n,&m,&ph,&cd,&v);
	ph/=60;
	for(int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		ene[i]=x*n+y+1;
	}
	for(int i=1;i<=n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		def[i]=x*n+y+1;
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			bul[(i-1)*m+j]=ph+(i-1)*(cd+ph);
			for(int k=1;k<=m;k++){
				add_edge(k,(i-1)*m+j);
				int x=def[j]/n+1;
				int y=def[j]%n;
				int xx=ene[i]/n+1;
				int yy=ene[i]%n;
				r=max(r,bul[(i-1)*m+j]+dist((double)x,(double)y,(double)xx,double(yy))/v);
			}
			
		}
	}
	while(l<r){
		double mid=(l+r)/2;
		if(check(mid)) r=mid;
		else l=mid+le;
	}
	printf("%.6lf",l);
	return 0;
} 
