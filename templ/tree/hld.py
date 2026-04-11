"""
这份模板是树链剖分的基础部分。
重点包括：
1. `dfs1` 求父亲、深度、子树大小、重儿子。
2. `dfs2` 求 dfs 序和每条重链的链头。
3. 基于树剖求 LCA。

树剖通常会和线段树一起配合，
把树上路径问题转成若干段区间问题。
"""
class Hld:
    def __init__(self, n, g, rt=1):
        self.n = n
        self.g = g
        self.fa = [0] * (n + 1)
        self.dep = [0] * (n + 1)
        self.siz = [0] * (n + 1)
        self.son = [0] * (n + 1)
        self.top = [0] * (n + 1)
        self.dfn = [0] * (n + 1)
        self.rk = [0] * (n + 1)
        self.tot = 0
        self.dfs1(rt, 0)
        self.dfs2(rt, rt)

    def dfs1(self, u, fa):
        # 第一遍 DFS 处理重儿子信息。
        self.fa[u] = fa
        self.dep[u] = self.dep[fa] + 1
        self.siz[u] = 1
        mx = 0
        for v in self.g[u]:
            if v == fa:
                continue
            self.dfs1(v, u)
            self.siz[u] += self.siz[v]
            if self.siz[v] > mx:
                mx = self.siz[v]
                self.son[u] = v

    def dfs2(self, u, topf):
        # 第二遍 DFS 给每个点分配 dfs 序和链头。
        self.tot += 1
        self.dfn[u] = self.tot
        self.rk[self.tot] = u
        self.top[u] = topf
        if self.son[u]:
            self.dfs2(self.son[u], topf)
            for v in self.g[u]:
                if v == self.fa[u] or v == self.son[u]:
                    continue
                self.dfs2(v, v)

    def lca(self, x, y):
        # 不在同一条链上时，深的链头先向上跳。
        while self.top[x] != self.top[y]:
            if self.dep[self.top[x]] < self.dep[self.top[y]]:
                x, y = y, x
            x = self.fa[self.top[x]]
        return x if self.dep[x] < self.dep[y] else y
