"""
这份代码是 `cf/R1072_div3/E.cpp` 的 Python 转写版。
重点包括：
1. 原题 C++ 用 `multiset` 维护已切分位置，这里改成树状数组维护有序点集。
2. `kth` 用来找某个排名对应的位置，从而得到当前插入点的前驱和后继。
3. 每插入一个分界点，就从答案里减去它新切开的那部分贡献。

这份转写保持了原代码的思路，只是把 C++ 的有序容器换成了更适合 Python 的写法。
"""
import sys


class Fenwick:
    def __init__(self, n):
        self.n = n
        self.tr = [0] * (n + 1)

    def add(self, x, v):
        # 在位置 x 上加 v，表示这个位置已被加入有序集合。
        while x <= self.n:
            self.tr[x] += v
            x += x & -x

    def sum(self, x):
        # 返回 [1..x] 内已经加入了多少个点。
        res = 0
        while x > 0:
            res += self.tr[x]
            x -= x & -x
        return res

    def kth(self, k):
        # 找排名为 k 的位置，配合 sum 可求前驱后继。
        x = 0
        bit = 1 << (self.n.bit_length() - 1)
        while bit:
            nx = x + bit
            if nx <= self.n and self.tr[nx] < k:
                x = nx
                k -= self.tr[nx]
            bit >>= 1
        return x + 1


def solve(it):
    n = next(it)
    a = [0] * (n + 1)
    dif = [[] for _ in range(n + 1)]
    ans = 0
    for i in range(1, n + 1):
        a[i] = next(it)
        if i > 1:
            # 相邻差值决定这一刀会在哪个阶段被加入。
            dif[abs(a[i] - a[i - 1]) + 1].append(i - 1)
        if i < n:
            ans += i

    out = [str(ans)]
    fw = Fenwick(n + 1)
    # 初始边界点为 0 和 n。
    fw.add(1, 1)
    fw.add(n + 1, 1)
    for i in range(2, n):
        for plc in dif[i]:
            pos = plc + 1
            rk = fw.sum(pos)
            las = fw.kth(rk) - 1
            nxt = fw.kth(rk + 1) - 1
            # 插入 plc 后，原先 [las, nxt] 这一整段被拆成两段。
            ans -= (plc - las) * (nxt - plc)
            fw.add(pos, 1)
        out.append(str(ans))
    return " ".join(out)


def main():
    # 整份快读，适合多测。
    data = list(map(int, sys.stdin.buffer.read().split()))
    it = iter(data)
    t = next(it)
    ans = []
    for _ in range(t):
        ans.append(solve(it))
    sys.stdout.write("\n".join(ans))


if __name__ == "__main__":
    main()
