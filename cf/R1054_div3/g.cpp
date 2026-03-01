#include <bits/stdc++.h>
#include <algorithm>
#define inf 0x7fffffff
#define ll long long 
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;

inline int read(){
    int x = 0, f = 1; char ch = getchar();
    while(!isdigit(ch)){if(ch == '-') f = -1; ch = getchar();}
    while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - 48; ch = getchar();}
    return x * f;
}

const int N = 2e5 + 5, k = 50;

int n, q, a[N];
vector<int> vec[N];

void reset(){
    
}

void pre_work(){

}

void solve(){
    for(int i = 1; i <= n; i++)
}

signed main(){
    freopen("g.out", "w", stdout);
    T = read();
    int count = T;
    while(T--){
        n = read(), q = read();
        for(int i = 1; i <= n; i++){
            a[i] = read();
            vec[a[i]].push_back(i);
        }
        solve();

    }
    return 0;
}