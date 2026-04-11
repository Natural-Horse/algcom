"""
这份模板整理中国剩余定理 CRT 和扩展 exCRT。
重点包括：
1. CRT 适用于模数两两互质的情况。
2. exCRT 可以处理模数不互质的情况。
3. 返回值统一写成 `(x, lcm)`，表示 `x` 是最小非负解，模 `lcm` 同余。

做这类题时最容易错的是：
1. 中间乘法和取模顺序。
2. 不互质时是否有解。
3. 最终答案要规范成最小非负数。
"""


def exgcd(a, b):
    if b == 0:
        return a, 1, 0
    g, x1, y1 = exgcd(b, a % b)
    x = y1
    y = x1 - a // b * y1
    return g, x, y


def crt(a, m):
    # 解 x ≡ a[i] (mod m[i])，要求 m 两两互质。
    mod = 1
    for x in m:
        mod *= x
    ans = 0
    for ai, mi in zip(a, m):
        Mi = mod // mi
        _, x, _ = exgcd(Mi, mi)
        ans = (ans + ai * Mi * x) % mod
    return ans, mod


def merge_equation(a1, m1, a2, m2):
    # 合并两个同余方程：
    # x ≡ a1 (mod m1)
    # x ≡ a2 (mod m2)
    g, x, _ = exgcd(m1, m2)
    c = a2 - a1
    if c % g != 0:
        return None
    mod = m1 // g * m2
    t = c // g * x % (m2 // g)
    ans = (a1 + m1 * t) % mod
    return ans, mod


def excrt(a, m):
    # 逐个合并，适用于模数不互质。
    ans, mod = a[0], m[0]
    for i in range(1, len(a)):
        res = merge_equation(ans, mod, a[i], m[i])
        if res is None:
            return None
        ans, mod = res
    return ans, mod
