"""
这份模板放几类非常常见的 DP 写法。
重点包括：
1. 01 背包和完全背包的一维滚动数组。
2. LIS 的二分优化写法。
3. 区间 DP 的基础框架。

DP 题最关键的是状态定义和转移来源。
这份模板主要帮你快速回忆循环顺序和常用写法。
"""
def knapsack_01(a, val, m):
    # 01 背包必须倒序枚举容量，避免同一件物品被重复使用。
    dp = [0] * (m + 1)
    for w, v in zip(a, val):
        for j in range(m, w - 1, -1):
            dp[j] = max(dp[j], dp[j - w] + v)
    return dp


def knapsack_complete(a, val, m):
    # 完全背包正序枚举容量，允许同一件物品重复使用。
    dp = [0] * (m + 1)
    for w, v in zip(a, val):
        for j in range(w, m + 1):
            dp[j] = max(dp[j], dp[j - w] + v)
    return dp


def lis(a):
    # d[i] 表示长度为 i+1 的上升子序列的最小结尾。
    d = []
    for x in a:
        l, r = 0, len(d)
        while l < r:
            mid = (l + r) >> 1
            if d[mid] >= x:
                r = mid
            else:
                l = mid + 1
        if l == len(d):
            d.append(x)
        else:
            d[l] = x
    return len(d)


def interval_dp(a):
    # 区间 DP 基础框架，具体转移按题意修改。
    n = len(a)
    dp = [[0] * n for _ in range(n)]
    for ln in range(2, n + 1):
        for l in range(n - ln + 1):
            r = l + ln - 1
            dp[l][r] = 10 ** 18
            for k in range(l, r):
                dp[l][r] = min(dp[l][r], dp[l][k] + dp[k + 1][r])
    return dp
