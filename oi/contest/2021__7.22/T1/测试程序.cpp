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

int T = 100000005;

int main(){
	for(int i = 1; i <= T; i++){
		system("random.exe");
		int st = clock();
		system("T1.exe");
		int re = clock();
		system("proper.exe");
		if(system("fc print.out answer.out")){
			printf("Wrong Answer #%d, time: %d", T, re - st);
			break;
			
		}
		else{
			puts("Accepted\n");
		}
	}
	return 0;
}

