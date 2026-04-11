"""
这份模板是线性筛。
重点包括：
1. O(n) 求素数表。
2. 同时求最小质因子 `minp`。
3. 扩展出欧拉函数 `phi` 和莫比乌斯函数 `mu`。

线性筛的优势是每个合数只会被最小质因子筛掉一次，
所以不仅快，而且很方便在筛的过程中顺手带别的信息。
"""


def linear_sieve(n):
    # 返回素数表和每个数的最小质因子。
    pr = []
    minp = [0] * (n + 1)
    for i in range(2, n + 1):
        if not minp[i]:
            minp[i] = i
            pr.append(i)
        for p in pr:
            if i * p > n:
                break
            minp[i * p] = p
            if i % p == 0:
                break
    return pr, minp


def sieve_phi(n):
    # 线性筛求欧拉函数。
    pr = []
    minp = [0] * (n + 1)
    phi = [0] * (n + 1)
    phi[1] = 1
    for i in range(2, n + 1):
        if not minp[i]:
            minp[i] = i
            pr.append(i)
            phi[i] = i - 1
        for p in pr:
            if i * p > n:
                break
            minp[i * p] = p
            if i % p == 0:
                phi[i * p] = phi[i] * p
                break
            phi[i * p] = phi[i] * (p - 1)
    return pr, phi


def sieve_mu(n):
    # 线性筛求莫比乌斯函数。
    pr = []
    minp = [0] * (n + 1)
    mu = [0] * (n + 1)
    mu[1] = 1
    for i in range(2, n + 1):
        if not minp[i]:
            minp[i] = i
            pr.append(i)
            mu[i] = -1
        for p in pr:
            if i * p > n:
                break
            minp[i * p] = p
            if i % p == 0:
                mu[i * p] = 0
                break
            mu[i * p] = -mu[i]
    return pr, mu


def factorize(x, minp):
    # 用最小质因子表做快速分解。
    res = []
    while x > 1:
        p = minp[x]
        c = 0
        while x % p == 0:
            x //= p
            c += 1
        res.append((p, c))
    return res
