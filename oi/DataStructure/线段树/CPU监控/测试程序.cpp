#include<bits/stdc++.h>
#include<cstdlib>
#include<ctime>;
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
	for(int T = 1; T <= 100000; T++){
		system("D:\\信息竞赛\\数据结构\\线段树\\CPU监控\\random.exe");
		double st = clock();
		system("D:\\信息竞赛\\数据结构\\线段树\\CPU监控\\CPU监控.exe");
		double ed = clock();
		system("D:\\信息竞赛\\数据结构\\线段树\\CPU监控\\对拍.exe");
		if(system("fc D:\\信息竞赛\\数据结构\\线段树\\CPU监控\\ans.out D:\\信息竞赛\\数据结构\\线段树\\CPU监控\\out.out")){
			puts("Wrong Answer");
			return 0;
		}
		else{
			printf("Accepted, 测试点 #%d, 用时 %.0lfms\n", T, ed - st);
		}
	}
	return 0;
}

