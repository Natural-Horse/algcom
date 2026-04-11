"""
这份模板是 Dijkstra 堆优化最短路。
重点包括：
1. 适用于边权非负图。
2. 用 `heapq` 维护当前最短路点。
3. 通过 `d != dis[u]` 跳过过期状态。

如果图里存在负边，就不能直接套这份模板。
"""
import heapq


def dijkstra(n, g, st):
    # g[u] 里存 (v, w)。
    inf = 10 ** 18
    dis = [inf] * (n + 1)
    dis[st] = 0
    hp = [(0, st)]
    while hp:
        d, u = heapq.heappop(hp)
        # 堆里同一点可能被压入多次，过期状态直接跳过。
        if d != dis[u]:
            continue
        for v, w in g[u]:
            nd = d + w
            if nd < dis[v]:
                dis[v] = nd
                heapq.heappush(hp, (nd, v))
    return dis
