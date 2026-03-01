#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
#define db double
#define int long long
using namespace std;

inline int read(){
	int x = 0, f = 1; char ch = getchar();
	while(!isdigit(ch)){if(ch == '-') f = -1; ch = getchar();}
	while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - 48; ch = getchar();}
	return x * f;
}

const int N = 6666, M = 111, mod = 1e4 + 5;

struct AC{
    int vis[26], fail;
    bool end;
}ac[N];
int n, m, tot, ans, f[N][M];
queue<int> q;

void insert(string s){
    int u = 0, len = s.length();
    for(int i = 0; i < len; i++){
        if(!ac[u].vis[s[i]-'A']) ac[u].vis[s[i]-'A'] = ++tot;
        u = ac[u].vis[s[i]-'A'];
    }
    ac[u].end = true;
}
void get_fail(){
    for(int i = 0; i < 26; i++){
        if(ac[0].vis[i]){
            q.push(ac[0].vis[i]);
            ac[ac[0].vis[i]].fail = 0;
        }
    }
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int i = 0; i < 26; i++){
            if(ac[u].vis[i]){
                ac[ac[u].vis[i]].fail = ac[ac[u].fail].vis[i];
                ac[ac[u].vis[i]].end |= ac[ac[ac[u].vis[i]].fail].end;
                q.push(ac[u].vis[i]);
            }
            else ac[u].vis[i] = ac[ac[u].fail].vis[i];
        }
    }
}

signed main(){
    n = read(), m = read();
    for(int i = 1; i <= n; i++){
        string s; cin >> s;
        insert(s);
    }
    get_fail();
    f[0][0] = 1;
    for(int i = 1; i <= m; i++){
        for(int j = 0; j <= tot; j++){
            for(int k = 0; k < 26; k++){
                if(!ac[ac[j].vis[k]].end) f[ac[j].vis[k]][i] = (f[ac[j].vis[k]][i]+f[j][i-1]) % mod;
            }
        }
    }
    for(int i = 0; i <= tot; i++) ans = (ans + f[i][m]) % mod;
    ll all = 1;
    for(int i = 1; i <= m; i++) all = (all * (ll)26) % mod;
    printf("%lld\n", (all-ans+mod)%mod);
    return 0;
}

