#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

ll read(){
	ll x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9'){if(ch == '-') f = -1; ch = getchar();}
	while (ch >= '0' && ch <= '9'){x = x*10 + ch - 48; ch = getchar();}
	return x * f;
}

ll n, ans; 

int main(){
	n = read();
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n && i + j <= n; j++){
			if(i*j % (i+j) == 0) ans++;
		}
	}
	printf("%lld", ans); 
	return 0;
}

