#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

const int Maxn = 15;

ll a, b; 

ll f[15][15][15];
ll p[15];
int l[Maxn];

void init(){
	for(int i = 0; i <= 9; i++){
		f[1][i][i] = 1;
	}
	p[0] = 1;
	for(int i = 1; i <= 13; i++){
		p[i] = p[i-1] * 10;
	}
	for(int i = 2; i <= 13; i++){
		for(int j = 0; j <= 9; j++){
			for(int k = 0; k <= 9; k++){
				for(int s = 0; s <= 9; s++){
					f[i][j][k] += f[i-1][s][k];
				}
				if(k == j) f[i][j][k] += p[i];
			}
		}
	}
}

ll ansa[15], ansb[15];

void get(int x){
	ll len = 0;
	memset(l, 0, sizeof(l));
	while(x){
		l[++len] = x % 10;
		x /= 10;
	}
	for(int i = 1; i < len; i++){
		for(int j = 0; j <= 9; j++){
			for(int k = 0; k <= 9; k++){
				ansa[k] += f[i][j][k];
			}
		}
	}
	for(int i = 1; i < l[len]; i++){
		for(int j = 0; j <= 9; j++) ansa[j] += f[len][i][j];
	}
	for(int i = len-1; i >= 1; --i){
		for(int j = 0; j < l[i]; j++){
			for(int k = 0; k <= 9; k++){
				ansa[k] += f[i][j][k];
			}
		}
	}
}

void get_(int x){
	ll len = 0;
	memset(l, 0, sizeof(l));
	while(x){
		l[++len] = x % 10;
		x /= 10;
	}
	for(int i = 1; i < len; i++){
		for(int j = 0; j <= 9; j++){
			for(int k = 0; k <= 9; k++){
				ansb[k] += f[i][j][k];
			}
		}
	}
	for(int i = 1; i < l[len]; i++){
		for(int j = 0; j <= 9; j++) ansb[j] += f[len][i][j];
	}
	for(int i = len-1; i >= 1; --i){
		for(int j = 0; j < l[i]; j++){
			for(int k = 0; k <= 9; k++){
				ansb[k] += f[i][j][k];
			}
		}
	}
}

int main(){
	init();
	scanf("%lld %lld", &a, &b);
	get(a-1);
	get_(b);
	for(int i = 0; i <= 9; i++){
		printf("%lld ", ansb[i] - ansa[i]);
	}
	return 0;
}
