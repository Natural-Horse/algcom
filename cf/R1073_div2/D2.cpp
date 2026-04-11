#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
#define pii pair<int, int>
#define mkp make_pair
using namespace std;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    vector<int> nxt(n, 0), sufl(n, 0), sufr(n, 0);
    int lasl = n + 1, sumr = 0, suml = 0;
    for (int i = n - 1; i >= 0; --i) {
        nxt[i] = lasl;
        sufr[i] = sumr;
        sufl[i] = suml;
        if (s[i] == '(') lasl = i, suml++;
        else sumr++;
    }
    int ans = inf;
    for (int i = 0; i < n - 1; i++) { 
        if (s[i] == ')' && nxt[i] < n && sufl[nxt[i]] >= nxt[i] - i) 
            ans = min(ans, 2 * (nxt[i] - i));
    }
    if(ans == inf) cout << "-1\n";
    else cout << n - ans << endl;;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int T = 0; cin >> T;
    while (T--) solve();
    return 0;
}