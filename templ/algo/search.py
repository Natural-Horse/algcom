"""
这份模板整理搜索类题型的基础写法。
重点包括：
1. 图上的迭代版 DFS。
2. 图上的 BFS 最短步数模板。
3. 网格 BFS 的四联通扩展方式。

竞赛里搜索题的核心通常不是“会不会搜”，
而是状态设计、判重方式、以及如何控制复杂度。
"""
from collections import deque


def dfs_iter(st, g):
    # 迭代版 DFS，避免 Python 递归爆栈。
    n = len(g) - 1
    vis = [0] * (n + 1)
    stk = [st]
    vis[st] = 1
    ords = []
    while stk:
        u = stk.pop()
        ords.append(u)
        for v in g[u]:
            if vis[v]:
                continue
            vis[v] = 1
            stk.append(v)
    return ords


def bfs(st, g):
    # 标准 BFS，vis 也可以理解为最短路层数。
    n = len(g) - 1
    vis = [-1] * (n + 1)
    q = deque([st])
    vis[st] = 0
    while q:
        u = q.popleft()
        for v in g[u]:
            if vis[v] != -1:
                continue
            vis[v] = vis[u] + 1
            q.append(v)
    return vis


def grid_bfs(sx, sy, mp):
    # 网格最短路，默认 '#' 不能走。
    n, m = len(mp), len(mp[0])
    dis = [[-1] * m for _ in range(n)]
    q = deque([(sx, sy)])
    dis[sx][sy] = 0
    dx = (-1, 1, 0, 0)
    dy = (0, 0, -1, 1)
    while q:
        x, y = q.popleft()
        for k in range(4):
            nx, ny = x + dx[k], y + dy[k]
            # 先判边界，再判障碍和是否访问过。
            if nx < 0 or nx >= n or ny < 0 or ny >= m:
                continue
            if mp[nx][ny] == "#" or dis[nx][ny] != -1:
                continue
            dis[nx][ny] = dis[x][y] + 1
            q.append((nx, ny))
    return dis
