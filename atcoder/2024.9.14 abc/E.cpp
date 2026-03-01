#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

inline ll read(){
    ll x = 0, f = 1; char ch = getchar();
    while(!isdigit(ch)){if(ch == '-') f = -1; ch = getchar();}
    while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - 48; ch = getchar();}
    return x * f;
}

const int N = 2e5 + 5;

int n, a[N], ls[N], tot;
vector<int> vec[N];
ll ans;

int main(){
    n = read();
    for(int i = 1; i <= n; i++){
        a[i] = read();
        ls[++tot] = a[i];
        // vec[a[i]].push_back(i);
    }
    sort(ls + 1, ls + 1 + tot);
    tot = unique(ls + 1, ls + 1 + tot) - ls - 1;
    for(int i = 1; i <= n; i++){
        int plc = lower_bound(ls + 1, ls + 1 + tot, a[i]) - ls;
        vec[plc].push_back(i);
    }
    for(int i = 1; i <= tot; i++){
        int las = 0;
        ll res = 0;
        if(vec[i].empty()) continue;
        for(int j = 0; j < vec[i].size(); j++){
            res += (ll)(vec[i][j] - las - 1) * (ll)(vec[i][j] - las) / 2;
            las = vec[i][j];
        }
        if(vec[i][vec[i].size()-1] < n) res += (ll)(n - las) * (ll)(n - las + 1) / 2;
        ans += (ll)(1 + n) * (ll)n / 2 - res;
    }
    printf("%lld\n", ans);
    return 0;
}