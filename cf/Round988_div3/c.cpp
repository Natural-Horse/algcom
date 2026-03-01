// clang-format off
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
// #define int long long
using namespace std;

inline int read(){
    int x = 0, f = 1; char ch = getchar();
    while(!isdigit(ch)){if(f == '-') f = -1; ch = getchar();}
    while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - 48; ch = getchar();}
    return x * f;
}

const int N = 2e5 + 5; 
int T, n, a[N], ans;
// int flag[N], pm[N], cnt;
// int nxt[N], las[N], tot;
// vector<int> vec[N], edg;
// bool p[N << 1], b[N];

// void Prime(){
//     memset(p, true, sizeof p);
//     for(int i = 2; i <= (N << 1); i++){
// 		if(p[i] == true){
// 			pm[++cnt] = i;
// 		}
// 		for(int j = 1; j <= cnt && i * pm[j] <= (N << 1); j++){
// 			p[i*pm[j]] = false;
// 			if(i % pm[j] == 0) break;
// 		}
// 	}
// }

signed main(){
    // freopen("1.out", "w", stdout);
    T = read();
    // Prime();
    // for(int i = 1; i <= 10000; i++) printf("%d : %d\n", i, pre[i]);
    while(T--){
        n = read();
        if(n <= 4){cout << "-1\n"; continue;}
        for(int i = 1; i <= n; i += 2){
            if(i != 5) printf("%d ", i);
        }
        printf("5 4 ");
        for(int i = 2; i <= n; i += 2){
            if(i != 4) printf("%d ", i);
        } 
    }
    return 0;
}