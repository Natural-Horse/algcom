#include<bits/stdc++.h>
#include<algorithm>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

inline int read(){
	int x = 0, f = 1; char ch = getchar();
	while(!isdigit(ch)){if(ch == '-') f = -1; ch = getchar();}
	while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - 48; ch = getchar();}
	return x * f;
}

const int N = 1e5 + 5;

struct Ed{
	int u, v, w, nxt;
}ed[N<<1];
int n, hd[N], tot, val[N], ans;

string get(int x){
	string s;
	while(x) s = s + (char)((x & 1) + '0'), x >>= 1;
	while(s.length() < 31) s = s + (char)('0');
//	reverse(s.begin(), s.end());
	return s;
}

class Trie{
public:
	int nxt[N*30][3], tot;
	void insert(string s, int len){
		int plc = 0;
		for(int i = len-1; i >= 0; --i){
			int c = s[i] - '0';
			if(!nxt[plc][c]) nxt[plc][c] = ++tot;
			plc = nxt[plc][c];
		}
	}
	int qr_mx(string s, int len){
		int plc = 0, ans = 0;
		for(int i = len-1; i >= 0; --i){
			int c = s[i] - '0';
			if(nxt[plc][c^1]){
				ans += (1 << i);
				plc = nxt[plc][c^1];
			}
			else plc = nxt[plc][c];
		}
		return ans;
	}
}T;

void add_edge(int u, int v, int w){
	ed[++tot].nxt = hd[u], hd[u] = tot;
	ed[tot].u = u, ed[tot].v = v, ed[tot].w = w;
}

void dfs(int u, int fa){
	for(int i = hd[u]; i; i = ed[i].nxt){
		int v = ed[i].v; if(v == fa) continue;
		val[v] = val[u] ^ ed[i].w;
		dfs(v, u);
	}
	string s = get(val[u]);
	int len = s.length();
	T.insert(s, len);
}

int main(){
	n = read();
	for(int i = 1, u, v, w; i < n; i++){
		u = read(), v = read(), w = read();
		add_edge(u, v, w), add_edge(v, u, w);
	}
	dfs(1, 0);
	for(int i = 1; i <= n; i++){
		string s = get(val[i]);
		int len = s.length();
		ans = max(ans, T.qr_mx(s, len));
//		printf("ans : %d\n", ans);
	}
	printf("%d\n", ans);
	return 0;
}

