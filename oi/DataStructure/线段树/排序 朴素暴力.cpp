#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

const int Maxn = 1e6;

int a[Maxn + 5];
int n, m, p;

bool cmp(int a, int b){
	return a > b;
}

int main(){
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
	}
	for(int i = 1; i <= m; i++){
		int op, st, re;
		scanf("%d %d %d", &op, &st, &re);
		if(op == 0) sort(a + st + 1, a + re + 1);
		if(op == 1) sort(a + st + 1, a + re + 1, cmp);
	}
	scanf("%d", &p);
	printf("%d", a[p]);
	return 0;
} 
