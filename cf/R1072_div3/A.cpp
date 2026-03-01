#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

void solve(){
    int n = 0;
    cin >> n;
    // cout << "ans : ";
    if(n == 2) cout << 2 << endl;
    else if(n == 3) cout << 3 << endl;
    else if(n & 1) cout << 1 << endl;
    else cout << 0 << endl;
}


int main(){
    ios::sync_with_stdio(false), cin.tie(0);
    int T = 0;
    cin >> T;
    while(T--) solve();
    return 0;
}