"""
这份代码是 `cf/R1072_div3/F.cpp` 的 Python 转写版。
重点包括：
1. 这是一个树上 DP。
2. `f[u][1][r]` 维护在以 `u` 为根的子树内，选择包含 `u` 的方案后，方案数对 3 取模为 `r` 是否可行。
3. 合并子树时，本质是在做模 3 状态转移。

代码基本保持了原 C++ 的状态设计和转移方式，
只是换成了 Python 的列表实现。
"""
import sys

sys.setrecursionlimit(1 << 25)


def solve(it):
    n = next(it)
    g = [[] for _ in range(n + 1)]
    for _ in range(n - 1):
        u = next(it)
        v = next(it)
        g[u].append(v)
        g[v].append(u)

    # f[u][0/1][r] 对应原代码的三维布尔 DP。
    f = [[[0, 0, 0], [0, 0, 0]] for _ in range(n + 1)]

    def dp(u, fa):
        # g0 表示已经合并完前若干个儿子后，模 3 余数是否可达。
        g0 = [1, 0, 0]
        cnt = 0
        for v in g[u]:
            if v == fa:
                continue
            cnt += 1
            dp(v, u)
            gv = [[0, 0, 0] for _ in range(3)]
            if f[v][1][0]:
                gv[0][0], gv[0][1], gv[0][2] = g0[0], g0[1], g0[2]
            if f[v][1][1]:
                # 儿子贡献为 1 时，相当于整体余数循环右移。
                gv[1][0], gv[1][1], gv[1][2] = g0[2], g0[0], g0[1]
            if f[v][1][2]:
                gv[2][0], gv[2][1], gv[2][2] = g0[1], g0[2], g0[0]
            g0[0] = gv[0][0] | gv[1][0] | gv[2][0]
            g0[1] = gv[0][1] | gv[1][1] | gv[2][1]
            g0[2] = gv[0][2] | gv[1][2] | gv[2][2]

        f[u][0][0] = 1
        if not cnt:
            # 叶子节点只能单独形成 1。
            f[u][1][1] = 1
        else:
            f[u][1][0] = g0[0]
            f[u][1][1] = g0[1] | 1
            f[u][1][2] = g0[2]

    dp(1, 0)
    return "YES" if f[1][1][0] else "NO"


def main():
    # 多测快读。
    data = list(map(int, sys.stdin.buffer.read().split()))
    it = iter(data)
    t = next(it)
    ans = []
    for _ in range(t):
        ans.append(solve(it))
    sys.stdout.write("\n".join(ans))


if __name__ == "__main__":
    main()
