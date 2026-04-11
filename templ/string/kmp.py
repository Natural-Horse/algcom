"""
这份模板是 KMP。
重点包括：
1. `nxt` 数组表示模式串每个前缀的最长真前后缀长度。
2. 匹配失败时通过 `nxt` 回退，不需要重新比较。
3. 可以在线性时间内完成模式匹配。

KMP 最容易写错的地方通常是下标和回退位置。
"""
def kmp_nxt(s):
    # 构造模式串的前缀函数。
    n = len(s)
    nxt = [0] * n
    j = 0
    for i in range(1, n):
        while j and s[i] != s[j]:
            j = nxt[j - 1]
        if s[i] == s[j]:
            j += 1
        nxt[i] = j
    return nxt


def kmp_find(s, p):
    # 返回模式串 p 在文本串 s 中所有出现位置。
    if not p:
        return []
    nxt = kmp_nxt(p)
    j = 0
    ans = []
    for i, ch in enumerate(s):
        while j and ch != p[j]:
            j = nxt[j - 1]
        if ch == p[j]:
            j += 1
        if j == len(p):
            ans.append(i - len(p) + 1)
            j = nxt[j - 1]
    return ans
