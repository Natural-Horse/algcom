#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

inline ll read(){
    ll x = 0, f = 1; char ch = getchar();
    while(!isdigit(ch)){if(ch == '-') f = -1; ch = getchar();}
    while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - 48; ch = getchar();}
    return x * f;
}

const int N = 45;

ll T, ans, k, cnt[N], pre[N], sum[N], up[N], b[N];


ll qp(ll aa, ll bb){
    ll res = 1, jud = aa;
    while(bb){
        if(bb & 1) res *= jud;
        jud *= jud, bb >>= 1;
    }
    return res;
}

void reset(){
    ans = 0;
}

void init(){
    for(int i = 1; i <= 20; i++){
        for(int j = 0; j <= 9; j++){
            sum[i] += j * (qp(10, i-1)) + sum[i-1];
        }
        for(int j = 1; j <= i; j++){
            pre[i] += j * (qp(10, j) - qp(10, j-1));
        }
        cnt[i] = pre[i] - pre[i-1]; 
    }
}

void get_bound(ll target){
    int pt = 1;
    while(target){
        up[pt] = target % 10;
        target /= 10, pt++;
    }
}

ll get_sum(ll scl, ll target){
    ll res = 0;
    get_bound(target);
    int pre_sum = 0;
    for(int i = scl; i; --i){
        // res += up[i] * sum[i-1];
        for(int j = 0; j < up[i]; j++){
            res += sum[i-1] + j * qp(10, i - 1);
            res += pre_sum * qp(10, i - 1);
        }
        if(i == 1) res += up[i] + pre_sum;
        pre_sum += up[i];
    }
    return res;
}

void solve(){
    // get_info();
    int plc = upper_bound(pre, pre + 1 + 15, k) - pre - 1;
    ll rem = k - pre[plc];
    ll quo_num = rem / (plc + 1);
    ll rem_num = rem % (plc + 1);
    ll target_num = qp(10, plc) - 1 + quo_num + 1;
    ans = get_sum(plc + 1, target_num - 1);
    if(rem_num == 0) return;
    ll pt = 0;
    while(target_num){
        ++pt;
        b[pt] = target_num % 10;
        target_num /= 10;
    }
    for(int i = 1; i <= rem_num; i++){
        ans += b[pt--];
    }
}

int main(){
    T = read();
    init();
    while(T--){
        k = read();
        reset();
        solve();
        printf("%lld\n", ans);
    }
    return 0;
}