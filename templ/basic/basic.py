"""
这份模板放最常用的 Python 竞赛基础写法。
重点包括：
1. `sys.stdin.buffer` 的快读与 `sys.stdout.write` 的快写。
2. 单个整数、整数列表、字符串、整份输入一次性读入的常见方式。
3. Python 对应 C++ 里分支、循环、函数、递归的最基础写法。

平时做题时，这份文件更像一个“语法速查表”，不一定整份直接复制，
而是按题型挑里面需要的输入输出和函数框架来用。
"""
import sys


def read_int():
    # 读一行，只取一个整数。
    return int(sys.stdin.buffer.readline())


def read_ints():
    # 读一行整数，返回 list。
    return list(map(int, sys.stdin.buffer.readline().split()))


def read_str():
    # 读一行字符串并去掉末尾换行。
    return sys.stdin.buffer.readline().decode().strip()


def fast_read_all():
    # 把整份输入一次性读完，适合极限卡常的场景。
    data = list(map(int, sys.stdin.buffer.read().split()))
    it = iter(data)
    return it


def solve_basic_io():
    # 最常见的 input 写法，直观但速度一般。
    n = int(input())
    a = list(map(int, input().split()))
    s = input().strip()
    print(n)
    print(*a)
    print(s)


def solve_buffer_io():
    # 竞赛里更常用的整份快读模板。
    data = fast_read_all()
    t = next(data)
    ans = []
    for _ in range(t):
        n = next(data)
        a = [next(data) for _ in range(n)]
        ans.append(str(sum(a)))
    sys.stdout.write("\n".join(ans))


def branch_loop_func_demo(x):
    # 对应 C++ 里的 if / else if / else。
    if x < 0:
        return -1
    elif x == 0:
        return 0
    return 1


def loop_demo(n):
    # for 和 while 在竞赛里的基础写法。
    s = 0
    for i in range(1, n + 1):
        s += i
    j = 0
    while j < n:
        j += 1
    return s


def recur_demo(u):
    # 递归函数示例，实际做题前要先确认递归深度是否安全。
    if u <= 1:
        return 1
    return recur_demo(u - 1) + recur_demo(u - 2)


def solve():
    # 留空，做题时把主逻辑写在这里。
    pass


if __name__ == "__main__":
    solve()
