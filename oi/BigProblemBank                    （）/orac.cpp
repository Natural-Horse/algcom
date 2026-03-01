#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

int read(){
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9'){if(ch == '-') f = -1; ch = getchar();}
	while (ch >= '0' && ch <= '9'){x = x*10 + ch - 48; ch = getchar();}
	return x * f;
}

const int N = 1e5 + 5;

int n, a[N], mx, p[N<<1], cnt;
int idx[N<<1][20], idm[N<<1];
bool b[N<<1];
ll ans = 1;

void Prime(){
	for(int i = 2; i <= mx; i++){
		if(!b[i]) p[++cnt] = i;
		for(int j = 1; j <= cnt && i * p[j] <= mx; j++){
			b[i*p[j]] = true;
			if(i % p[j] == 0) break;
		}
	}
}

ll qp(ll x, int id){
	ll res = 1, jud = x;
	while(id){
		if(id & 1) res *= jud;
		jud = jud * jud, id >>= 1;
	}
	return res;
}

int main(){
	n = read();
	for(int i = 1; i <= n; i++) a[i] = read(), mx = max(mx, a[i]);
	Prime();
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= cnt && p[j] <= sqrt(a[i]); j++){
			int jud = 0;
			while(a[i] % p[j] == 0) jud++, a[i] /= p[j];
			idx[p[j]][jud]++; idm[p[j]] = max(idm[p[j]], jud);
		}
	}
    for(int i = 1; i <= cnt; i++){
        for(int j = 0; j <= idm[p[i]]; j++) printf("%d ", idx[p[i]][j]);
        printf("\n");
    }
	for(int i = 1; i <= cnt; i++){
		for(int j = 0; j <= idm[p[i]]; j++){
			if(idx[p[i]][j] >= 2){ans *= qp(p[i], j); break;} 
		}
	}
	printf("%lld\n", ans);
	return 0;
}

