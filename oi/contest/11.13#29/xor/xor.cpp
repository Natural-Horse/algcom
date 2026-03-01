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

const int N = 5e5 + 5;

int n, a[N], ans;

signed main(){
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    n = read();
    for(int i = 1; i <= n; i++) a[i] = read();
    for(int i = 2; i < n; i++){
        for(int j = 1; j < i; j++){
            for(int k = i+1; k <= n; k++){
                if(a[i] ^ a[j] < a[i] ^ a[k]) ans++;
            }
        }
    }
    printf("%lld\n", ans);
    return 0;
}

