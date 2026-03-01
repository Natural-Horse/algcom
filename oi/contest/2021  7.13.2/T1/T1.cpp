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

const int N = 1e5 + 5;
int a[N], b[N], n;
int val[N], ch[N][2], dat[N], siz[N], fa[N], f[N][2], cnt[N], root, tot, ans;
vector<int> ban[N];
bool check[N];
int st[N], top;

int New(int v){
	val[++tot] = v, dat[tot] = rand(), siz[tot] = 1;
	return tot;
}
void push_back(int u){siz[u] = siz[ch[u][0]] + siz[ch[u][1]] + 1;}
void rotate(int &u, int d){
	int x = ch[u][d^1];
	ch[u][d^1] = ch[x][d];
	ch[x][d] = u;
	u = x;
	push_back(ch[u][d]), push_back(u);
}
void insert(int &u, int v){
	if(!u){
		u = New(v);
		return;
	}
	int d = v > val[u];
	insert(ch[u][d], v);
	if(dat[u] < dat[ch[u][d]]) rotate(u, d ^ 1);
	push_back(u);
}
int query_rank(int u, int v){
	if(!u) return 1;
	if(v == val[u]) return siz[ch[u][1]] + 1;
	else if(v < val[u]) return query_rank(ch[u][0], v);
	else return siz[ch[u][0]] + 1 + query_rank(ch[u][1], v);
}

void dfs(int u, int sum, bool chs){
	if(u > n) return;
	ans = max(ans, sum);
	if(!check[u]){
		for(int i = 0; i < ban[u].size(); i++){
			if(check[ban[u][i]]) st[++top] = ban[u][i];
			check[ban[u][i]] = true;
		} 
		dfs(u+1, sum+1, true);
		for(int i = 0; i < ban[u].size(); i++){
			check[ban[u][i]] = false;
			while(top){
				int y = st[top];
				check[y] = true;
				top--;
			}
		}
	} 
	dfs(u+1, sum, false);
}

int main(){
	n = read();
	if(n <= 1000){
		for(int i = 1; i <= n; i++) a[i] = read(), b[i] = read();
		for(int i = 1; i <= n; i++){
			for(int j = 1; j < i; j++){
				if(b[i] > a[j]) ban[j].push_back(i);
			}
		}
		dfs(1, 0, true);
		printf("%d", ans);
		return 0;
	}
	else{
		for(int i = 1; i <= n; i++) a[i] = read(), b[i] = read();
		for(int i = 1; i <= n; i++){
			cnt[i] = i - query_rank(root, b[i]);
			insert(root, a[i]);
			f[i][0] = max(f[i-1][1], f[i-1][0]);
//			if(cnt[i] <= cnt[i-1]) f[i][1] = max(f[i-1][1] + 1, f[i-1][0]);
//			else 
		}
		for(int i = 1; i <= n; i++){
			f[i][0] = max(f[i-1][1], f[i-1][0]);
//			if(b[i] > a[i-1]) f[i][1] = 
		}
		printf("%d", f[n][1]);
		return 0;
	}
	
}

