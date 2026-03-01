#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
#define db double
using namespace std;

inline int read(){
	int x = 0, f = 1; char ch = getchar();
	while(!isdigit(ch)){if(ch == '-') f = -1; ch = getchar();}
	while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - 48; ch = getchar();}
	return x * f;
}

int main(){
    int T = 100000;
    for(int i = 1; i <= T; i++){
        system("sample.exe");
        int st = clock();
        system("zj.exe");
        int re = clock();
        system("bf.exe");
        if(system("fc out.out ans.out")){
            printf("Wrong Answer on test#%d, time:%d\n", i, re - st);
            return 0;
        }
        else printf("Accepted  test#%d, time:%d\n", i, re - st);
    }
    return 0;
}
