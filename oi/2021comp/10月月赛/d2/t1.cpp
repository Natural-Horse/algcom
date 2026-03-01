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

const int N = 1e3 + 5;

int T, n, m; 

int main(){
    T = read();
    while(T--){
        bool check = false;
        n = read(), m = read();
        int lim = sqrt(n);
        for(int i = 1; i <= lim; i++){
            if(n%i==0 && ((i+1+n/i+1)<<1) <= m) {
                printf("Good\n");
                check = true;
                break;
            }
        }
        if(!check) printf("Miss\n");
    }
    return 0;
}

