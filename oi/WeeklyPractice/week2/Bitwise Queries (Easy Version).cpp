#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

const int Maxn = 7e4 + 5;

int n;
int a[Maxn];
int xr[Maxn];

void check(int xx){
	if(xx == -1){		
		exit(0);
	} 
}

int main(){
	scanf("%d", &n);
	for(int i = 2; i <= n; i++){
		printf("XOR 1 %d\n", i);
		fflush(stdout);
		scanf("%d", &xr[i]);
//		check(xr[i]);
	}
	int x = 0, y = 0, z = 0, xx = 0, yy = 0, zz = 0;
	printf("AND 1 2\n");
	fflush(stdout);
	scanf("%d", &x);
//	check(x);
	printf("AND 2 3\n");
	fflush(stdout);
	scanf("%d", &y);
//	check(y);
	printf("AND 1 3\n");
	fflush(stdout);
	scanf("%d", &z);
//	check(z);
	xx = xr[2] + 2 * x;
	yy = (xr[2] ^ xr[3]) + 2 * y;
	zz = xr[3] + 2 * z;
	a[1] = (xx + yy + zz) / 2 - yy;
	for(int i = 2; i <= n; i++){
		a[i] = xr[i] ^ a[1];
	}
	printf("! ");
	for(int i = 1; i <= n; i++) printf("%d ", a[i]);
	printf("\n");
	return 0;
} 
