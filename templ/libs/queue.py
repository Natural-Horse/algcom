"""
这份模板整理 `queue` 模块的基础用法。
重点包括：
1. `Queue` 普通队列。
2. `PriorityQueue` 优先队列。
3. `LifoQueue` 栈。

算法竞赛里通常更常用 `collections.deque` 和 `heapq`，
因为它们更轻、更快；`queue` 更偏线程安全场景。
"""
from queue import LifoQueue, PriorityQueue, Queue


def queue_demo():
    # FIFO 普通队列。
    q = Queue()
    q.put(3)
    q.put(5)
    return q.get(), q.empty()


def priority_queue_demo():
    # PriorityQueue 默认也是最小值优先弹出。
    q = PriorityQueue()
    q.put((2, "b"))
    q.put((1, "a"))
    return q.get(), q.get()


def lifo_demo():
    # LifoQueue 行为类似栈。
    q = LifoQueue()
    q.put(1)
    q.put(2)
    return q.get(), q.get()
