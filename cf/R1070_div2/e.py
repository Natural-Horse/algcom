import sys

# 增加递归深度限制，防止 DFS 爆栈
sys.setrecursionlimit(300000)

def solve():
    # 读取所有输入
    input_data = sys.stdin.read().split()
    if not input_data:
        return

    iterator = iter(input_data)
    
    try:
        num_test_cases = int(next(iterator))
    except StopIteration:
        return

    for _ in range(num_test_cases):
        n = int(next(iterator))
        
        # 读取 a, c, p
        # 注意：题目中 p 是 1-based index，这里我们转成 0-based 方便处理
        # 但为了保持和你 C++ 逻辑一致（C++ 是 1-based），我们在 Python 里也尽量模拟 1-based 数组
        # 或者在读取时做转换。这里为了对齐你的 C++ 代码，使用 1-based 数组（前面补一个占位符）
        
        a = [0] + [int(next(iterator)) for _ in range(n)]
        c = [0] + [int(next(iterator)) for _ in range(n)]
        p = [0] + [int(next(iterator)) for _ in range(n)]

        # 全局变量初始化
        ls = [0] * (n + 1)
        rs = [0] * (n + 1)
        st = [0] * (n + 1)
        top = 0
        rt = 0
        
        # 1. 构建笛卡尔树
        for i in range(1, n + 1):
            las = 0
            while top >= 1 and a[i] >= a[st[top]]:
                las = st[top]
                top -= 1
            
            if top:
                rs[st[top]] = i
            else:
                rt = i
            
            ls[i] = las
            st[top + 1] = i
            top += 1

        # 2. EVC (Equal Value Component) 逻辑
        top_rep = [0] * (n + 1)
        
        # 使用栈模拟 DFS 计算 top_rep，防止爆栈（虽然设置了 limit，但迭代更稳）
        # 这里为了保持码风，还是写成递归形式，Python 递归深度已开大
        def dfs_top(u, p_node):
            if not u:
                return
            if p_node and a[u] == a[p_node]:
                top_rep[u] = top_rep[p_node]
            else:
                top_rep[u] = u
            
            dfs_top(ls[u], u)
            dfs_top(rs[u], u)

        dfs_top(rt, 0)

        # 更新 c 值为 Group Min
        # 这一步可以优化：先收集每个 group 的 min，再赋值
        # 为了 O(N)，我们用一个字典或数组
        group_min = {} # key: top_rep_id, value: min_c
        
        # 第一遍：收集最小值
        for i in range(1, n + 1):
            root_id = top_rep[i]
            if root_id not in group_min:
                group_min[root_id] = c[i]
            else:
                group_min[root_id] = min(group_min[root_id], c[i])
        
        # 第二遍：赋值回 c
        for i in range(1, n + 1):
            c[i] = group_min[top_rep[i]]

        # 3. 主 DFS：计算 dfn, subsize, val
        dfn = [0] * (n + 1)
        subsize = [0] * (n + 1)
        val = [0] * (n + 1)
        tot = 0
        min_c_global = 2 * 10**18 # 足够大的数

        def dfs(u, current_min_c):
            nonlocal tot
            if not u:
                return
            
            tot += 1
            dfn[u] = tot
            
            # 更新路径最小值
            next_min_c = min(current_min_c, c[u])
            val[tot] = next_min_c
            
            dfs(ls[u], next_min_c)
            dfs(rs[u], next_min_c)
            
            if u == rt:
                val[dfn[u]] = 0
            
            subsize[u] = subsize[ls[u]] + subsize[rs[u]] + 1

        dfs(rt, min_c_global)

        # 4. 线段树构建
        # Python 中用数组模拟线段树
        tr_sum = [0] * (4 * n + 5)
        tr_dev = [False] * (4 * n + 5)
        # tr_l, tr_r, tr_siz 其实可以隐式计算，或者存起来
        # 为了完全还原你的结构，我们存起来
        tr_l = [0] * (4 * n + 5)
        tr_r = [0] * (4 * n + 5)

        def build(u, l, r):
            tr_l[u] = l
            tr_r[u] = r
            tr_dev[u] = False
            
            if l == r:
                tr_sum[u] = val[l]
                return
            
            mid = (l + r) // 2
            build(u << 1, l, mid)
            build(u << 1 | 1, mid + 1, r)
            tr_sum[u] = tr_sum[u << 1] + tr_sum[u << 1 | 1]

        build(1, 1, n)

        def push_down(u):
            if tr_dev[u]:
                na = u << 1
                nb = na | 1
                tr_dev[na] = True
                tr_dev[nb] = True
                tr_sum[na] = 0
                tr_sum[nb] = 0
                tr_dev[u] = False # 标记下传后，当前节点标记清除（虽然不清也行，因为是覆盖）

        def push_up(u):
            tr_sum[u] = tr_sum[u << 1] + tr_sum[u << 1 | 1]

        def op_dev(u, st, re):
            l = tr_l[u]
            r = tr_r[u]
            
            if l > re or r < st:
                return
            
            if l >= st and r <= re:
                tr_dev[u] = True
                tr_sum[u] = 0
                return
            
            push_down(u)
            op_dev(u << 1, st, re)
            op_dev(u << 1 | 1, st, re)
            push_up(u)

        def qr_sum(u, st, re):
            l = tr_l[u]
            r = tr_r[u]
            
            if l > re or r < st:
                return 0
            
            if l >= st and r <= re:
                return tr_sum[u]
            
            push_down(u)
            return qr_sum(u << 1, st, re) + qr_sum(u << 1 | 1, st, re)

        # 5. 计算答案
        ans_list = []
        
        # 初始答案
        ans_list.append(qr_sum(1, 1, n))
        
        for i in range(1, n + 1):
            target = top_rep[p[i]]
            # 区间清零
            op_dev(1, dfn[target], dfn[target] + subsize[target] - 1)
            ans_list.append(qr_sum(1, 1, n))

        print("ans :", *ans_list)

if __name__ == "__main__":
    solve()
