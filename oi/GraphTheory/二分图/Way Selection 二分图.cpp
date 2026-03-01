#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;

struct Port{
	int x,y;
}pt[1005];

struct node{
	int x,y,v;
}peo[1005];

struct Edge{
	int nxt,to;
	double len;
}ed[1000005];

double dist(double xa,double ya,double xb,double yb){
	return sqrt(pow(xa-xb,2)+pow(ya-yb,2));
}

int r,a,t;              //r人数,a传送点数,t时间限制 
int head[1005],tot;
int tt,cnt;
int match[1005],vis[1005];

void add_edge(int u,int v,double w){
	ed[++tot].nxt=head[u];
	ed[tot].to=v;
	ed[tot].len=w;
	head[u]=tot;
}

bool dfs(int u,int tim){
	for(int i=head[u];i;i=ed[i].nxt){
		int v=ed[i].to;
		double w=ed[i].len;
		if(vis[v]==tim) continue;
		vis[v]=tim;
		if(!match[v] || dfs(match[v],tim)){
			match[v]=u;
			return true;
		}
	}
	return false;
}

int main(){
	scanf("%d%d%d",&r,&a,&t);
	for(int i=1;i<=a;i++){
		scanf("%d%d",&pt[i].x,&pt[i].y);
	}
	for(int i=1,x,y,v;i<=r;i++){
		scanf("%d%d%d",&x,&y,&v);
		peo[i].v=v;
		peo[i].x=x;
		peo[i].y=y;
	}
	for(int i=1;i<=r;i++){
		int x=peo[i].x;
		int y=peo[i].y;
		int v=peo[i].v; 
		for(int j=1;j<=a;j++){
			int xx=pt[i].x;
			int yy=pt[i].y;
			if(dist((double)x,(double)y,(double)xx,(double)yy)/(double)v<=t){
				add_edge(i,j,dist((double)x,(double)y,(double)xx,(double)yy)/(double)v);
			}
		}
	}
	for(int i=1;i<=r;i++){
		tt++;
		if(dfs(i,tt)) cnt++; 
	}
	printf("%d",cnt);
	return 0;
} 
