#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

inline ll read(){
    ll x = 0, f = 1; char ch = getchar();
    while(!isdigit(ch)){if(ch == '-') f = -1; ch = getchar();}
    while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - 48; ch = getchar();}
    return x * f;
}

const int N = 1e6 + 5, M = 12;

int q, k, tot[N], st[N];
ll p[N], cnt, n;
bool b[N];

ll qp(ll aa, ll bb){
    ll res = 1, jud = aa;
    while(bb){
        if(bb & 1) res *= jud;
        jud *= jud, bb >>= 1;
    }
    return res;
}

int main(){
    for(int i = 2; i <= N; i++){
        if(!b[i]) p[++cnt] = i;
        for(int j = 1; j <= cnt && i * p[j] <= N; j++){
            b[i*p[j]] = true;
            if(i % p[j] == 0) break;
        }
    }
    q = read();
    for(int i = 1; i <= q; i++){
        n = read(), k = read();
        bool check = false;
        memset(tot, 0, sizeof tot);
        for(int j = 1; j <= cnt; j++){
            while(n % p[j] == 0){
                n /= p[j], tot[j]++, check = true;
            }
        }
        if(!check){
            if(k == 1) printf("%lld\n", n);
            else printf("1\n");
        }
        else{
            ll ans = 1;
            for(int j = 1; j <= cnt; j++){
                if(tot[j] >= k) ans *= qp(p[j], tot[j]);
            }
            printf("%lld\n", ans);
        }
    }
    return 0;
}