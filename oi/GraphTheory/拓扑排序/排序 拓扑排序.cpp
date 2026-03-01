#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;

struct Edge{
	int nxt,to;
}ed[605];

int n,m;
int head[30],tot;
int pre[30],jud[30];
bool vis[30];
bool b[30];
int ans[30],cnt;
int dp[30];
queue<int> q;

void add_edge(int u,int v){
	ed[++tot].nxt=head[u];
	ed[tot].to=v;
	head[u]=tot;
}

int topsort(){
//	memset(ans,0,sizeof(ans));
	memset(vis,false,sizeof(vis));
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=n;i++){
		if(jud[i]==0 && b[i]){
			q.push(i);
			vis[i]=true;
			dp[i]=1;
		}
	}
	if(q.empty()) return 2;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		ans[++cnt]=u;
		for(int i=head[u];i;i=ed[i].nxt){
			int v=ed[i].to;			
			jud[v]--;
			if(jud[v]<0) return 2;
			if(dp[v]>=dp[u]) return 2;			
			if(jud[v]==0){
				if(vis[v]==true) return 2; 
				q.push(v);
				vis[v]=true; 
				dp[v]=dp[u]+1;
			}
		}
	}
	if(cnt==n) return 1;
	else return 0;
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		char u,v,opt;
		cnt=0;
		scanf("\n%c%c%c",&u,&opt,&v);
		if(u==v){
			printf("Inconsistency found after %d relations.",i);
			return 0;
		}
		int x=u-'A'+1;
		int y=v-'A'+1;
		b[x]=true;
		b[y]=true;
		add_edge(x,y);
		pre[y]++;
		for(int j=1;j<=n;j++){
			jud[j]=pre[j];
		}
		int check=topsort();
		if(check==2){
			printf("Inconsistency found after %d relations.",i);
			return 0;
		} 	
		if(dp[ans[n]]==n && check==1){
			printf("Sorted sequence determined after %d relations: ",i);
			for(int j=1;j<=n;j++){
				char plc=ans[j]+'A'-1;
				printf("%c",plc);			
			}
			printf(".");
			return 0;
		}	
	}
	printf("Sorted sequence cannot be determined.");
	return 0;
}
