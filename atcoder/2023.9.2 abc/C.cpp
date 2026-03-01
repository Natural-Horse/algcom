#include<bits/stdc++.h>
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

ll n, d, p, f[N], ans;

bool cmp(int aa, int bb){
    return aa > bb;
}

int main(){
    n = read(), d = read(), p = read();
    for(int i = 1; i <= n; i++) f[i] = read();
    sort(f + 1, f + 1 + n, cmp);
    for(int i = 1; i <= n; i += d){
        ll cnt = 0, jud = 0;
        for(int j = i; j <= i + d - 1 && j <= n; j++){
            cnt++, jud += f[j];
        }
        ans += min(jud, p);
    }
    printf("%lld\n", ans);
    return 0;
}