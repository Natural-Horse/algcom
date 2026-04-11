"""
这份模板是 AC 自动机。
重点包括：
1. 用 Trie 存多模式串。
2. 用 fail 指针把失配跳转串起来。
3. 查询时可以同时匹配多个模式串。

适合“给很多模式串，问文本里出现了多少次/哪些出现过”的题。
"""
from collections import deque


class ACAutomaton:
    def __init__(self):
        self.tr = [[0] * 26]
        self.fail = [0]
        self.cnt = [0]

    def insert(self, s):
        # 把一个模式串插入 Trie。
        u = 0
        for ch in s:
            c = ord(ch) - 97
            if not self.tr[u][c]:
                self.tr[u][c] = len(self.tr)
                self.tr.append([0] * 26)
                self.fail.append(0)
                self.cnt.append(0)
            u = self.tr[u][c]
        self.cnt[u] += 1

    def build(self):
        # BFS 建 fail 指针，并补齐自动机转移。
        q = deque()
        for c in range(26):
            v = self.tr[0][c]
            if v:
                q.append(v)
        while q:
            u = q.popleft()
            for c in range(26):
                v = self.tr[u][c]
                if v:
                    self.fail[v] = self.tr[self.fail[u]][c]
                    q.append(v)
                else:
                    self.tr[u][c] = self.tr[self.fail[u]][c]

    def query(self, s):
        # 这里演示的是统计匹配总数的基础写法。
        u = 0
        ans = 0
        for ch in s:
            u = self.tr[u][ord(ch) - 97]
            j = u
            while j and self.cnt[j] != -1:
                ans += self.cnt[j]
                self.cnt[j] = -1
                j = self.fail[j]
        return ans
