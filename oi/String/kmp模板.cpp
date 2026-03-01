#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

inline int read(){
	int x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9'){if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - 48; ch = getchar();}
	return x * f;
}

const int N = 1e6 + 5;

int n, m, kmp[N];
char s[N], p[N];

int main(){
	scanf("%s", s + 1);
	scanf("%s", p + 1);
	n = strlen(s + 1), m = strlen(p + 1);
	int pt = 0; 
	for(int i = 2; i <= m; i++){
		while(pt && p[pt+1] != p[i]) pt = kmp[pt];
		if(p[i] == p[pt+1]) pt++;
		kmp[i] = pt;
	}
	pt = 0;
	for(int i = 1; i <= n; i++){
		while(pt && p[pt+1] != s[i]) pt = kmp[pt];
		if(p[pt+1] == s[i]) pt++;
		if(pt == m){printf("%d\n", i - m + 1); pt = kmp[pt];} 
	}
	for(int i = 1; i <= m; i++) printf("%d ", kmp[i]);
	printf("\n");
	return 0;
}