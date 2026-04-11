"""
这份模板是拓扑排序。
重点包括：
1. 基于入度数组。
2. 队列里维护当前所有入度为 0 的点。
3. 若最终点数不足 n，说明图中有环。

适合 DAG 上的依赖关系、DP 转移、构造顺序等问题。
"""
from collections import deque


def topo_sort(n, g):
    # 先统计每个点的入度。
    deg = [0] * (n + 1)
    for u in range(1, n + 1):
        for v in g[u]:
            deg[v] += 1
    q = deque()
    for i in range(1, n + 1):
        if deg[i] == 0:
            q.append(i)
    ords = []
    while q:
        u = q.popleft()
        ords.append(u)
        for v in g[u]:
            deg[v] -= 1
            if deg[v] == 0:
                q.append(v)
    return ords if len(ords) == n else []
