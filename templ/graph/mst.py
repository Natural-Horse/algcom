"""
这份模板整理最小生成树的两种经典算法。
重点包括：
1. Kruskal: 适合边集形式，配合并查集。
2. Prim: 适合邻接表形式，配合堆。

无向图不连通时，两种算法都无法得到生成树，
这里统一返回 -1。
"""
import heapq


class Dsu:
    def __init__(self, n):
        self.fa = list(range(n + 1))
        self.sz = [1] * (n + 1)

    def find(self, x):
        while self.fa[x] != x:
            self.fa[x] = self.fa[self.fa[x]]
            x = self.fa[x]
        return x

    def merge(self, x, y):
        fx, fy = self.find(x), self.find(y)
        if fx == fy:
            return False
        if self.sz[fx] < self.sz[fy]:
            fx, fy = fy, fx
        self.fa[fy] = fx
        self.sz[fx] += self.sz[fy]
        return True


def kruskal(n, edges):
    # edges 元素格式为 (u, v, w)。
    dsu = Dsu(n)
    edges.sort(key=lambda x: x[2])
    ans = 0
    cnt = 0
    for u, v, w in edges:
        if not dsu.merge(u, v):
            continue
        ans += w
        cnt += 1
        if cnt == n - 1:
            break
    return ans if cnt == n - 1 else -1


def prim(n, g):
    # 从 1 号点开始扩展最小生成树。
    vis = [0] * (n + 1)
    hp = [(0, 1)]
    ans = 0
    cnt = 0
    while hp:
        w, u = heapq.heappop(hp)
        if vis[u]:
            continue
        vis[u] = 1
        ans += w
        cnt += 1
        for v, ww in g[u]:
            if not vis[v]:
                heapq.heappush(hp, (ww, v))
    return ans if cnt == n else -1
