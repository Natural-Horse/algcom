#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
#define db double
using namespace std;

inline ll read(){
	ll x = 0, f = 1; char ch = getchar();
	while(!isdigit(ch)){if(ch == '-') f = -1; ch = getchar();}
	while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - 48; ch = getchar();}
	return x * f;
}

int T;
ll n, p, ans;

int main(){
    T = read();
    while(T--){
        ans = 0;
        n = read(), p = read();
        if(p == 1){
            printf("0\n");
            continue;
        }
        int cnt = 0;
        while(n){
            cnt ^= 1;
            ans += (n - n / p) * cnt;
            n /= p;
        }
        printf("%lld\n", ans);
    }
    return 0;
}

