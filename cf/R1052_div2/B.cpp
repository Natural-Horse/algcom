#include <bits/stdc++.h>
#define inf 0x3f3f3f3f3f
#define ll long long
using namespace std;

inline int read(){
    int x = 0, f = 1; char ch = getchar();
    while(!isdigit(ch)){if(f == '-') f = -1; ch = getchar();}
    while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - 48; ch = getchar();}
    return x * f;
}

const int N = 2e5 + 5;

int n, m, T;
int a[N];
vector<int> b[N], sel;
bool used[N], check[N];
string ans;

void reset(){
    for(int i = 1; i <= m; i++) b[i].clear();
    memset(used, false, sizeof used);
    memset(check, false, sizeof check);
    sel.clear();
    ans = "NO\n";
}

void solve(){
    bool flag = true;
    ans = "NO\n";
    for(int i = 1; i <= m; i++){
        int cnt = b[i].size();
        if(cnt == 0){ans = "NO\n"; return;}
        else if(cnt == 1){
            used[b[i][0]] = true;
        }
    }

    for(int i = 1; i <= m; i++){
        int cnt = 0;
        for(auto s : b[i])
            if(!used[s] && !check[s]) cnt++, check[s] = true, sel.push_back(s);
    }
    if(sel.size() >= 2){ans = "YES\n"; return;}
}


int main(){
    T = read();
    int count = T;
    while(T--){
        
        n = read(), m = read();
        reset();
        for(int i = 1, size; i <= n; i++){
            size = read();
            for(int j = 1, x; j <= size; j++){
                x = read();
                b[x].push_back(j);
            }
        }
        solve();
        cout << ans;
    }
    return 0;
}