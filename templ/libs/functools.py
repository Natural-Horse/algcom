"""
这份模板整理 `functools` 在竞赛和脚本里最常见的用法。
重点包括：
1. `lru_cache` 做记忆化搜索。
2. `cmp_to_key` 把比较函数转成排序 key。
3. `reduce` 做连续聚合。

其中最常用的一般是 `lru_cache`，
特别适合状态不大、递归转移自然的记忆化 DP。
"""
from functools import cmp_to_key, lru_cache, reduce


def cache_demo(n):
    @lru_cache(None)
    def dfs(x):
        # 经典记忆化斐波那契写法。
        if x <= 1:
            return 1
        return dfs(x - 1) + dfs(x - 2)

    return dfs(n)


def cmp_demo(a):
    # 让奇数排前面，奇偶相同时按从小到大排。
    def cmp(x, y):
        if (x & 1) != (y & 1):
            return -1 if (x & 1) else 1
        return (x > y) - (x < y)

    return sorted(a, key=cmp_to_key(cmp))


def reduce_demo(a):
    # reduce 会把序列不断按给定函数折叠起来。
    return reduce(lambda x, y: x + y, a, 0)
