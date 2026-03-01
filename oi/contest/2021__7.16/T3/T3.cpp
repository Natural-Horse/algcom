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

const int N = 1e6 + 5;

int pre[N], cnt[N];
int n, p, k, ans;

int main(){
	n = read(), p = read(), k = read();
	int jud = 1, num = 0;
	while(jud <= n){
		jud *= p;
		cnt[jud] = ++num;
	}
	for(int i = 1; i <= n; i++) pre[i] = pre[i-1] + cnt[i];
	for(int l = 0; l <= n; l++){
		for(int s = 0; s <= l; s++){
			if(pre[l] - pre[l-s] - pre[s] >= k) ans++;
		}
	}
//	ans *= 2;
	printf("%d", ans);
	return 0;
}

