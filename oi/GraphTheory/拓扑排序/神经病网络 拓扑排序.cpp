#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;

struct node{
	int c,u;
}md[105];

struct Edge{
	int nxt,to,len;
}ed[10005];

int n,p;
int pre[105];
int head[105],tot; 
bool b[205],mode[105];
queue<int> q;

void add_edge(int u,int v,int w){
	ed[++tot].nxt=head[u];
	ed[tot].to=v;
	ed[tot].len=w;
	head[u]=tot;
}

void topsort(){
	for(int i=1;i<=n;i++){
		if(md[i].c>0){
			q.push(i);
			mode[i]=true;
		}
	}
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int i=head[u];i;i=ed[i].nxt){
			int v=ed[i].to;
			int w=ed[i].len;
			md[v].c+=w*md[u].c;
			if(md[v].c>0 && !mode[v]){
				q.push(v);
				mode[v]=true;
			}
		}
	}
}

int main(){
	scanf("%d%d",&n,&p);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&md[i].c,&md[i].u);
		if(md[i].c!=0) b[i]=true;
		else md[i].c=-md[i].u;
	}
	for(int i=1,u,v,w;i<=p;i++){
		scanf("%d%d%d",&u,&v,&w);
		add_edge(u,v,w);
		pre[v]++;
	}
	topsort();
	bool check=false;
	for(int i=1;i<=n;i++){
		if(head[i]==0){
			if(md[i].c>0 && b[i]==false){
				check=true;
				printf("%d %d\n",i,md[i].c);
			}	
			if(b[i]==true){
				check=true;
				printf("%d %d\n",i,md[i].c);
			}
		}
	}
	if(check==false) printf("NULL");
	return 0;
}
