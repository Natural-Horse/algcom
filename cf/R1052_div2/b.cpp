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
vector<int> a[N], b[N];
string ans;

void reset(){
    for(int i = 1; i <= m; i++) b[i].clear();
    for(int i = 1; i <= n; i++) a[i].clear();
    ans = "NO\n";
}

bool check(int x, int blo){
    int cnt = 0;
    for(auto p : a[x]){
        cnt = 0;
        for(auto s : b[p]){
            if(s != blo && s != x) cnt++;
        }
        if(!cnt) return false;
    }
    return true;
}

void solve(){
    for(int i = 1; i <= m; i++){
        if(!b[i].size()) return;
    }
    int flag1 = 0, flag2 = 0;
    for(int i = 1; i <= n; i++){
        if(check(i, 0)){
            flag1 = i;
            break;
        }
    }
    for(int i = 1; i <= n; i++){
        if(i != flag1 && check(i, 0)){
            flag2 = i;
            break;
        }
    }
    if((flag1) && (flag2)) ans = "YES\n";
    return;
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
                a[i].push_back(x);
                b[x].push_back(i);
            }
        }
        solve();
        cout << ans;
    }
    return 0;
}