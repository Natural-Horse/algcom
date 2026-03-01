#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

int read(){
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9'){if(ch == '-') f = -1; ch = getchar();}
	while (ch >= '0' && ch <= '9'){x = x*10 + ch - 48; ch = getchar();}
	return x * f;
}

int n, type;

int main(){
	freopen("sample.in", "w", stdout);
	srand(time(0));
	n = rand() % 1000 + 1; type = 1;
	printf("%d %d\n", n, type);
	for(int i = 1; i <= n; i++){
		int fab = rand() % 1000000 + 1;
		printf("%d ", fab);
	}
	return 0;
}

