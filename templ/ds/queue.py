"""
这份模板演示 Python 里普通队列的常用替代品。
重点包括：
1. `collections.deque` 作为 queue 使用。
2. `append` 入队，`popleft` 出队。
3. 判空和取长度的基础方式。

Python 没有和 C++ `queue` 完全同名的标准容器，
竞赛里绝大多数时候直接用 `deque` 就够了。
"""
from collections import deque


def queue_demo():
    # 普通队列只在尾部插入、头部弹出。
    q = deque()
    q.append(3)
    q.append(5)
    x = q.popleft()
    return x, len(q), not q
