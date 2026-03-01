#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

inline int read(){
    int x = 0, f = 1; char ch = getchar();
    while(!isdigit(ch)){if(ch == '-') f = -1; ch = getchar();}
    while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - 48; ch = getchar();}
    return x * f;
}

const int N = 5e5 + 5;

int T, n, m, b[30];
string s, t, ans;

void reset(){
    ans.clear();
    memset(b, 0, sizeof b);
}

void solve(){
    n = s.length(), m = t.length();
    for(auto c : t) b[c - 'a' + 1]++;
    for(auto c : s){
        if(!b[c - 'a' + 1]){
            ans = "Impossible";
            return;
        }
        b[c - 'a' + 1]--;
    }
    int tmp_s = 0;
    for(int i = 1; i <= 26; i++){
        while(s[tmp_s] - 'a' + 1 <= i && tmp_s < n){
            ans += s[tmp_s];
            tmp_s++;
        }
        for(int j = 1; j <= b[i]; j++){
            ans += static_cast<char>(i + 'a' - 1);
        }
    }
}

int main(){
    T = read();
    while(T--){
        cin >> s >> t;
        reset();
        solve();
        // cout << "ans : ";
        cout << ans << endl;
    }
    return 0;
}