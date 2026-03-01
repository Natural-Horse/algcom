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

int T = 1000005;

int main(){
	for(int i = 1; i <= T; i++){
		system("random.exe");
		system("T2.exe");
		int st = clock();
		system("checker.exe");
		int re = clock();
		if(system("fc output.out answer.out")){
			printf("Wrong Answer on #%d", i);
			break;
		}
		else printf("Accepted  #%d, time:%d\n", i, re-st);
	}
	return 0;
}

