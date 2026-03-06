#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
#define pii pair<int, int>
#define mkp make_pair
using namespace std;

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    string sorted = s;
    sort(sorted.begin(), sorted.end());
    if (s == sorted) {
        cout << "Bob\n";
        return;
    }
    vector<int> idx;
    for (int i = 0; i < n; ++i) if (s[i] != sorted[i]) idx.push_back(i+1);
    cout << "Alice\n" << idx.size() << '\n';
    for (int i = 0; i < (int)idx.size(); ++i) {
        if (i) cout << ' ';
        cout << idx[i];
    }
    cout << '\n';
}

int main(){
    ios::sync_with_stdio(false), cin.tie(0);
    int T = 0; cin >> T;
    while(T--) solve();
    return 0;
}