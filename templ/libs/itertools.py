"""
这份模板整理 `itertools` 里竞赛常见的迭代器工具。
重点包括：
1. 排列、组合、可重复组合。
2. 笛卡尔积。
3. 前缀累积和分组。

这类工具写法很省事，但有些会一次性生成大量状态，
遇到数据范围大时要先确认总复杂度。
"""
import itertools


def perm_demo(a, r):
    # 从 a 中选 r 个数做排列。
    return list(itertools.permutations(a, r))


def comb_demo(a, r):
    # combinations 不允许重复选，combinations_with_replacement 允许重复选。
    c1 = list(itertools.combinations(a, r))
    c2 = list(itertools.combinations_with_replacement(a, r))
    return c1, c2


def product_demo(a, b):
    # 笛卡尔积。
    return list(itertools.product(a, b))


def accumulate_demo(a):
    # 累积和，默认是前缀加法。
    return list(itertools.accumulate(a))


def groupby_demo(a):
    # groupby 只会把相邻相同元素分到同一组，通常先排序再用。
    res = []
    for k, grp in itertools.groupby(a):
        res.append((k, list(grp)))
    return res
