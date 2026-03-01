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

const int N = 31;

int n, k, cnt;
int c[N];

int main(){
	n = read(), k = read();
	for(int i = 1; i <= n; i++){
		char ch = getchar();
		if(ch == 'W') c[i] = 0, cnt++;
		else c[i] = 1;
	}
	if(k == 0){
		printf("0");
		return 0;
	}
	if(k == n){
		printf("%d", cnt);
		return 0;
	}
}

