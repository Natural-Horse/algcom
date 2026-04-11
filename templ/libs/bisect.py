"""
这份模板整理 `bisect` 模块。
重点包括：
1. `bisect_left` 和 `bisect_right` 的边界含义。
2. `insort` 插入到有序数组。

它经常用来替代 C++ 的 `lower_bound / upper_bound`，
但要注意 Python 列表插入是 O(n)。
"""
from bisect import bisect_left, bisect_right, insort


def bound_demo(a, x):
    # a 必须已经有序。
    p1 = bisect_left(a, x)
    p2 = bisect_right(a, x)
    return p1, p2


def insert_demo(a, x):
    # insort 会保持数组有序。
    b = a[:]
    insort(b, x)
    return b
