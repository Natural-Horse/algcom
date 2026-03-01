#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

inline int read(){
	int x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9'){if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - 48; ch = getchar();}
	return x * f;
}

const int N = 1e6 + 5;

struct AC{
	int fail, end, fa, vis[26], cnt, id, ans;
}ac[N];
struct Nd{
	string s;
	int val;
}nd[N];
int n, tot, pre[N], p[N];
bool vis[N];
string S[N], T;
vector<int> vec;
map<string, int> mp;
queue<int> q;

inline void insert(string s, int flag){
	int now = 0, len = s.length();
	for(int i = 0; i < len; i++){
		if(!ac[now].vis[s[i]-'a']){
			ac[now].vis[s[i]-'a'] = ++tot;
			ac[tot].id = s[i]-'a'+1;
		} 
		ac[ac[now].vis[s[i]-'a']].fa = now;
		now = ac[now].vis[s[i]-'a'];
	}
	ac[now].end++, ac[now].id = flag, p[flag] = now;
}
void get_fail(){
	for(int i = 0; i < 26; i++){
		if(ac[0].vis[i]){
			ac[ac[0].vis[i]].fail = 0;
			q.push(ac[0].vis[i]);
		}
	}
	while(!q.empty()){
		int u = q.front(); q.pop();
		for(int i = 0; i < 26; i++){
			if(ac[u].vis[i]){
				ac[ac[u].vis[i]].fail = ac[ac[u].fail].vis[i];
				pre[ac[ac[u].vis[i]].fail]++;
				q.push(ac[u].vis[i]);
			}
			else ac[u].vis[i] = ac[ac[u].fail].vis[i];
		}
	}
}
void qr_cnt(string s){
	int u = 0, len = s.length();
	for(int i = 0; i < len; i++){
	    u = ac[u].vis[s[i]-'a'];
	    ac[u].ans++;
    }
}
void toposort(){
    for(int i = 1; i <= tot; i++) if(!pre[i]) q.push(i);
    while(!q.empty()){
        int u = q.front(); q.pop();
        int v = ac[u].fail;
        pre[v]--, ac[v].ans += ac[u].ans;
        if(!pre[v]) q.push(v);
    }
}

int main(){
	n = read();
	for(int i = 1; i <= n; i++){
		cin >> S[i]; insert(S[i], i);
	}
	cin >> T;
	get_fail(); qr_cnt(T); 
    toposort();
//	for(int i = 1; i <= n; i++) printf("%d ", p[i]);
//	printf("\n");
    for(int i = 1; i <= n; i++) printf("%d\n", ac[p[i]].ans);
	return 0;
}

