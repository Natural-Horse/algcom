"""
这份模板整理树的最基础操作。
重点包括：
1. 由边集建邻接表。
2. 求父节点、深度、遍历顺序。

很多树题的第一步都是先把这些基础数组准备出来，
后面的树 DP、LCA、树剖都会依赖它们。
"""
def build_tree(n, edges):
    # 无向树建图。
    g = [[] for _ in range(n + 1)]
    for u, v in edges:
        g[u].append(v)
        g[v].append(u)
    return g


def tree_parent_dep(n, g, rt=1):
    # 用一遍类 BFS/DFS 的顺序求 fa 和 dep。
    fa = [0] * (n + 1)
    dep = [0] * (n + 1)
    ords = [rt]
    for u in ords:
        for v in g[u]:
            if v == fa[u]:
                continue
            fa[v] = u
            dep[v] = dep[u] + 1
            ords.append(v)
    return fa, dep, ords
