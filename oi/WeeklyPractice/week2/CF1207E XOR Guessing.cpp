#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

ll f[10], l[10];
ll ans = 1;

int main(){
	printf("?");
	ll num2 = 0, num1 = 0;
	for(int i = 1; i <= 100; i++){
		printf(" %d", i);
	}
	printf("\n");
	int sc1;
	fflush(stdout);
	cin >> sc1;	
	sc1 >>= 7;
	sc1 <<= 7;
	int ii = 1;
	printf("?");
	for(int i = 1; i <= 100; i++){
		int j = i * (1 << 7);
		printf(" %d", j);
	}
	printf("\n");
	int sc2;
	fflush(stdout);
	cin >> sc2;	
	sc2 = (sc2 & ((1 << 7) - 1));
	printf("! %d", sc1 + sc2);
	return 0;
}
