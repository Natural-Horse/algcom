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

const int N = 5e3 + 5;

int T, p, a, b, ans;
bool check[N];

void reset(){
    ans = 0;
    memset(check, false, sizeof check);
}

void solve(){
    check[a] = true;
    int tmp = a;
    ans = a;
    for(int i = 1; i <= p; i++){
        tmp = (tmp + b) % p;
        if(check[tmp]) break;
        ans = max(ans, tmp);
    }
}

int main(){
    T = read();
    while(T--){
        p = read(), a = read(), b = read();
        reset();
        solve();
        // printf("ans : ");
        printf("%d\n", ans);
    }
    return 0;
}