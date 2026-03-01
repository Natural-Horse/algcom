#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
#define mod 998244353
using namespace std;

int read(){
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9'){if(ch == '-') f = -1; ch = getchar();}
	while (ch >= '0' && ch <= '9'){x = x*10 + ch - 48; ch = getchar();}
	return x * f;
}

const int N = 1e5 + 5;

int T, n, f[N], g[N];

ll qp(ll x, ll idx){
	ll res = 1, jud = x;
	while(idx){
		if(idx & 1) res = (res % mod * jud) % mod;
		jud = (jud * jud) % mod;
		idx >>= 1;
	}
	return res;
}

void pre_work(){
	for(int i = 1; i <= N; i++){
		
	}
}

int main(){
	T = read();
	
	for(int ii = 1; ii <= T; ii++){
		n = read();
	}
}

