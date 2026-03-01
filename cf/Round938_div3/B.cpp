#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

inline int read(){ 
    int x = 0, f = 1; char ch = getchar();
    while(!isdigit(ch)){if(ch == '-') f = -1; ch = getchar();}
    while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - 48; ch = getchar();}
    return x * f;
}

const int N = 5e2 + 5;

int t, n, c, d, a[N*N], b[N*N], minn;
map<int, int> mp1, mp2;

int main(){
    t = read();
    while(t--){
        n = read(), c = read(), d = read();
        minn = inf;
        mp1.clear();
        for(int i = 1; i <= n*n; i++) a[i] = read(), mp1[a[i]]++, minn = min(a[i], minn);
        // printf("fab:%d %d:", t, n);
        // for(int i = 1; i <= n*n; i++) printf("%d ", a[i]);
        // printf("\n");
        b[1] = minn;
        for(int i = 1; i <= n*n; i += n){
            if(i != 1) b[i] = b[i-n] + c;
            for(int j = i+1; j < i+n; j++){
                b[j] = b[j-1] + d;
            }
        }
        bool check = true;
        // printf("\nans : ");
        for(int i = 1; i <= n*n; i++){
            // printf("%d ", b[i]);
            // if(a[i] != b[i]){check = false; break;}
            if(mp1[b[i]] == 0){check = false; break;}
            else mp1[b[i]]--;
        }
        if(check) printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}