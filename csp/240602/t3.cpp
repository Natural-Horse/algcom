#pragma GCC optimize(2, 3, "Ofast", "inline")
#pragma GCC optimize(2, 3, "Ofast", "inline") // 编译器优化选项，非算法逻辑相关，仅提升速度
#include <bits/stdc++.h>
using namespace std; // 使用 std 命名空间以简化代码
// 用 '\n' 替代 endl，避免 endl 带来的 flush，提升 IO 性能
#define endl '\n'
//#define int long long
//#define double long double
using i64 = long long; // 常用类型别名
using ui64 = unsigned long long;
//using i128 = __int128;
#define inf (int)0x3f3f3f3f3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
#define yn(x) cout << (x ? "yes" : "no") << endl
#define Yn(x) cout << (x ? "Yes" : "No") << endl
#define YN(x) cout << (x ? "YES" : "NO") << endl
#define mem(x, i) memset(x, i, sizeof(x))
#define cinarr(a, n) for (int _ = 1; _ <= n; _++) cin >> a[_]
#define cinstl(a) for (auto& _ : a) cin >> _
#define coutarr(a, n) for (int _ = 1; _ <= n; _++) cout << a[_] << " \n"[_ == n]
#define coutstl(a) for (const auto& _ : a) cout << _ << ' '; cout << endl
#define all(x) (x).begin(), (x).end()
#define ls (s << 1)
#define rs (s << 1 | 1)
#define ft first
#define se second
#define pii pair<int, int>
#ifdef DEBUG
    #include "debug.h"
#else
    #define dbg(...) void(0) // 调试宏：未定义 DEBUG 时不输出
#endif

const int N = 2e5 + 5;
const int N = 2e5 + 5; // 辅助数组大小（模板余量）
//const int M = 1e5 + 5;
const int mod = 998244353;
//const int mod = 1e9 + 7;
//template <typename T> T ksm(T a, i64 b) { T ans = 1; for (; b; a = 1ll * a * a, b >>= 1) if (b & 1) ans = 1ll * ans * a; return ans; }
//template <typename T> T ksm(T a, i64 b, T m = mod) { T ans = 1; for (; b; a = 1ll * a * a % m, b >>= 1) if (b & 1) ans = 1ll * ans * a % m; return ans; }

int a[N];
int n, m, t, k, q; // 全局变量（n: 单词数, m: 期望词表长度）

vector<vector<int>> v;
vector<int> cnt;
vector<string> ans;
// v: 每个单词的当前 token id 序列
// cnt: 每个单词的权重/频率
// ans: 当前词表，索引即为 token id，初始为单字母，后续追加合并结果

struct node {
    int id1, id2, cnt, vis;
    bool operator < (const node& t) const {
        if (cnt != t.cnt) return cnt < t.cnt;
        if (ans[id1].length() + ans[id2].length() != ans[t.id1].length() + ans[t.id2].length())
            return ans[id1].length() + ans[id2].length() > ans[t.id1].length() + ans[t.id2].length();
        if (ans[id1].length() != ans[t.id1].length())
            return ans[id1].length() > ans[t.id1].length();
        return ans[id1] + ans[id2] > ans[t.id1] + ans[t.id2];
    }
};
// priority_queue 中存放的节点，表示候选合并对 (id1, id2)
// cnt: 对应 pair 的累计权重（越大优先合并）
priority_queue<node> pq;

struct Info {
    multiset<int> posi;
    int cnt, vis;
};
// 每个相邻 pair 的信息：包含出现该 pair 的单词集合 posi、累积权重 cnt、版本号 vis
map<pair<int, int>, Info> mpInfo;
Info& getInfo(int id1, int id2) {
    if (mpInfo.count({id1, id2})) return mpInfo[{id1, id2}];
    else return mpInfo[{id1, id2}] = {multiset<int>(), 0, 0};
}
// 获取引用，若不存在则创建默认 Info

void work() {
    cin >> n >> m;
    vector<string> s(n);
    vector<int> vis(26, 0);
    v.resize(n), cnt.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i] >> cnt[i];
        for (auto& ch : s[i]) vis[ch - 'a'] = 1;
    }
    // 读取输入：n 个单词，每行一个单词和其频率；m 为期望的词表大小
    for (int i = 0; i < 26; i++) {
        if (vis[i])
            ans.emplace_back(string(1, 'a' + i));
        if (i) vis[i] += vis[i - 1];
    }  

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < s[i].length(); j++) {
            v[i].emplace_back(vis[s[i][j] - 'a'] - 1);
            if (j) {
                Info& info = getInfo(v[i][j - 1], v[i][j]);
                info.posi.emplace(i), info.cnt += cnt[i], ++info.vis;
                pq.emplace((node){v[i][j - 1], v[i][j], info.cnt, info.vis});
            }
        }
    }
        // 把每个单词按初始 token id（单字母）拆分，并统计所有相邻 pair 的出现频率

    while (ans.size() < m) {
        while (pq.size() && pq.top().vis != mpInfo[{pq.top().id1, pq.top().id2}].vis) pq.pop();
        if (pq.empty()) break;
        if (pq.top().cnt == 0) break;

        int id1 = pq.top().id1, id2 = pq.top().id2;
        dbg(id1, id2);
        Info& info = getInfo(id1, id2);
        pq.pop();
        ans.emplace_back(ans[id1] + ans[id2]);

        for (auto i : info.posi) {
            int p = -1;
            for (int j = 0; j < v[i].size() - 1; j++)
                if (v[i][j] == id1 && v[i][j + 1] == id2) {
                    p = j;
                    break;
                }
            if (p == -1) continue;

            auto remove = [&] (int id1, int id2, int idx) {
                Info& tem = getInfo(id1, id2);
                if (&tem.posi == &info.posi) return;
                tem.posi.erase(tem.posi.find(idx));
                tem.cnt -= cnt[idx], ++tem.vis;
                pq.emplace((node){id1, id2, tem.cnt, tem.vis});
            };
            auto add = [&] (int id1, int id2, int idx) {
                Info& tem = getInfo(id1, id2);
                if (&tem.posi == &info.posi) return;
                tem.posi.emplace(idx);
                tem.cnt += cnt[idx], ++tem.vis;
                pq.emplace((node){id1, id2, tem.cnt, tem.vis});
            };

            if (p) remove(v[i][p - 1], v[i][p], i);
            if (p + 2 < v[i].size()) remove(v[i][p + 1], v[i][p + 2], i);

            v[i].erase(v[i].begin() + p + 1);
            v[i][p] = ans.size() - 1;

            if (p) add(v[i][p - 1], v[i][p], i);
            if (p + 1 < v[i].size()) add(v[i][p], v[i][p + 1], i);
        }

        info.posi.clear();
        info.cnt = 0, ++info.vis;
        pq.emplace((node){id1, id2, info.cnt, info.vis});
    }
        // 主循环：不断合并频率最高的 pair，直到词表达到 m 或无有效 pair

    for (auto& str : ans) cout << str << endl;
}
        // 输出最终的词表

signed main() {
#ifdef LOCAL
    freopen("C:\\Users\\admin\\CLionProjects\\Practice\\data.in", "r", stdin);
    freopen("C:\\Users\\admin\\CLionProjects\\Practice\\data.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int Case = 1;
    //cin >> Case;
    while (Case--) work();
    return 0;
}
