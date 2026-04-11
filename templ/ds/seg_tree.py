"""
这份模板是线段树区间加、区间求和版本。
重点包括：
1. 建树、区间加懒标记、区间求和。
2. `push_up / push_down` 的标准组织方式。

如果题目是区间最值、区间赋值、区间覆盖等，
就在这个框架上换维护信息和懒标记语义。
"""
class SegTree:
    def __init__(self, a):
        self.n = len(a) - 1
        self.sum = [0] * (self.n << 2)
        self.tag = [0] * (self.n << 2)
        self.build(1, 1, self.n, a)

    def build(self, u, l, r, a):
        # 建树时默认 a 是 1 下标数组。
        if l == r:
            self.sum[u] = a[l]
            return
        mid = (l + r) >> 1
        self.build(u << 1, l, mid, a)
        self.build(u << 1 | 1, mid + 1, r, a)
        self.push_up(u)

    def push_up(self, u):
        # 用两个儿子更新当前节点信息。
        self.sum[u] = self.sum[u << 1] + self.sum[u << 1 | 1]

    def apply(self, u, l, r, v):
        # 把懒标记直接作用到当前区间。
        self.sum[u] += (r - l + 1) * v
        self.tag[u] += v

    def push_down(self, u, l, r):
        # 下传懒标记，保证儿子信息正确。
        if not self.tag[u]:
            return
        mid = (l + r) >> 1
        self.apply(u << 1, l, mid, self.tag[u])
        self.apply(u << 1 | 1, mid + 1, r, self.tag[u])
        self.tag[u] = 0

    def add(self, u, l, r, st, re, v):
        # 区间加。
        if st <= l and r <= re:
            self.apply(u, l, r, v)
            return
        self.push_down(u, l, r)
        mid = (l + r) >> 1
        if st <= mid:
            self.add(u << 1, l, mid, st, re, v)
        if re > mid:
            self.add(u << 1 | 1, mid + 1, r, st, re, v)
        self.push_up(u)

    def qr(self, u, l, r, st, re):
        # 区间求和。
        if st <= l and r <= re:
            return self.sum[u]
        self.push_down(u, l, r)
        mid = (l + r) >> 1
        res = 0
        if st <= mid:
            res += self.qr(u << 1, l, mid, st, re)
        if re > mid:
            res += self.qr(u << 1 | 1, mid + 1, r, st, re)
        return res
