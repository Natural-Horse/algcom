"""
这份模板整理二分相关的经典写法。
重点包括：
1. 有序数组上的 `lower_bound` 和 `upper_bound`。
2. 查具体值是否存在。
3. 二分答案时找最小可行值、最大可行值的两个标准框架。

真正做题时最重要的是先想清楚 `check(mid)` 的单调性，
模板本身只是把边界细节固定下来，避免手误。
"""
def lower_bound(a, x):
    # 返回第一个 >= x 的位置。
    l, r = 0, len(a)
    while l < r:
        mid = (l + r) >> 1
        if a[mid] >= x:
            r = mid
        else:
            l = mid + 1
    return l


def upper_bound(a, x):
    # 返回第一个 > x 的位置。
    l, r = 0, len(a)
    while l < r:
        mid = (l + r) >> 1
        if a[mid] > x:
            r = mid
        else:
            l = mid + 1
    return l


def binary_search_value(a, x):
    # 在有序数组里判断 x 是否存在。
    p = lower_bound(a, x)
    return p < len(a) and a[p] == x


def binary_search_ans(l, r, check):
    # 找最小满足 check(mid) 的值。
    while l < r:
        mid = (l + r) >> 1
        if check(mid):
            r = mid
        else:
            l = mid + 1
    return l


def binary_search_ans_right(l, r, check):
    # 找最大满足 check(mid) 的值。
    while l < r:
        mid = (l + r + 1) >> 1
        if check(mid):
            l = mid
        else:
            r = mid - 1
    return l
