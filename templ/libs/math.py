"""
这份模板整理 `math` 模块里竞赛最常用的内容。
重点包括：
1. 最大公约数、最小公倍数、平方根。
2. 向上取整、向下取整、阶乘、排列组合。
3. 常见取模运算，包括快速幂、逆元、模加减乘。
4. 三角函数和常量在需要几何计算时的基础用法。

做算法竞赛时，`math` 最常见的还是数论和精度相关工具。
如果题目是纯整数运算，优先用整数公式，少碰浮点误差。
"""
import math


def gcd_lcm_demo(a, b):
    # gcd 是最大公约数，lcm 是最小公倍数。
    g = math.gcd(a, b)
    l = math.lcm(a, b)
    return g, l


def sqrt_demo(x):
    # isqrt 返回整数平方根，适合判完全平方数。
    rt = math.isqrt(x)
    return rt, rt * rt == x


def ceil_floor_demo(x):
    # ceil / floor 处理实数上下取整。
    return math.ceil(x), math.floor(x)


def comb_demo(n, k):
    # factorial / perm / comb 都是 Python 内置高精度整数版本。
    return math.factorial(n), math.perm(n, k), math.comb(n, k)


def mod_base_demo(a, b, mod):
    # Python 的 % 会返回非负余数，适合直接做模加减乘。
    add = (a + b) % mod
    sub = (a - b) % mod
    mul = (a * b) % mod
    return add, sub, mul


def mod_pow_demo(a, b, mod):
    # 三参数 pow 是竞赛里最常用的快速幂写法。
    return pow(a, b, mod)


def mod_inv_demo(a, mod):
    # mod 为质数且 a 与 mod 互质时，可用费马小定理求逆元。
    return pow(a, mod - 2, mod)


def mod_div_demo(a, b, mod):
    # 模意义下的除法本质是乘上逆元。
    return a * mod_inv_demo(b, mod) % mod


def trig_demo(x):
    # 三角函数默认用弧度制。
    return math.sin(x), math.cos(x), math.pi
