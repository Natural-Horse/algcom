"""
这份模板说明 Python 里如何近似替代 C++ `set` 的有序操作。
重点包括：
1. 普通去重可直接用 `set`。
2. 如果需要有序前驱后继，可以配合 `sorted + bisect`。
3. `insort` 可以插入到有序数组中，但复杂度是线性的。

严格高强度有序集合场景下，Python 常要换思路，
或使用树状数组、线段树、堆、离线处理来代替。
"""
from bisect import bisect_left, bisect_right, insort


def ordered_set_demo(a, x):
    # 先去重排序，再做二分查找。
    s = sorted(set(a))
    p1 = bisect_left(s, x)
    p2 = bisect_right(s, x)
    insort(s, x)
    return p1, p2, s
