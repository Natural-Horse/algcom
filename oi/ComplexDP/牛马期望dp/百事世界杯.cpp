#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
#define db double
#define int long long
using namespace std;

inline int read(){
	int x = 0, f = 1; char ch = getchar();
	while(!isdigit(ch)){if(ch == '-') f = -1; ch = getchar();}
	while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - 48; ch = getchar();}
	return x * f;
}

const int N = 50;

int n, f[N], g[N];

ll gcd(ll x, ll y){
    return y == 0 ? x : gcd(y, x % y);
}
void dev(ll &x, ll &y){
    int d = gcd(x, y);
//    printf("%lld ", d);
    x /= d, y /= d;
}

signed main(){
    n = read();
    f[0] = 0, g[0] = 1;
    for(int i = 1; i <= n; i++){
        g[i] = g[i-1] * i, f[i] = f[i-1]*i + n*g[i-1];
        dev(f[i], g[i]);
//        printf("%lld %lld\n", f[i], g[i]);
    }
    if(g[n] == 1) printf("%lld\n", f[n]);
    else{
        int fab = f[n] / g[n], fabb = fab;
        f[n] %= g[n]; int jud = g[n];
        int pt1 = 0, pt2 = 0;
        while(fabb) pt1++, fabb /= 10;
        while(jud) pt2++, jud /= 10;
        for(int i = 1; i <= pt1; i++) printf(" ");
        printf("%lld\n", f[n]);
        printf("%lld", fab);
        for(int i = 1; i <= pt2; i++) printf("-");
        printf("\n");
        for(int i = 1; i <= pt1; i++) printf(" ");
        printf("%lld\n", g[n]);
    }
    
    return 0;
}

