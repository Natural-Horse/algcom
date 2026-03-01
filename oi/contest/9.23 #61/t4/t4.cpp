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

const int N = 5e3 + 5;

int n, a[N], s[N], f[N][N]; 
int stk[N][N], top[N];

bool cmp(int aa, int bb){
    return aa > bb;
}

int main(){
    n = read();
    for(int i = 1; i <= n; i++) a[i] = read(), s[i] = s[i-1] + a[i];
    sort(s + 1, s + 1 + n, cmp);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= 9; i++){
            int p = s[j] * (s[i] - s[j]), t = s[i] - s[j];
            
        }
    }
}

