#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

const int N = 1e5 + 5;

void solve(){
    int n; cin >> n;
    vector<int> a(n + 1);
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    if(a[1] + a[n] > 0) cout << "Alice" << endl;
    else cout << "Bob" << endl;
}

int main(){
    ios::sync_with_stdio(false), cin.tie(0);
    int T = 0;
    cin >> T;
    while(T--) solve();
    return 0;
}