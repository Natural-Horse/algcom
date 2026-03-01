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
int flag[N], pm[N], cnt;
int nxt[N], las[N], tot;
vector<int> vec[N], edg;
bool p[N << 1], b[N];

void Prime(){
    memset(p, true, sizeof p);
    for(int i = 2; i <= (N << 1); i++){
		if(p[i] == true){
			pm[++cnt] = i;
		}
		for(int j = 1; j <= cnt && i * pm[j] <= (N << 1); j++){
			p[i*pm[j]] = false;
			if(i % pm[j] == 0) break;
		}
	}
}

signed main(){
    // freopen("1.out", "w", stdout);
    T = read();
    Prime();
    // for(int i = 1; i <= 10000; i++) printf("%d : %d\n", i, pre[i]);
    while(T--){
        n = read();
        if(n == 2 || n == 3 || n == 4) {
            cout << "-1" << endl;
            continue;
        }
        int plc = upper_bound(pm + 1, pm + 1 + cnt, n) - pm - 1;
        for(int i = 1; i <= n; i++){
            int st = lower_bound(pm + 1, pm + 1 + cnt, i << 1) - pm;
            for(int j = st; j <= plc; j++){
                if(pm[j] - i == i) continue;
                vec[i].push_back(pm[j] - i);
                vec[pm[j]-i].push_back(i);
            }
            if(i != 1) las[i] = i - 1;
            if(i != n) nxt[i] = i + 1;
        }
        bool check = false;
        for(int i = 1; i <= n; i++){
            a[i] = i;
            if(vec[i].size() == n - 1){
                printf("-1\n");
                check = true;
                break;
            }
            else if(vec[i].size() == (n - 2)){
                edg.push_back(i);
                if(edg.size() > 2){
                    printf("-1\n");
                    check = true;
                    break;
                }
            }
        }
        if(check){
            for(int i = 1; i <= n; i++) vec[i].clear();
            continue; 
        } 
        int pos = 3, stplc = 1, tmp = 1;
        printf("1 ");
        b[1] = true;
        for(int i = 1; i < n; i++){
            while(p[a[tmp] + a[pos]] && pos) pos = nxt[pos];
            printf("%d ", a[pos]);
            las[nxt[pos]] = las[pos];
            nxt[las[pos]] = nxt[pos];
            tmp = pos;
            b[tmp] = true;
            while(b[stplc] && stplc) stplc = nxt[stplc];
            pos = stplc;
        }
        cout << endl;
        for(int i = 1; i <= n; i++) b[i] = false, vec[i].clear();
        edg.clear();
    }
    return 0;
}