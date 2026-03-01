#include <bits/stdc++.h>
#include <algorithm>
#define inf 0x3f3f3f3f
#define ll long long 
#define int long long
using namespace std;

inline int read(){
    int x = 0, f = 1; char ch = getchar();
    while(!isdigit(ch)){if(ch == '-') f = -1; ch = getchar();}
    while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - 48; ch = getchar();}
    return x * f;
}

const int N = 2e5 + 5;

int n, T, k, L, R;
int a[N], ls[N], c[N], tot, b_min[N], b_max[N], dis_cnt_min, dis_cnt_max;
int ptl, ptr_min, ptr_max;
int r_bound_min[N], r_bound_max[N], r_lim, ans;

void reset(){
    for(int i = 1; i <= n; i++) b_min[i] = b_max[i] = 0;
    tot = 0, dis_cnt_min = dis_cnt_max = 0;
    ptl = 1, ptr_min = ptr_max = 0;
    r_lim = 0, ans = 0;
}

void solve(){
    sort(ls + 1, ls + 1 + tot);
    tot = unique(ls + 1, ls + 1 + tot) - ls - 1;
    for(int i = 1; i <= n; i++)
        c[i] = lower_bound(ls + 1, ls + 1 + tot, a[i]) - ls;

    for(ptl = 1; ptl <= n; ptl++){
        // if(dis_cnt_min < k && ptr_min == n){
        //     r_lim = ptl - 1;
        //     break;
        // }

        while(dis_cnt_min < k && ptr_min < n){
            ptr_min++;
            if(!b_min[c[ptr_min]]) dis_cnt_min++;
            b_min[c[ptr_min]]++;
            while(ptr_max < ptr_min && ptr_max < n){
                ptr_max++;
                if(!b_max[c[ptr_max]]) dis_cnt_max++;
                b_max[c[ptr_max]]++; 
            }
            
        }

        if(dis_cnt_min < k){
            r_lim = ptl - 1;
            break;
        }

        while(dis_cnt_max == k && ptr_max < n){
            if(!b_max[c[ptr_max + 1]]) break;
            ptr_max++;
            // if(!b_max[c[ptr_max]]) dis_cnt_max++;  
            b_max[c[ptr_max]]++;
        }

        r_bound_min[ptl] = ptr_min, r_bound_max[ptl] = ptr_max;
        if(b_min[c[ptl]] == 1) dis_cnt_min --;
        if(b_max[c[ptl]] == 1) dis_cnt_max --;
        b_min[c[ptl]]--, b_max[c[ptl]]--;
        r_lim = ptl;
    }

    for(int i = 1; i <= r_lim; i++){
        // int len_max = r_bound_max[i] - i + 1;
        // int len_min = r_bound_min[i] - i + 1;
        // int fabr = (len_max >= R ? R : len_max);
        // int fabl = (len_min <= L ? L : len_min);
        // if(fabl > fabr) continue; 
        // ans += fabr - fabl + 1;
        int final_l = max(i + L - 1, r_bound_min[i]);
        int final_r = min(i + R - 1, r_bound_max[i]);
        if(final_l > final_r) continue;
        ans += final_r - final_l + 1;
    }
    if(ans < 0) ans = 0;
}

signed main(){
    T = read();
    int count = T;
    while(T--){
        n = read(), k = read(), L = read(), R = read();
        reset();
        for(int i = 1; i <= n; i++){
            a[i] = read();
            ls[++tot] = a[i];
        }
        solve();
        printf("Test %lld : ", count - T);
        printf("%lld\n", ans);
    }
    return 0;
}