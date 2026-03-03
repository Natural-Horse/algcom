#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
#define pii pair<int, int>
#define mkp make_pair
using namespace std;

void solve(){
    int n; cin >> n;
    vector<pii> a(n + 1), b(n + 1);
    vector<bool> b1(n + 1, false), b2(n + 1, false);
    for (int i = 1; i <= n; i++){
        int v; cin >> v;
        if(i & 1) a[i] = mkp(v, 0), b[i] = mkp(v, 1);
        else a[i] = mkp(v, 1), b[i] = mkp(v, 0);
    }
    sort(a.begin() + 1, a.end()), sort(b.begin() + 1, b.end());
    bool ch1 = true, ch2 = true;
    for(int i = 2; i <= n; i++){
        if(a[i].second == a[i-1].second) ch1 = false;
        if(b[i].second == b[i-1].second) ch2 = false;
        if(ch1 == false && ch2 == false) break;
    }
    if(ch1 == true || ch2 == true) cout << "YES" << endl;
    else cout << "NO" << endl;
    
}

int main(){
    ios::sync_with_stdio(false), cin.tie(0);
    int T = 0; cin >> T;
    while(T--) solve();
    return 0;
}