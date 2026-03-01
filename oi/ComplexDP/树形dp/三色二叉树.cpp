#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;

struct Node{
	int num,cnt;
}node[500005];

struct Edge{
	int nxt,to;
}ed[1000005];

char a[500005];
int lena;
int plc=1;
int head[500005],tot;
int dpa[500005][2];
int dpb[500005][3]; 
int ans=-inf;

void add_edge(int u,int v){
	ed[++tot].nxt=head[u];
	ed[tot].to=v;
	head[u]=tot;
}

void dfs1(int fa){	
	int num=node[plc].num;
	int cnt=node[plc].cnt;
	for(int i=1;i<=cnt;i++){
		plc++;
		add_edge(fa,plc);
		add_edge(plc,fa);
		dfs1(plc);
	}
}

void dfs2(int u,int fa){
	dpa[u][1]=1;
	int juda=0,judb=0,cnt=0;	
	for(int i=head[u];i;i=ed[i].nxt){
		int v=ed[i].to;
		if(v==fa) continue;
		cnt++;
		dfs2(v,u);
		dpa[u][1]+=dpa[v][0];
		if(cnt==1){
			juda+=dpa[v][1];
			judb+=dpa[v][0];
		} 
		if(cnt==2){
			juda+=dpa[v][0];
			judb+=dpa[v][1];
		}
	}
	dpa[u][0]=max(juda,judb);
}

void dfs3(int u,int fa){
	dpb[u][0]=1;
	int cnt=0;
	int ga=0,gb=0;
	int ba=0,bb=0;
	int ra=0,rb=0;
	for(int i=head[u];i;i=ed[i].nxt){
		int v=ed[i].to;
		if(v==fa) continue;
		dfs3(v,u);
		cnt++;
		if(cnt==1){
			ga+=dpb[v][1];
			gb+=dpb[v][2];
			ba+=dpb[v][0];
			bb+=dpb[v][2];
			ra+=dpb[v][0];
			rb+=dpb[v][1];
		}
		if(cnt==2){
			ga+=dpb[v][2];
			gb+=dpb[v][1];
			ba+=dpb[v][2];
			bb+=dpb[v][0];
			ra+=dpb[v][1];
			rb+=dpb[v][0];
		}
	}
	dpb[u][0]+=min(ga,gb);
	dpb[u][1]+=min(ba,bb);
	dpb[u][2]+=min(ra,rb);
}

int main(){
	scanf("%s",a+1);
	lena=strlen(a+1);
	for(int i=1;i<=lena;i++){
		node[i].cnt=a[i]-'0';
		node[i].num=i;
	}
	dfs1(1);
	dfs2(1,0);
	dfs3(1,0);
	ans=min(dpb[1][0],dpb[1][1]);
	ans=min(ans,dpb[1][2]);
	printf("%d %d",max(dpa[1][1],dpa[1][0]),ans);
	return 0;
} 
/* 
21200110
*/



