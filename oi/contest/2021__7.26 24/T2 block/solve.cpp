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

int a, b, c, d, e, aa, bb, cc, dd, ee, cnt;
int q[10005];
bool check;

void add(int &u){
	u++;
	if(u > 3) u = 1;
	return;
}

void cpy(){aa = a, bb = b, cc = c, dd = d;}
void re(){a = aa, b = bb, c = cc, d = dd;cnt--;}
void op1(){cpy(); add(d), add(a), add(b);q[++cnt]=1;}
void op2(){cpy(); add(a), add(b), add(c);q[++cnt]=2;}
void op3(){cpy(); add(b), add(c), add(d);q[++cnt]=3;}
void op4(){cpy(); add(c), add(d), add(a);q[++cnt]=4;}
//void op5(){cpy(); add(c), add(e);q[++cnt]=5;}

void dfs(int u){
	if(check) return;
	if(a == 1 && b == 1 && c == 1 && d == 1 && e == 1){
		check = true;
		return;
	}
	for(int i = 1; i <= 4; i++){
		int op = rand() % 4;
		if(op == 0) op1();
		if(op == 1) op2();
		if(op == 2) op3();
		if(op == 3) op4();
		dfs(u+1), re();
	}
}

int main(){
	srand(time(0));
	a = read(), b = read(), c = read(), d = read();
	dfs(1);
	for(int i = 1; i <= cnt; i++){
		printf("%d\n", q[i]);
	}
	return 0;
}
