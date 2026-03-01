#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

ll read(){
	int x = 0,f = 1;char ch = getchar();
	while (ch < '0' || ch > '9'){if (ch == '-') f = -1; ch = getchar();}
	while (ch >= '0' && ch <= '9'){x = x*10 + ch - 48; ch = getchar();}
	return x * f;
}

const int N = 3e5 + 5;

int n, m; 
ll a[N];
ll minn = inf, maxn, plca, plcb, sum, tot;

int main(){
	n = read(), m = read();
	for(int i = 1; i <= n; i++){
		a[i] = read();
		if(a[i] > maxn) maxn = a[i], plca = i; 
		if(a[i] < minn) minn = a[i], plcb = i;
		tot += a[i];
	}
	for(int i = 1; i <= n; i++){
		if(i != plcb){
			sum += maxn - a[i];
		}
	}
	if(sum >= m){
		printf("%lld", tot - maxn - minn + m);
	}
	else{
		ll jud = (m-sum) / (n-1);
		maxn += jud;
		int cnt = (m-sum) % (n-1);
		if(!cnt) printf("%lld", maxn * (n-2));
		else printf("%lld", (maxn+1)*(cnt-1) + maxn*(n-1-cnt));
	}
	return 0;
}

