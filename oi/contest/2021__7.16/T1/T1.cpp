#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

int read(){
	int x = 0,f = 1;char ch = getchar();
	while (ch < '0' || ch > '9'){if (ch == '-') f = -1; ch = getchar();}
	while (ch >= '0' && ch <= '9'){x = x*10 + ch - 48; ch = getchar();}
	return x * f;
}

const int N = 6e4 + 5;

struct Edge{
	int nxt, to;
}ed[N << 1];
int n, m, head[N], tot, pre[N], ans;
bool b[2003][2003], vis[N], c[2003][2003];
vector<int> s[N], st;

void add_edge(int u, int v){ed[++tot].nxt=head[u];ed[tot].to=v;head[u]=tot;}
void dfs(int u){
	s[u].push_back(u);
	vis[u] = true;
	for(int i = head[u]; i; i = ed[i].nxt){
		int v = ed[i].to;
		if(!vis[v]) dfs(v);	
		for(int j = 0; j < s[v].size(); j++){
			if(!c[u][s[v][j]]){
				s[u].push_back(s[v][j]);
				if(!b[u][s[v][j]]) ans++;
			} 
			c[u][s[v][j]] = true;			
		}
	}
}

int main(){
	n = read(), m = read();
	if(n <= 2002){
		for(int i = 1, u, v; i <= m; i++){
			u = read(), v = read();
			b[u][v] = true, add_edge(u, v), pre[v]++;
		} 
		for(int i = 1; i <= n; i++){
			if(!pre[i]) st.push_back(i);
		}
		for(int i = 0; i < st.size(); i++){
			dfs(st[i]);
		}
		printf("%d", ans);
	}
	return 0;
}

