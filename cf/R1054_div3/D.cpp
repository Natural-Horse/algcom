#include <bits/stdc++.h>
#define inf 1000000000000
#define ll long long 
using namespace std;

inline int read(){
    int x = 0, f = 1; char ch = getchar();
    while(!isdigit(ch)){if(ch == '-') f = -1; ch = getchar();}
    while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - 48; ch = getchar();}
    return x * f;
}

const int N = 2e5 + 5;

int n, T, a[N], b[N];
ll cnta, cntb, ans;
string s;

void reset(){
    cnta = cntb = 0;
    ans = inf;
}

ll check(int plc[], int mid, int cnt){
    ll jud = 0, res = 0;
    for(int i = mid + 1; i <= cnt; i++){
        res += plc[i] - plc[mid] - 1 - jud;
        jud++;
    }
    jud = 0;
    for(int i = mid - 1; i; --i){
        res += plc[mid] - plc[i] - 1 - jud;
        jud++;
    }
    return res;
}

void solve(){
    for(int i = 0; i < s.length(); i++){
        if(s[i] == 'a') a[++cnta] = i + 1;
        else if(s[i] == 'b') b[++cntb] = i + 1;
    }
    if(cnta){
        if(cnta & 1) ans = min(ans, check(a, cnta / 2 + 1, cnta));
        else{
            ans = min(ans, check(a, cnta / 2, cnta));
            ans = min(ans, check(a, cnta / 2 + 1, cnta));
        } 
    }
    if(cntb){
        if(cntb & 1) ans = min(ans, check(b, cntb / 2 + 1, cntb));
        else{
            ans = min(ans, check(b, cntb / 2, cntb));
            ans = min(ans, check(b, cntb / 2 + 1, cntb));
        }
    }
    
}

int main(){
    T = read();
    int count = T;
    while(T--){
        n = read();
        reset();
        cin >> s;
        solve();
        // printf("Test %d : ", count - T);
        printf("%lld\n", ans);
    }
    return 0;
}