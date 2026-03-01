#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
#define int long long
using namespace std;

inline ll read(){
    ll x = 0, f = 1; char ch = getchar();
    while(!isdigit(ch)){if(ch == '-') f = -1; ch = getchar();}
    while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - 48; ch = getchar();}
    return x * f;
}

int n, k;

void solve(){
    if(k & 1){
        for(int i = 1; i <= k; i++) printf("%lld%c", n, i == k ? '\n' : ' ');
    }
    else{
        vector<int> bits;
        for(int i = 0; i < 62; i++){
            if((n >> i) & 1) bits.push_back(i);
        }

        int cnt = bits.size();
        int m = min(cnt, k);
        if(m & 1) m--;

        if(m == 0){
            for(int i = 1; i <= k - 2; i++) printf("%lld ", n);
            printf("%lld 0\n", n);
        }
        else{
            vector<int> x(m, 0);
            vector<int> msb(m, -1);

            for(int i = 0; i < m - 1; i++){
                int b = bits.back(); bits.pop_back();
                x[i] |= (1LL << b);
                msb[i] = b;
            }
            while(!bits.empty()){
                int b = bits.back(); bits.pop_back();
                x[m - 1] |= (1LL << b);
                if(msb[m - 1] == -1) msb[m - 1] = b; 
            }

            for(int i = 0; i < 62; i++){
                if(!((n >> i) & 1)){ 
                    vector<int> candidates;
                    for(int j = 0; j < m; j++){
                        if(msb[j] > i) candidates.push_back(j);
                    }

                    int count = candidates.size();
                    if(count & 1) count--; 

                    for(int j = 0; j < count; j++){
                        x[candidates[j]] |= (1LL << i);
                    }
                }
            }

            for(int i = 0; i < m; i++) printf("%lld ", n ^ x[i]);
            for(int i = 0; i < k - m; i++) printf("%lld%c", n, i == k - m - 1 ? '\n' : ' ');
            if(k == m) printf("\n");
        }
    }
}

signed main(){
    int T = read();
    while(T--){
        n = read(); k = read();
        solve();
    }
    return 0;
}