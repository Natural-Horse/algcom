#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

const int Maxn = 20, Maxm = 10, Maxv = 100;

int n, m;
int a[Maxn];

int random(int n){
	return (ll)rand() * rand() % n + 1;
}

int main(){
	freopen("sample.in", "w", stdout);
	srand(time(0));
	n = random(Maxn) + 1;
	printf("%d\n", n);
	m = random(Maxm) + 1;
	for(int i = 1; i <= n; i++){
		a[i] = random(2 * m + 1) - m;
		printf("%d ", a[i]);
	}
	printf("\n%d\n", m);
	for(int i = 1; i <= m; i++){
		int op = rand() % 4;
		if(op == 0){
			char op_ = 'Q';
			printf("%c ", op_);
			int st = random(n), re = random(n);
			if(st > re) swap(st, re);
			printf("%d %d\n", st, re);
		}
		if(op == 1){
			char op_ = 'A';
			printf("%c ", op_);
			int st = random(n), re = random(n);
			if(st > re) swap(st, re);
			printf("%d %d\n", st, re);
		}
		if(op == 2){
			char op_ = 'P';
			printf("%c ", op_);
			int st = random(n), re = random(n);
			if(st > re) swap(st, re);
			int val = random(Maxv);
			printf("%d %d %d\n", st, re, val);
		}
		if(op == 3){
			char op_ = 'C';
			printf("%c ", op_);
			int st = random(n), re = random(n);
			if(st > re) swap(st, re);
			int val = random(Maxv);
			printf("%d %d %d\n", st, re, val);
		}
	}
	return 0;
} 
