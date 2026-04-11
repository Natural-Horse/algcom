"""
这份模板整理树上 DP 的两个经典方向。
重点包括：
1. 自底向上的子树大小和子树贡献统计。
2. 换根 DP 的基础转移。

换根 DP 的核心不是背模板，
而是看清一个儿子从父亲换成根后，贡献会怎么变化。
"""
def tree_dp_subsize(n, g, rt=1):
    # 先拿到一份从根出发的遍历顺序。
    fa = [0] * (n + 1)
    ords = [rt]
    for u in ords:
        for v in g[u]:
            if v == fa[u]:
                continue
            fa[v] = u
            ords.append(v)
    siz = [1] * (n + 1)
    dp = [0] * (n + 1)
    for u in reversed(ords):
        for v in g[u]:
            if v == fa[u]:
                continue
            # 这里示例统计的是子树距离和。
            siz[u] += siz[v]
            dp[u] += dp[v] + siz[v]
    return siz, dp


def reroot_dp(n, g, rt=1):
    # ans[u] 表示以 u 为根时的答案。
    siz, dp = tree_dp_subsize(n, g, rt)
    fa = [0] * (n + 1)
    ords = [rt]
    for u in ords:
        for v in g[u]:
            if v == fa[u]:
                continue
            fa[v] = u
            ords.append(v)
    ans = [0] * (n + 1)
    ans[rt] = dp[rt]
    for u in ords:
        for v in g[u]:
            if v == fa[u]:
                continue
            # 根从 u 移到 v，v 子树内点更近，外部点更远。
            ans[v] = ans[u] + n - 2 * siz[v]
    return ans
