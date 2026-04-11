"""
这份模板是并查集。
重点包括：
1. 路径压缩。
2. 按大小合并。
3. 判断两个点是否在同一连通块。

图连通性、Kruskal、离线合并类题目都很常用。
"""
class Dsu:
    def __init__(self, n):
        self.fa = list(range(n + 1))
        self.sz = [1] * (n + 1)

    def find(self, x):
        # 迭代版路径压缩。
        while self.fa[x] != x:
            self.fa[x] = self.fa[self.fa[x]]
            x = self.fa[x]
        return x

    def merge(self, x, y):
        # 按大小合并，减少树高。
        fx, fy = self.find(x), self.find(y)
        if fx == fy:
            return False
        if self.sz[fx] < self.sz[fy]:
            fx, fy = fy, fx
        self.fa[fy] = fx
        self.sz[fx] += self.sz[fy]
        return True
