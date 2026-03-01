#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

int n, m;
int f[15][15];
int l[15], len;

void init(){
	for(int i = 0; i <= 9; i++){
		if(i == 4) continue;
		f[1][i] = 1;
	}
	for(int i = 2; i <= 10; i++){
		for(int j = 0; j <= 9; j++){
			if(j == 4) continue;
			for(int k = 0; k <= 9; k++){
				if(j != 6 || k != 2) f[i][j] += f[i-1][k];
			}
		}
	}
}

int get(int x){
	int ans = 0;
	len = 0;
	memset(l, 0, sizeof(l));
	while(x){
		l[++len] = x % 10;
		x /= 10;
	}
	for(int i = 1; i < len; i++){
		for(int j = 1; j <= 9; j++) ans += f[i][j];
	}
	for(int i = 1; i < l[len]; i++) ans += f[len][i];
	for(int i = len-1; i >= 1; --i){
		if(l[i+1] == 4) break;
		for(int j = 0; j < l[i]; j++){
			if(l[i+1] != 6 || j != 2) ans += f[i][j];
		}
		if(l[i+1]==6&&l[i]==2)break;
	}
	return ans;
}

int main(){
	init();
	scanf("%d %d", &n, &m);
	do{
		int a = get(n);
		int b = get(m+1);
		printf("%d\n", b - a);
		scanf("%d %d", &n, &m);
	}while(n != 0 || m != 0);
	return 0;	
} 
