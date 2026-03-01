#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

int read(){
	int x = 0,f = 1;char ch = getchar();
	while (ch < '0' || ch > '9'){if (ch == '-') f = -1; ch = getchar();}
	while (ch >= '0' && ch <= '9'){x = x*10 + ch - 48; ch = getchar();}
	return x * f;
}

const int N = 3e3 + 5;
const int mod = (1 << 30);

int n, m, T;
ll pre[N], sum[N];
ll p[N], cnt, f[N], jud[N];
bool pm[N], b[N];

void Prime(){
	for(int i = 2; i <= N; i++){
		if(!b[i]){
			p[++cnt] = i;
			pm[i] = true;
		}
		for(int j = 1; j <= cnt && i*p[j] <= N; j++){
			b[i*p[j]] = true;
			if(i % p[j] == 0){
				break;
			}
		}
	}
	for(int i = 1; i <= N; i++){
		f[i] = f[i-1] + (pm[i]==true);
		sum[i] = sum[i-1] + f[i];
		pre[i] = pre[i-1] + i;
	}		
}



int main(){
	T = read();
	Prime();
	for(int ii = 1; ii <= T; ii++){
		n = read(), m = read();
		ll ans = 0;
		for(int i = 1; i < n-1; i++){
			
		}
		printf("%lld", (ans + 2) % mod);
	}
	return 0;
}
