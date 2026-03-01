#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
#define low(a, b) lower_bound(vec[a].begin(), vec[a].end(), b)
#define upp(a, b) upper_bound(vec[a].begin(), vec[a].end(), b)
using namespace std;

inline int read(){
	int x = 0, f = 1; char ch = getchar();
	while(!isdigit(ch)){if(ch == '-') f = -1; ch = getchar();}
	while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - 48; ch = getchar();}
	return x * f;
}

const int N = 1e5 + 5, M = 405;

int main(){
	int T = 1000000;
	system("sample.exe");
	double st = clock();
	system("std2.exe");
	double re = clock();
	system("std1.exe");
	double t3 = clock();
	if(system("fc out.out 1.out")){
		printf("Wrong Answer , time1:%.2lfms time2:%.2lfms\n", re - st, t3 - re);
		return 0;
	}
	else printf("Accepted , time1:%.2lfms time2:%.2lfms\n", re - st, t3 - re);
	return 0;
}
