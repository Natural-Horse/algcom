#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;

    vector<int> cnt(n + 1, 0);
    
    for(int i = 0; i < (1 << n); i++){
        int k;
        if(i == 0) {
            k = n; 
        } else {
            int lg = 31 - __builtin_clz(i);
            k = n - 1 - lg;
        }

        int val = (cnt[k] << (k + 1)) | ((1 << k) - 1);
        cout << val << " ";
        
        cnt[k]++;
    }
    cout << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}