"""
这份模板是树状数组。
重点包括：
1. 单点修改、前缀和查询、区间和查询。
2. 利用二进制倍增思想求第 k 小位置。

树状数组适合处理“前缀可加可减”的问题，
代码短、常数小，是竞赛里非常高频的结构。
"""
class Fenwick:
    def __init__(self, n):
        self.n = n
        self.tr = [0] * (n + 1)

    def add(self, x, v):
        # 单点加 v。
        while x <= self.n:
            self.tr[x] += v
            x += x & -x

    def sum(self, x):
        # 前缀和 [1..x]。
        res = 0
        while x > 0:
            res += self.tr[x]
            x -= x & -x
        return res

    def qr(self, l, r):
        # 区间和 [l..r]。
        return self.sum(r) - self.sum(l - 1)

    def kth(self, k):
        # 求前缀和第一次 >= k 的位置，常用于第 k 小。
        x = 0
        bit = 1 << (self.n.bit_length() - 1)
        while bit:
            nx = x + bit
            if nx <= self.n and self.tr[nx] < k:
                k -= self.tr[nx]
                x = nx
            bit >>= 1
        return x + 1
