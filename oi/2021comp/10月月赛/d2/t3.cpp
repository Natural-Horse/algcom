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

const int N = 3e6 + 5;

ll n, q, x[N], f[N << 1], pre[N << 1];
ll mn = inf, mx = 0;
bool b[N << 1];

int main(){
    n = read(); q = read();
    for(int i = 1; i <= n; i++){
         x[i] = read();
        mn = min(mn, x[i]), mx = max(mx, x[i]);
    }
    for(int i = 1; i <= n; i++){
        x[i] = x[i] - mn + 1; b[x[i]] = true;
    }
    for(int i = 1; i <= (mx-mn+1) << 1; i++){
        if(b[i]) pre[i] = i;
        else pre[i] = pre[i-1];
        int plc = pre[i] - (i - pre[i]);
        if(plc <= 0) f[i] ++;
        else if(b[i]) f[i] = 0;
        else if(!b[plc] && pre[pre[i]-1] == pre[plc]) f[i] = f[plc] + 1;
    }
    for(int i = 1; i <= q; i++){
        int plc = read();
        if(plc < mn) {printf("0\n"); continue;}
        plc = plc - mn + 1;
        printf("%lld\n", f[plc]);
    }
    return 0;
}

