"""
这份模板整理快速幂和最基础的模运算写法。
重点包括：
1. 二进制快速幂。
2. 模加、模减、模乘。
3. 质数模数下利用费马小定理求逆元。

竞赛里只要涉及大指数取模，快速幂几乎都是默认工具。
如果模数不是质数，逆元不能直接套费马小定理，要改用 exgcd。
"""


def mod_add(a, b, mod):
    # 模加，顺手统一成非负余数。
    return (a + b) % mod


def mod_sub(a, b, mod):
    # 模减时 Python 本身就会给出非负余数。
    return (a - b) % mod


def mod_mul(a, b, mod):
    # Python 整数不会溢出，直接乘再取模即可。
    return a * b % mod


def qpow(a, b, mod):
    # 标准二进制快速幂。
    res = 1
    a %= mod
    while b:
        if b & 1:
            res = res * a % mod
        a = a * a % mod
        b >>= 1
    return res


def inv_prime(a, mod):
    # mod 为质数，且 a 与 mod 互质。
    return qpow(a, mod - 2, mod)


def div_prime(a, b, mod):
    # 模意义下除法，本质是乘逆元。
    return a * inv_prime(b, mod) % mod
