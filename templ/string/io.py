"""
这份模板放字符串类题目最基础的输入输出处理。
重点包括：
1. 用 buffer 读一整行字符串。
2. 字符串和字符数组之间的互转。
3. 输出字符串长度等基础信息。

字符串题经常会混合字符、整数、模式串等多种输入，
先把读法写稳很重要。
"""
import sys


def solve():
    # 读一行字符串。
    s = sys.stdin.buffer.readline().decode().strip()
    a = list(s)
    print(s)
    print("".join(a))
    print(len(s))


if __name__ == "__main__":
    solve()
