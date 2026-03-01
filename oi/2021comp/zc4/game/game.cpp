#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
#define db double
using namespace std;

inline ll read(){
	ll x = 0, f = 1; char ch = getchar();
	while(!isdigit(ch)){if(ch == '-') f = -1; ch = getchar();}
	while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - 48; ch = getchar();}
	return x * f;
}

const int N = 1e7 + 5;

ll n, m, all, s[N];
int p[N], cnt, tot, ans[N];
bool b[N], check;

void Prime(){
    for(int i = 2; i <= N; i++){
        if(!b[i]) p[++cnt] = i;
        for(int j = 1; j <= cnt && p[j]*i <= N; j++){
            b[i*p[j]] = true;
            if(i % p[j] == 0) break;
        }
    }
}

int main(){
//    freopen("1.out", "w", stdout);
//    Prime();
    n = read(), m = read();
    ll jud = sqrt(m);
    for(int i = 2; i <= jud && i <= jud && m > 1; i++){
//        while(m % i == 0 && i <= cnt && i <= jud && m > 1){
          if(m % i == 0 && (m/i)%i != 0){
              m /= i, jud = sqrt(m); 
              s[++tot] = i, all += p[i];
          }
            
//        }
    } 
    if(m > 1) s[++tot] = m, all += m;
    printf("all : %lld\n", all);
    for(int i = 1; i <= tot; i++) printf("%d ", s[i]);
    printf("\n");
    if(all > n){
        printf("-1\n");
        return 0;
    }
    
    ll pt = n - all + 1;
    printf("pt : %lld\n", pt);
    for(int i = 1; i < pt; i++) ans[i] = 1;
    for(int i = 1; i <= tot; i++){
        int fab = 0;
        for(ll j = pt; j <= pt+s[i]-2; j++) ans[j] = j+1, fab = j;
        fab++;
        ans[fab] = pt, pt = fab + 1;
    }
    for(int i = 1; i <= n; i++) printf("%d ", ans[i]);
    printf("\n");
    return 0;
    
}

