#include <bits/stdc++.h>
#define inf 1e9 + 10
#define ll long long
#define db double
using namespace std;

const int N = 2e6 + 5;
int T;

void solve(){
    int n = 0; cin >> n;
    vector<int> x(n + 1, 0);
    int st = 1, jud = 0, l = 0, r = inf, ans = 0;
    for(int i = 1; i <= n; i++) cin >> x[i];
    for(int i = 1; i <= n; i++){
        if(i != 1) ans++;
        if (i != n){
            
            if (!((i - st) & 1)) {
                jud += x[i+1] - x[i];
                r = min(r, jud); 
            }
            else {
                jud -= x[i+1] - x[i];
                l = max(l, jud);
            }
            if (l >= r) {
                ans--;
                st = i;
                l = 0, r = x[i+1]-x[i], jud = x[i+1]-x[i];
            }
        }
    }
    // cout << "ans : ";
    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false) , cin.tie(0);
    cin >> T;
    while(T--) solve();
    return 0;
}