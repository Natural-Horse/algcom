#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

inline int read(){
	int x = 0, f = 1; char ch = getchar();
	while(!isdigit(ch)){if(ch == '-') f = -1; ch = getchar();}
	while(isdigit(ch)){x = (x << 1) + (x << 3) + ch - 48; ch = getchar();}
	return x * f;
}

int f[35][100], lim[15], l, r;

void init(){
	for(int i = 1; i <= 31; i++){
		if(i > 1) f[i][i+28] = 1;
		for(int j = 1; j <= i+28; j++){
			for(int k = 0; k <= i-2; k++){
				f[i][j+k] += f[i-k-1][j+k-1] + f[i-k-1][j+k-1];
				f[i][j+k] += f[i-k-1][j+k+1] + f[i-k-1][j+k+1];
			}
			
		}
	}
}

inline int get(int x){
	int ans = 0, len = 0;
	while(x){
		lim[++len] = x&1;
		x >>= 1;
	} 
	for(int i = 1; i < len; i++){		
		for(int k = 30; k <= i+28; k++){
			ans += f[i][k][0] + f[i][k][1];
		}	
		
	}
	int cmp = 0;
	for(int i = len; i >= 2; --i){
		if(!lim[i]) continue;
		cmp += (lim[i] == 1? 1 : -1);
		for(int j = 30 - cmp; j <= i+28; j++){
			ans += f[i-1][j][0] + f[i-1][j][1];
		} 
	}
	return ans;
}

int main(){
	l = read(), r = read();
	init();
	int L = get(l-1);
	int R = get(r);
	int ans = R - L;
	printf("%d\n", ans);
	return 0;
}

