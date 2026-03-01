#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

inline ll read(){ 
    ll x = 0, f = 1; char ch = getchar();
    while(!isdigit(ch)){if(ch == '-') f = -1; ch = getchar();}
    while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - 48; ch = getchar();}
    return x * f;
}

const int N = 2e5 + 5;

ll t, n, k, a[N], b[N], pre[N], suf[N];

int main(){
    t = read();
    while(t--){
        n = read(), k = read();
        for(int i = 1; i <= n; i++) a[i] = read(), pre[i] = pre[i-1] + a[i];
        // for(int i = 1, j = n; i <= j; i++, j--){
        //     // b[i*2-1] = a[i];
        //     // pre[i*2-1] = pre[i*2-2] + a[i];
        //     // if(i < j){
        //     //     b[i*2] = a[j];
        //     //     pre[i*2] = pre[i*2-1] + a[j];
        //     // }
            
        // }
        for(int i = n; i; --i) suf[n+1-i] = suf[n+1-(i+1)] + a[i];
        // printf("\nsuf: ");
        // for(int i = 1; i <= n; i++) printf("%lld ", suf[i]);
        // printf("\n");
        if(pre[n] <= k){
            printf("%lld\n", n);
            continue;
        }
        ll r = k >> 1, l = k - r;
        int plc1 = lower_bound(pre + 1, pre + n + 1, l) - pre;
        int plc2 = lower_bound(suf + 1, suf + 1 + n, r) - suf;
        // printf("plc1:%d, plc2:%d, l:%lld, r%lld, pre1:%lld, pre2:%lld\n", plc1, plc2, l, r, pre[plc1], pre[plc2]);
        if(pre[plc1] > l) plc1--;
        if(suf[plc2] > r) plc2--;
        printf("%d\n", plc1 + plc2);
        for(int i = 1; i <= n; i++) a[i] = b[i] = pre[i] = suf[i] = 0;
    }

    return 0;
}