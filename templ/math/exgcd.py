"""
这份模板整理扩展欧几里得相关写法。
重点包括：
1. `exgcd(a, b)` 求 `ax + by = gcd(a, b)` 的一组解。
2. 求模逆元。
3. 求一次不定方程 `ax + by = c` 是否有解。

这份模板在模数不一定是质数时特别重要，
因为这时逆元通常要靠 exgcd 来求。
"""


def exgcd(a, b):
    # 返回 gcd(a, b) 以及一组系数 x, y。
    if b == 0:
        return a, 1, 0
    g, x1, y1 = exgcd(b, a % b)
    x = y1
    y = x1 - a // b * y1
    return g, x, y


def inv_any(a, mod):
    # 只有 gcd(a, mod) == 1 时逆元才存在。
    g, x, _ = exgcd(a, mod)
    if g != 1:
        return None
    return x % mod


def solve_linear(a, b, c):
    # 解 ax + by = c，返回一组整数解，不存在则返回 None。
    g, x, y = exgcd(a, b)
    if c % g != 0:
        return None
    k = c // g
    return g, x * k, y * k
