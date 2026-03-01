#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;

int n,m;
int e[505][505];
int dis[505];
bool vis[505];
int ans;

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j) e[i][j]=0;
			else e[i][j]=inf;
		}
	}
	for(int i=1,u,v,w;i<=m;i++){
		scanf("%d%d%d",&u,&v,&w);
		e[u][v]=e[v][u]=min(w,e[u][v]);
	}
//	printf("\n");
	for(int i=1;i<=n;i++){
		dis[i]=e[1][i];
	} 
	for(int i=1;i<=n;i++){
		int flag=inf,u;
		for(int j=1;j<=n;j++){
			if(!vis[j]&&flag>dis[j]){
				flag=dis[j];
				u=j;
			}
		}		
		if(dis[u]==inf){
			printf("%d",ans);
			return 0;
		}
		vis[u]=true;
		ans+=dis[u];
//		printf("%d %d\n",u,ans);
		for(int j=1;j<=n;j++){
			dis[j]=min(dis[j],e[u][j]);
		}		
	}
	if(ans==inf) printf("impossible");
	else printf("%d",ans);
	return 0;
}


