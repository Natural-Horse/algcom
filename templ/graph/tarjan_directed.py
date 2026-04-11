"""
这份模板是有向图 Tarjan 求强连通分量。
重点包括：
1. `dfn` 表示时间戳，`low` 表示可回溯到的最小时间戳。
2. 栈里维护当前尚未弹出的连通块。
3. 当 `dfn[u] == low[u]` 时，可以弹出一个 SCC。

缩点、判环、2-SAT 等题里都很常见。
"""
def tarjan_scc(n, g):
    dfn = [0] * (n + 1)
    low = [0] * (n + 1)
    ins = [0] * (n + 1)
    stk = []
    scc_id = [0] * (n + 1)
    scc = []
    idx = 0

    def dfs(u):
        nonlocal idx
        idx += 1
        # 新点入栈，暂时认为属于当前搜索树上的活跃点。
        dfn[u] = low[u] = idx
        stk.append(u)
        ins[u] = 1
        for v in g[u]:
            if not dfn[v]:
                dfs(v)
                low[u] = min(low[u], low[v])
            elif ins[v]:
                low[u] = min(low[u], dfn[v])
        if dfn[u] == low[u]:
            # u 是当前 SCC 的根。
            cur = []
            while True:
                x = stk.pop()
                ins[x] = 0
                scc_id[x] = len(scc) + 1
                cur.append(x)
                if x == u:
                    break
            scc.append(cur)

    for i in range(1, n + 1):
        if not dfn[i]:
            dfs(i)
    return scc_id, scc
