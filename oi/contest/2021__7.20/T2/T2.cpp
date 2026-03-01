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

const int N = 1e5 + 5;

ll n, k, p, a[N];
priority_queue<int> q;

int main(){
	n = read(), k = read();
	for(int i = 1; i <= n; i++) a[i] = read();
	for(int i = 1; i <= k; i++){
		p = read();
		ll ra = 0, rb = 0, pt = p;
		for(int j = 1; j <= p; j++) q.push(a[j]);
		while(!q.empty()){
			int x = q.top(); q.pop();
			ra += x;
			if(pt < n) q.push(a[++pt]);
			if(!q.empty()){
				int y = q.top(); q.pop();
				rb += y;
				if(pt < n) q.push(a[++pt]);
			}
		}
		printf("%lld\n", ra - rb);
	}
	return 0;
}

