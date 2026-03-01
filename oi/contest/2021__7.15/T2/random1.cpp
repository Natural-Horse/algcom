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

bool b[100], c[100];

int main(){
	freopen("sample1.in", "w", stdout);
	srand(time(0));
	int n = 10;
	b[0] = c[0] = true;
	for(int i = 1; i <= n; i++){
		int tmp = 0;
		while(!b[tmp]) tmp = rand()%10+1;
		printf("%d ", tmp);
	} 
	printf("\n");
	for(int i = 1; i <= n; i++){
		int tmp = 0;
		while(!c[tmp]) tmp = rand()%10+1;
		printf("%d ", tmp);
	}
	return 0;
}

