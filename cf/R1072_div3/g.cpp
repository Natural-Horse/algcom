#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

const int N = 2e5 + 5;

typedef struct Node {
    int l, r, siz, mn;
    Node() { l = 0, r = 0, siz = 0, mn = inf; }
} TrNd;

class SegTree {
private:
    int n;
    vector<TrNd> tr;

    void pushUp(int u) {
        int na = u << 1, nb = na | 1;
        tr[u].mn = min(tr[na].mn, tr[nb].mn);
    }
    void build(const vector<int>& a, int u, int l, int r){
        tr[u].l = l, tr[u].r = r, tr[u].siz = r - l + 1;
        if (l == r) {
            tr[u].mn = a[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(a, u << 1, l, mid);
        build(a, u << 1 | 1, mid + 1, r);
        tr[u].mn = min(tr[u<<1].mn, tr[u<<1|1].mn);
    }
    void opChange(int u, int plc, int val) {
        int l = tr[u].l, r = tr[u].r;
        if (l > plc || r < plc) return;
        if (l >= plc && r <= plc) {
            tr[u].mn = val;
            return;
        }
        opChange(u << 1, plc, val);
        opChange(u << 1 | 1, plc, val);
        pushUp(u);
    }
    int qrMinVal(int u, int st, int re) {
        int l = tr[u].l, r = tr[u].r;
        if (l > re || r < st) return inf;
        if (l >= st && r <= re) return tr[u].mn;
        int res = min(qrMinVal(u << 1, st, re), qrMinVal(u << 1 | 1, st, re));
        return res;
    }

public:
    SegTree(int _n) : n(_n), tr(_n << 2 | 1) {}
    void build(const vector<int>& a) { build(a, 1, 1, n); }
    void opChange(int plc, int val) { opChange(1, plc, val); }
    int qrMinVal(int st, int re) { return qrMinVal(1, st, re); }
};

void solve() {
    int n, m; cin >> n >> m;
    vector<int> a(n + 1, 0);
    for(int i = 1; i <= n; i++) cin >> a[i];
    SegTree tree(n);
    tree.build(a);
    auto check = [&](int st, int re) -> bool {
        return tree.qrMinVal(st, re) > re - st;
    };
    for(int i = 1, op, x, y; i <= m; i++) {
        cin >> op >> x >> y;
        if (op == 1) {
            tree.opChange(x, y);
        }
        else {
            int l = 0, r = y - x;
            while(l < r) {
                int mid = (l + r) >> 1;
                if (check(x , x + mid)) l = mid + 1;
                else r = mid;
            }
            if (tree.qrMinVal(x, x + l) == l) cout << 1 << endl;
            else cout << 0 << endl;
        }
    }
}

int main(){
    ios::sync_with_stdio(false), cin.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}