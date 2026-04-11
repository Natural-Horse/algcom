"""
这份模板整理双指针的两种常见方向。
重点包括：
1. 同向双指针维护合法区间。
2. 两个有序数组的归并过程。

双指针题最重要的是想清楚：
左端什么时候移动，右端什么时候扩展，区间性质是否可维护。
"""
def longest_unique_subarray(a):
    # 维护一个没有重复数字的窗口。
    cnt = {}
    l = 0
    ans = 0
    for r, x in enumerate(a):
        cnt[x] = cnt.get(x, 0) + 1
        while cnt[x] > 1:
            y = a[l]
            cnt[y] -= 1
            l += 1
        ans = max(ans, r - l + 1)
    return ans


def merge_sorted(a, b):
    # 归并是很多题的底层过程，比如 merge sort、离线扫描等。
    i = j = 0
    c = []
    while i < len(a) and j < len(b):
        if a[i] <= b[j]:
            c.append(a[i])
            i += 1
        else:
            c.append(b[j])
            j += 1
    c.extend(a[i:])
    c.extend(b[j:])
    return c
