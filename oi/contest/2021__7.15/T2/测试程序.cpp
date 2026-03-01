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

int main(){
	for(int T = 1; T <= 10005; T++){
		system("random1.exe");
		double st = clock();
		system("T2 正解.exe");
		double re = clock();
		system("T2__题解checker.exe");
		if(system("fc output.out answer.out")){
			puts("Wrong Answer");
			return 0;
		}
		else printf("Accepted, 测试点 #%d, 用时 %.0lfms\n", T, re - st);
	}
	return 0;
}

