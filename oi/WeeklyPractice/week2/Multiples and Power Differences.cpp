#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

const int Maxn = 505;

int n, m;
int a[Maxn][Maxn], b[Maxn][Maxn];

int gcd(int x, int y){
	return y == 0? x: gcd(y, x % y);
} 

int jud = 1;
int p[35];
bool c[35][20];
int num[20];

void init(){
	for(int i = 1; i <= 29; i++){
		p[i] = i * i * i * i;
		int sum = jud - p[i];
		for(int j = 1; j <= 16; j++){
			if(sum % j == 0 && !num[j]){
				num[j] = sum;
				break;
			} 
		}
	}
}

int main(){
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			scanf("%d", &a[i][j]);
		}
	}
	for(int i = 1; i <= 16; i++) jud = i / gcd(jud, i) * jud;
	init();	
	for(int i = 1; i <= n; i++){
		for(int j = i % 2; j <= m; j += 2){
			if(j != 0) b[i][j] = jud;
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = (i+1) % 2; j <= m; j += 2){
			if(j == 0) continue;
			b[i][j] = num[a[i][j]];
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			printf("%d ", b[i][j]);
		}
		printf("\n");
	}
	return 0;
}
