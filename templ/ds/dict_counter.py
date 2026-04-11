"""
这份模板对应 C++ 里 `map / unordered_map` 和计数桶的常见用途。
重点包括：
1. `defaultdict(int)` 做默认值为 0 的计数。
2. `Counter` 快速统计频次。

绝大多数哈希计数题，Python 用这两个就很顺手。
"""
from collections import Counter, defaultdict


def dict_counter_demo(a):
    # defaultdict 适合手动维护频率。
    mp = defaultdict(int)
    for x in a:
        mp[x] += 1
    # Counter 适合快速统计和取高频元素。
    cnt = Counter(a)
    return mp, cnt.most_common(3)
