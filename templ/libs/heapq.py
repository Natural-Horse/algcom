"""
这份模板整理 `heapq` 模块。
重点包括：
1. 小根堆基本操作。
2. 大根堆取反数模拟。
3. 取前 k 大 / 前 k 小的一些便捷接口。

图论最短路、贪心、维护动态最值时都常用。
"""
import heapq


def min_heap_demo(a):
    # 建小根堆并依次弹出。
    hp = a[:]
    heapq.heapify(hp)
    res = []
    while hp:
        res.append(heapq.heappop(hp))
    return res


def max_heap_demo(a):
    # 通过存相反数模拟大根堆。
    hp = [-x for x in a]
    heapq.heapify(hp)
    res = []
    while hp:
        res.append(-heapq.heappop(hp))
    return res


def topk_demo(a, k):
    # nlargest / nsmallest 适合快速取前 k 个元素。
    return heapq.nlargest(k, a), heapq.nsmallest(k, a)
