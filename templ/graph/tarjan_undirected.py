"""
这份模板整理无向图 Tarjan 的几种常见结果。
重点包括：
1. 割点和桥。
2. 边双连通分量。
3. 点双连通分量。

做这类题时一定要想清楚图是“点双”还是“边双”，
两者的定义、缩点方式和结论都不一样。
"""
def tarjan_cut_bridge(n, g):
    dfn = [0] * (n + 1)
    low = [0] * (n + 1)
    cut = [0] * (n + 1)
    bridge = []
    idx = 0

    def dfs(u, in_e):
        nonlocal idx
        idx += 1
        dfn[u] = low[u] = idx
        child = 0
        for v, eid in g[u]:
            if not dfn[v]:
                child += 1
                dfs(v, eid)
                low[u] = min(low[u], low[v])
                # low[v] > dfn[u] 说明 (u, v) 是桥。
                if low[v] > dfn[u]:
                    bridge.append((u, v))
                # 非根结点满足 low[v] >= dfn[u] 时是割点。
                if in_e != -1 and low[v] >= dfn[u]:
                    cut[u] = 1
            elif eid != in_e:
                low[u] = min(low[u], dfn[v])
        if in_e == -1 and child >= 2:
            cut[u] = 1

    for i in range(1, n + 1):
        if not dfn[i]:
            dfs(i, -1)
    return cut, bridge


def edge_bcc(n, g):
    # 边双连通分量可以理解为“删掉所有桥后剩下的连通块”。
    cut, bridge = tarjan_cut_bridge(n, g)
    st = set()
    for u, v in bridge:
        if u > v:
            u, v = v, u
        st.add((u, v))

    bel = [0] * (n + 1)
    edcc = []

    def dfs(u, cid):
        bel[u] = cid
        edcc[-1].append(u)
        for v, _ in g[u]:
            x, y = u, v
            if x > y:
                x, y = y, x
            if bel[v] or (x, y) in st:
                continue
            dfs(v, cid)

    for i in range(1, n + 1):
        if bel[i]:
            continue
        edcc.append([])
        dfs(i, len(edcc))
    return bel, edcc, cut, bridge


def vertex_bcc(n, g):
    # 点双连通分量通常借助边栈来维护当前搜索过程。
    dfn = [0] * (n + 1)
    low = [0] * (n + 1)
    cut = [0] * (n + 1)
    stk = []
    vdcc = []
    idx = 0

    def dfs(u, fa_e):
        nonlocal idx
        idx += 1
        dfn[u] = low[u] = idx
        child = 0
        for v, eid in g[u]:
            if not dfn[v]:
                stk.append((u, v))
                child += 1
                dfs(v, eid)
                low[u] = min(low[u], low[v])
                if low[v] >= dfn[u]:
                    # 以 (u, v) 为界，弹出一个点双。
                    if fa_e != -1 or child > 1:
                        cut[u] = 1
                    cur = []
                    while True:
                        x, y = stk.pop()
                        cur.append(x)
                        cur.append(y)
                        if x == u and y == v:
                            break
                    vdcc.append(list(set(cur)))
            elif eid != fa_e and dfn[v] < dfn[u]:
                stk.append((u, v))
                low[u] = min(low[u], dfn[v])

    for i in range(1, n + 1):
        if dfn[i]:
            continue
        if not g[i]:
            vdcc.append([i])
            continue
        dfs(i, -1)
    return cut, vdcc
