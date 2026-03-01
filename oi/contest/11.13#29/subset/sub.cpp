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

const int N = 1e4 + 5;

int n, m, a[N], b[N], cnt, f[N], pre[N];

inline ll c(ll x, ll y){
    return pre[x] / pre[x-y] / pre[y]; 
}

signed main(){
    freopen("subset.in", "r", stdin);
    freopen("subset.out", "w", stdout);
    n = read(), m = read();
    for(int i = 0; i <= m; i++) b[i] = read();
    pre[0] = 1;
    for(int i = 1; i <= n; i++) pre[i] = pre[i-1] * i;
    for(int i = 1; i < b[0]; i++) a[++cnt] = 0;
    f[0] = 1;
    for(int i = 1; i <= m; i++){
        int fab = b[i] - f[i];
        for(int j = m; j >= 0; --j){
            for(int k = 1; k <= fab && j + k*i <= m; k++){
                f[j+k*i] += f[j] * c(fab, k);
            } 
        }
        for(int j = 1; j <= fab; j++) a[++cnt] = i;
    }
    for(int i = 1; i <= n; i++) printf("%lld ", a[i]);
    printf("\n");
}

