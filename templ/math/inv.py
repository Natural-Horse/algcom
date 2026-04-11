"""
这份模板整理逆元和组合数的常见预处理。
重点包括：
1. 递推求 `1..n` 的逆元。
2. 阶乘和阶乘逆元预处理。
3. O(1) 查询组合数。

递推求逆元要求模数是质数，
并且通常用于需要大量逆元或组合数查询的题。
"""


def inv_table(n, mod):
    # 递推求 1..n 的逆元，要求 mod 为质数。
    inv = [0] * (n + 1)
    if n >= 1:
        inv[1] = 1
    for i in range(2, n + 1):
        inv[i] = (mod - mod // i) * inv[mod % i] % mod
    return inv


def fac_init(n, mod):
    # 预处理 fac 和 ifac，便于快速求组合数。
    fac = [1] * (n + 1)
    ifac = [1] * (n + 1)
    inv = inv_table(n, mod)
    for i in range(1, n + 1):
        fac[i] = fac[i - 1] * i % mod
    for i in range(1, n + 1):
        ifac[i] = ifac[i - 1] * inv[i] % mod
    return fac, ifac, inv


def comb(n, k, fac, ifac, mod):
    # C(n, k) = n! / (k! (n-k)!)
    if k < 0 or k > n:
        return 0
    return fac[n] * ifac[k] % mod * ifac[n - k] % mod
