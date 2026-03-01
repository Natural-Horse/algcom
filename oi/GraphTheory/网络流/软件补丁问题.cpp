#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

const int Maxn = 505;
const int NM = (1 << 22) | 1;

int n, m;
int p1[Maxn], p2[Maxn], s1[Maxn], s2[Maxn];
int dis[NM];
int w[Maxn];
bool vis[NM];
queue<int> q;

void spfa(){
	memset(dis, 0x3f, sizeof(dis));
	int st = (1 << n) - 1;
	dis[st] = 0;
	vis[st] = true;
	q.push(st);
	while(!q.empty()){
		int u = q.front();
		q.pop();
		vis[u] = false;
		for(int i = 1; i <= m; i++){
			if((u & p1[i]) == p1[i] && (u & p2[i]) == 0){
				int v = ((u | s1[i]) ^ s1[i]) | s2[i];
				if(dis[v] > dis[u] + w[i]){
					dis[v] = dis[u] + w[i];
					if(!vis[v]){
						vis[v] = true;
						q.push(v);
					}
				}
			}
		}
	}
}

int main(){
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= m; i++){
		scanf("%d", &w[i]);
		scanf(" ");
		for(int j = 1; j <= n; j++){
			char c;
			c = getchar();
			if(c == '+') p1[i] |= 1 << (j-1);
			if(c == '-') p2[i] |= 1 << (j-1);
		} 
		scanf(" ");
		for(int j = 1; j <= n; j++){
			char c;
			c = getchar();
			if(c == '+') s2[i] |= 1 << (j-1);
			if(c == '-') s1[i] |= 1 << (j-1);
		}
	}
	spfa();
	if(dis[0] == inf) printf("0");
	else printf("%d", dis[0]);
	return 0;
}
