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

int n;

signed main(){
    freopen("rox.in", "r", stdin);
    freopen("rox.out", "w", stdout);
    n = read();
    ll res = 0;
    for(int i = 1; i < n; i++) res += i ^ (n-i);
    printf("%lld\n", res); 
    return 0;
}

