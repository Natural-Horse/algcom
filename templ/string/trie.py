"""
这份模板是字典树 Trie。
重点包括：
1. 插入字符串。
2. 查询某个字符串出现次数。

字典树适合处理字符串集合上的前缀问题，
比如前缀统计、异或 Trie、自动机基础结构等。
"""
class Trie:
    def __init__(self):
        self.tr = [[0] * 26]
        self.ed = [0]

    def insert(self, s):
        # 逐字符向下走，不存在就新建节点。
        u = 0
        for ch in s:
            c = ord(ch) - 97
            if not self.tr[u][c]:
                self.tr[u][c] = len(self.tr)
                self.tr.append([0] * 26)
                self.ed.append(0)
            u = self.tr[u][c]
        self.ed[u] += 1

    def find(self, s):
        # 查完整字符串出现次数。
        u = 0
        for ch in s:
            c = ord(ch) - 97
            if not self.tr[u][c]:
                return 0
            u = self.tr[u][c]
        return self.ed[u]
