#include<bits/stdc++.h>
#define inf 2147483647
#define ll long long
#define db double
#define R register
using namespace std;

inline int read(){
	int x = 0, f = 1; char ch = getchar();
	while(!isdigit(ch)){if(ch == '-') f = -1; ch = getchar();}
	while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - 48; ch = getchar();}
	return x * f;
}

const int N = 5e4 + 5, B = 305;

struct Q{
    int op, l, r, k;
}q[N];
int n, m, S, L, ls[N << 3], tot, num, P, C;
int f[B][B], g[B][N], a[N], bl[N], cl[N], h[B], p[N];

int qr_rk(int l, int r, int val){
    int res = 1;
    if(bl[l] == bl[r]){
        for(R int i = l; i <= r; i++){
            if(a[i] < val) res++;
        }
        return res;
    }
    else{
        for(R int i = l; i <= bl[l]*S; i++) res += (a[i] < val);
        for(R int i = (bl[r]-1)*S+1; i <= r; i++) res += (a[i] < val);
        for(R int i = 1; i < cl[val]; i++) res += f[bl[r]-1][i] - f[bl[l]][i];
        for(R int i = (cl[val]-1)*L+1; i < val; i++) res += g[bl[r]-1][i] - g[bl[l]][i];
        return res;
    }
}
int qr_val(int l, int r, int rk){
    int fab = 0;
    if(bl[l] == bl[r]){
        for(R int i = l; i <= r; i++) h[cl[a[i]]]++, p[a[i]]++;
        for(R int i = 1; i <= C; i++){
            rk -= h[i], fab = i;
            if(rk <= 0) break;
        }
        rk += h[fab], fab--;
        int res = 0;
        for(R int i = fab*L+1; i <= min(num, (fab+1)*L); i++){
            rk -= p[i], res = i;
            if(rk <= 0) break;
        }
        for(R int i = l; i <= r; i++) h[cl[a[i]]]--, p[a[i]]--;
        return res;
    }
    else{
        for(R int i = l; i <= bl[l]*S; i++) h[cl[a[i]]]++, p[a[i]]++;
        for(R int i = (bl[r]-1)*S+1; i <= r; i++) h[cl[a[i]]]++, p[a[i]]++;
        for(R int i = 1; i <= C; i++){
            int jud = f[bl[r]-1][i] - f[bl[l]][i] + h[i];
            rk -= jud, fab = i;
            if(rk <= 0) break;
        }
        rk += h[fab] + f[bl[r]-1][fab] - f[bl[l]][fab], fab--;
        int res = 0;
        for(R int i = (fab*L)+1; i <= min((fab+1)*L, num); i++){
            int jud = g[bl[r]-1][i] - g[bl[l]][i] + p[i];
            rk -= jud, res = i;
            if(rk <= 0) break;
        }
        for(R int i = l; i <= bl[l]*S; i++) h[cl[a[i]]]--, p[a[i]]--;
        for(R int i = (bl[r]-1)*S+1; i <= r; i++) h[cl[a[i]]]--, p[a[i]]--;
        return res;
    }
}
void op_dev(int plc, int val){
    for(R int i = bl[plc]; i <= P; i++){
        f[i][cl[a[plc]]]--, f[i][cl[val]]++;
        g[i][a[plc]]--, g[i][val]++;
    }
    a[plc] = val;
}
int qr_pre(int l, int r, int val){
    int fab = 0, res = 0; bool check = false;
    if(bl[l] == bl[r]){
        for(R int i = l; i <= r; i++) h[cl[a[i]]]++, p[a[i]]++;
        for(R int i = val-1; i >= (cl[val]-1)*L+1; --i) if(p[i]){res = fab = i, check = true; break;}
        if(!fab) for(R int i = cl[val]-1; i; --i) if(h[i]){fab = i; break;}
        if(!check && fab) for(R int i = fab*L; i >= (fab-1)*L+1; --i) if(p[i]){res = i; break;}
        for(R int i = l; i <= r; i++) h[cl[a[i]]]--, p[a[i]]--;
        if(!fab) return 1;
        else return fab;
    }
    else{
        for(R int i = l; i <= bl[l]*S; i++) h[cl[a[i]]]++, p[a[i]]++;
        for(R int i = (bl[r]-1)*S+1; i <= r; i++) h[cl[a[i]]]++, p[a[i]]++;
        for(R int i = val-1; i >= (cl[val]-1)*L+1; --i) if(p[i]+g[bl[r]-1][i]-g[bl[l]][i]){res = fab = i, check = true; break;}
        if(!fab) for(R int i = cl[val]-1; i; --i) if(h[i]+f[bl[r]-1][i]-f[bl[l]][i]){fab = i; break;}
        if(!check && fab) for(R int i = fab*L; i >= (fab-1)*L+1; --i) if(p[i]+g[bl[r]-1][i]-g[bl[l]][i]){res = fab = i; break;}
        for(R int i = l; i <= bl[l]*S; i++) h[cl[a[i]]]--, p[a[i]]--;
        for(R int i = (bl[r]-1)*S+1; i <= r; i++) h[cl[a[i]]]--, p[a[i]]--;
        if(!fab) return 1;
        else return fab;
    }
}
int qr_suf(int l, int r, int val){
    int fab = 0, res = 0; bool check = false;
    if(bl[l] == bl[r]){
        for(R int i = l; i <= r; i++) h[cl[a[i]]]++, p[a[i]]++;
        for(R int i = val+1; i <= cl[val]*L; i++) if(p[i]){res = fab = i, check = true; break;}
        if(!fab) for(R int i = cl[val]+1; i <= C; i++) if(h[i]){fab = i; break;}
        if(!check && fab) for(R int i = (fab-1)*L+1; i <= min(num, fab*L); i++) if(p[i]){res = i; break;}
        for(R int i = l; i <= r; i++) h[cl[a[i]]]--, p[a[i]]--;
        if(!fab) return num;
        else return res;
    }
    else{
        for(R int i = l; i <= bl[l]*S; i++) h[cl[a[i]]]++, p[a[i]]++;
        for(R int i = (bl[r]-1)*S+1; i <= r; i++) h[cl[i]]++, p[a[i]]++;
        for(R int i = val+1; i <= cl[val]*L; i++) if(p[i]+g[bl[r]-1][i]-g[bl[l]][i]){res = fab = i, check = true; break;}
        if(!fab) for(R int i = cl[val]+1; i <= C; i++) if(h[i]+f[bl[r]-1][i]-f[bl[l]][i]){fab = i; break;}
        if(!check && fab) for(R int i = (fab-1)*L+1; i <= min(num, fab*L); i++) if(p[i]+g[bl[r]-1][i]-g[bl[l]][i]){res = i; break;}
        for(R int i = l; i <= bl[l]*S; i++) h[cl[a[i]]]--, p[a[i]]--;
        for(R int i = (bl[r]-1)*S+1; i <= r; i++) h[cl[i]]--, p[a[i]]--;
        if(!fab) return num;
        else return res;
    }
}

int main(){
    freopen("P3380_1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    n = read(), m = read(); S = sqrt(n), P = n / S + (n % S != 0);
    for(int i = 1; i <= n; i++) a[i] = read(), ls[++tot] = a[i];
    for(int i = 1, op; i <= m; i++){
        q[i].op = read();
        if(q[i].op == 1){
            q[i].l = read(), q[i].r = read(), q[i].k = read(); 
            ls[++tot] = q[i].k;
        }
        else if(q[i].op == 2) q[i].l = read(), q[i].r = read(), q[i].k = read();
        else if(q[i].op == 3) q[i].l = read(), q[i].k = read(), ls[++tot] = q[i].k;
        else{
            q[i].l = read(), q[i].r = read(), q[i].k = read();
            ls[++tot] = q[i].k;
        }
    }
    ls[++tot] = -inf, ls[++tot] = inf;
    sort(ls + 1, ls + 1 + tot);
    num = unique(ls + 1, ls + 1 + tot) - ls - 1;
    L = sqrt(num), C = num / L + (num % L != 0);
    for(int i = 1; i <= num; i++) cl[i] = (i-1) / L + 1;
    for(int i = 1; i <= n; i++) a[i] = lower_bound(ls + 1, ls + 1 + num, a[i]) - ls;
    for(int i = 1; i <= n; i++){
        bl[i] = (i-1) / S + 1;
        f[bl[i]][cl[a[i]]]++, g[bl[i]][a[i]]++;
    }
    for(int i = 1; i <= P; i++){
        for(int j = 1; j <= C; j++) f[i][j] += f[i-1][j];
        for(int j = 1; j <= num; j++) g[i][j] += g[i-1][j];
    }
    for(int i = 1; i <= m; i++){
        int op = q[i].op;
        if(op == 1){
            int l = q[i].l, r = q[i].r, k = q[i].k;
            k = lower_bound(ls + 1, ls + 1 + num, k) - ls;
            printf("%d\n", qr_rk(l, r, k));
        }
        else if(op == 2){
            int l = q[i].l, r = q[i].r, k = q[i].k;
            printf("%d\n", ls[qr_val(l, r, k)]);
        }
        else if(op == 3){
            int plc = q[i].l, val = lower_bound(ls + 1, ls + 1 + num, q[i].k) - ls;
            op_dev(plc, val);
        }
        else if(op == 4){
            int l = q[i].l, r = q[i].r, k = lower_bound(ls + 1, ls + 1 + num, q[i].k) - ls;
            printf("%d\n", ls[qr_pre(l, r, k)]);
        }
        else{
            int l = q[i].l, r = q[i].r, k = lower_bound(ls + 1, ls + 1 + num, q[i].k) - ls;
            printf("%d\n", ls[qr_suf(l, r, k)]);
        }
    }
    return 0;
}
