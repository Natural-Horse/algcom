#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

const int N = 2e5 + 5;

void solve(){
    int n, k; 
    cin >> n >> k;
    vector<int> a(n + 1, 0), b(n + 1, 0);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        b[a[i]]++;
    }
    int div = n - k + 1, mex = 0, res = 0;
    for(int i = 0; i <= n; i++) {
        if (b[i]) {
            mex = i + 1;
        }
        else break;
    }
    mex = min(k - 1, mex);
    // cout << "ans : ";
    cout << mex << endl;
}

int main(){
    ios::sync_with_stdio(false), cin.tie(0);
    int T = 0;
    cin >> T;
    while(T--) solve();
    return 0;
}