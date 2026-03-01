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

const int N = 2e5 +5;
int n;
int a[N], l[N], r[N], pre[N], suf[N], tot;
bool b[N];

int main(){
	n = read();
	for(int i = 1; i <= n; i++){
		a[i] = read();
		if(!a[i]) b[i] = true;
	} 
	printf("-1");
	return 0;
}

