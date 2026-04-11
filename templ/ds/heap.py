"""
这份模板对应 C++ 里的 `priority_queue`。
重点包括：
1. Python 的 `heapq` 默认是小根堆。
2. 大根堆通常通过存相反数来模拟。

做最短路、贪心、动态维护最值时经常会用到堆。
"""
import heapq


def min_heap_demo(a):
    # 小根堆直接压入原值。
    hp = []
    for x in a:
        heapq.heappush(hp, x)
    ans = []
    while hp:
        ans.append(heapq.heappop(hp))
    return ans


def max_heap_demo(a):
    # 大根堆把值取反后放进小根堆。
    hp = []
    for x in a:
        heapq.heappush(hp, -x)
    ans = []
    while hp:
        ans.append(-heapq.heappop(hp))
    return ans
