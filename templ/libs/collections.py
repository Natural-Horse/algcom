"""
这份模板整理 `collections` 里最常用的几个容器。
重点包括：
1. `deque` 双端队列。
2. `Counter` 频率统计。
3. `defaultdict` 默认值字典。

这几个基本都是 Python 竞赛的常客。
"""
from collections import Counter, defaultdict, deque


def deque_demo():
    # 头尾都能插入和删除。
    q = deque([2, 3])
    q.appendleft(1)
    q.append(4)
    return q.popleft(), q.pop(), list(q)


def counter_demo(a):
    # Counter 直接统计每个元素出现次数。
    cnt = Counter(a)
    return cnt, cnt.most_common(3)


def defaultdict_demo(a):
    # defaultdict(int) 默认值为 0，适合计数。
    mp = defaultdict(int)
    for x in a:
        mp[x] += 1
    return mp
