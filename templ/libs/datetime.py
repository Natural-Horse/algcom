"""
这份模板整理 `datetime` 的常见用法。
重点包括：
1. 当前时间。
2. 日期和时间的格式化。
3. 时间差计算。

算法竞赛里这个库不算高频，
但做脚本、日志、文件名时间戳时会很方便。
"""
import datetime


def now_demo():
    # 获取当前本地时间。
    return datetime.datetime.now()


def format_demo():
    # strftime 用于格式化输出。
    now = datetime.datetime.now()
    return now.strftime("%Y-%m-%d %H:%M:%S")


def delta_demo():
    # timedelta 可以直接做日期加减。
    d1 = datetime.date(2026, 4, 8)
    d2 = d1 + datetime.timedelta(days=7)
    return d1, d2, (d2 - d1).days
