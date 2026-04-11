"""
这份模板演示双端队列和单调队列。
重点包括：
1. `deque` 的头尾插入、头尾弹出。
2. 单调队列维护滑动窗口最小值。

如果题目涉及窗口最值、维护候选下标，
单调队列通常是非常值得优先考虑的结构。
"""
from collections import deque


def deque_demo():
    # 双端队列两端都能操作。
    q = deque()
    q.append(3)
    q.appendleft(2)
    q.append(5)
    a = q.popleft()
    b = q.pop()
    return a, b, list(q)


def mono_queue_min(a, k):
    # 维护一个下标队列，保证对应值单调递增。
    q = deque()
    ans = []
    for i, x in enumerate(a):
        # 新值更小时，队尾更劣的元素可以直接删掉。
        while q and a[q[-1]] >= x:
            q.pop()
        q.append(i)
        # 窗口左边界外的元素出队。
        while q and q[0] <= i - k:
            q.popleft()
        if i + 1 >= k:
            ans.append(a[q[0]])
    return ans
