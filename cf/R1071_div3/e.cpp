#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

int T;

void solve(){
    ll n, x, y;
    string s, ans = "NO";
    cin >> n >> x >> y >> s;
    ll sum = 0, suma = 0, sumb = 0;
    vector<ll> p(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> p[i], sum += p[i];
        if(s[i-1] == '0') suma += p[i] / 2 + 1;
        else sumb += p[i] / 2 + 1;
    }
    if(sum > x + y) ans = "NO";
    else if(s == string(n, '1')){
        if(y - x >= n && y >= sumb) ans = "YES";
        else ans = "NO";
    }
    else if(s == string(n, '0')){
        if(x - y >= n && x >= suma) ans = "YES";
        else ans = "NO";
    }
    else if(x >= suma && y >= sumb) ans = "YES";
    // cout << "ans : ";
    cout << ans << endl;
}

int main(){
    cin >> T;
    while(T--) solve();
    return 0;
}