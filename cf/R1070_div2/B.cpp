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

const int N = 2e5 + 5;

int T, n, ans;
string s;

void reset(){ ans = 0; }
    

void solve(){
    int l = 0, len = 0;
    int st = 0, re = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '1'){
            ans = max(ans, len);
            if(s[0] == '0' && st == 0) st = len;
            l = i, len = 0;
        }
        else{
            len++;
            if(i == n - 1) re = len;
        }
    }
    ans = max(ans, st + re);
}

int main(){
    T = read();
    while(T--){
        n = read();
        cin >> s;
        reset();
        solve();
        printf("%d\n", ans);
    }
    return 0;
}