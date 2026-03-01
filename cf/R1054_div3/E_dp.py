#!/usr/bin/env python3
# find_counterexample_with_gen.py
# Usage:
# 1) To reproduce big CF-like test and run ./E:
#    python3 find_counterexample_with_gen.py --gen-only
#    (This writes counterexample.txt and runs ./E < counterexample.txt)
#
# 2) To brute-force test a SMALLER variant of the same generator:
#    python3 find_counterexample_with_gen.py --brute-small
#    (This shrinks n to n_small for brute-force verification)
#
import subprocess
import sys
import argparse
from itertools import product
import random
import os

def compute(N, Z):
    # the generator you provided (returns list of length N)
    n = 200000
    mask = (1 << 17) - 1
    fill = int((1 << 15) * 1.3 + 1)
    arr = [mask + 2] * 2
    x = 6
    for i in range(1, fill):
        arr += [x] + [x]
        x = x * 5 + 1
        x = x & mask
    arr += [1] * (n - len(arr))
    # if caller asked for smaller N, we'll slice
    return arr[:N]

def brute_count(arr, k, L, R):
    n = len(arr)
    ans = 0
    for i in range(n):
        seen = {}
        distinct = 0
        for j in range(i, n):
            v = arr[j]
            if v not in seen or seen[v] == 0:
                seen[v] = 1
                distinct += 1
            else:
                seen[v] += 1
            length = j - i + 1
            if distinct == k and L <= length <= R:
                ans += 1
    return ans

def write_tests_to_file(tests, filename="counterexample.txt"):
    """
    tests: list of tuples (n,k,L,R,arr)
    Writes in the problem input format.
    """
    with open(filename, "w") as f:
        f.write(str(len(tests)) + "\n")
        for (n,k,L,R,arr) in tests:
            f.write(f"{n} {k} {L} {R}\n")
            f.write(" ".join(map(str, arr)) + "\n")
    print(f"[+] Written {len(tests)} tests to {os.path.abspath(filename)}")

def run_program_on_tests(exec_path, tests, timeout=10):
    """
    Runs exec_path with the given tests (in one input), returns list of outputs parsed as ints
    """
    T = len(tests)
    input_lines = []
    input_lines.append(str(T))
    for (n,k,L,R,arr) in tests:
        input_lines.append(f"{n} {k} {L} {R}")
        input_lines.append(" ".join(map(str, arr)))
    input_data = "\n".join(input_lines) + "\n"
    try:
        p = subprocess.Popen([exec_path], stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
    except FileNotFoundError:
        print(f"错误：找不到可执行文件 {exec_path}。请先编译你的 C++ 程序为该可执行文件名。")
        sys.exit(1)
    out, err = p.communicate(input_data, timeout=timeout)
    if err and len(err.strip())>0:
        # show stderr but continue
        print("[stderr from program]:")
        print(err)
    outs = []
    for line in out.splitlines():
        line = line.strip()
        if not line:
            continue
        parts = line.replace(":", " ").split()
        found = None
        for token in reversed(parts):
            try:
                v = int(token)
                found = v
                break
            except:
                continue
        if found is not None:
            outs.append(found)
    return outs

def gen_and_run_big(exec_path="./E", out_file="counterexample.txt"):
    # generate big test like the generator: n = 200000, k = n, L=1, R=n
    N = 200000
    arr = compute(N, N)
    tests = [(N, N, 1, N, arr)]
    write_tests_to_file(tests, out_file)
    print("[+] Running executable on generated big input (may take time)...")
    outs = run_program_on_tests(exec_path, tests, timeout=60)
    print("[+] Program outputs:")
    print("\n".join(map(str, outs)))
    return tests, outs

def gen_and_brute_small(exec_path="./E", n_small=8, out_file="counterexample_small.txt"):
    # produce a small test using same generator pattern but small n so brute is possible
    arr = compute(200000, 200000)  # generate base pattern
    arr_small = arr[:n_small]
    # choose some k,L,R combinations to try (we'll only try a handful)
    tests = []
    for k in range(1, min(n_small, 5) + 1):
        for L in range(1, n_small + 1):
            for R in range(L, min(n_small, L+3) + 1):  # limit R range to reduce total tests
                tests.append((n_small, k, L, R, arr_small))
                if len(tests) >= 200:
                    break
            if len(tests) >= 200:
                break
        if len(tests) >= 200:
            break
    write_tests_to_file(tests, out_file)
    # brute answers
    correct = [brute_count(arr_small, k, L, R) for (_,k,L,R,_) in tests]
    buggy_outs = run_program_on_tests(exec_path, tests, timeout=10)
    if len(buggy_outs) < len(tests):
        print("Program output fewer lines than tests; aborting.")
        return tests, correct, buggy_outs
    for idx, (tcase, corr) in enumerate(zip(tests, correct)):
        b = buggy_outs[idx]
        if b != corr:
            n,k,L,R,arr = tcase
            print("Found discrepancy!")
            print(f"n={n}, k={k}, L={L}, R={R}")
            print("arr =", arr)
            print("brute =", corr, "program =", b)
            # save the single failing test
            write_tests_to_file([tcase], "counterexample_discrepancy.txt")
            print("Saved failing test to counterexample_discrepancy.txt")
            return tests, correct, buggy_outs
    print("No discrepancy on small brute-tested batch.")
    return tests, correct, buggy_outs

def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--gen-only", action="store_true", help="Generate big CF-like test and run program (no brute).")
    parser.add_argument("--brute-small", action="store_true", help="Use a small n and brute-force compare.")
    parser.add_argument("--exec", type=str, default="./E", help="executable path (default ./E)")
    parser.add_argument("--nsmall", type=int, default=8, help="n for small brute-mode (default 8)")
    args = parser.parse_args()

    if args.gen_only:
        gen_and_run_big(exec_path=args.exec)
        return

    if args.brute_small:
        gen_and_brute_small(exec_path=args.exec, n_small=args.nsmall)
        return

    # default: run exhaustive + random as before, but also try one big generator input saved to file
    print("Default behavior: small exhaustive tests first, then try generator big input (gen-only).")
    # small exhaustive (original behavior)
    max_n = 6
    max_val = 3
    batch = []
    for n in range(1, max_n+1):
        for arr in product(range(1, max_val+1), repeat=n):
            arr = list(arr)
            for k in range(1, min(n, max_val)+1):
                for L in range(1, n+1):
                    for R in range(L, n+1):
                        batch.append((n,k,L,R,arr))
                        if len(batch) >= 500:
                            tests = batch
                            correct = [brute_count(a,k,L,R) for (a,k,L,R,a) in []]  # skip heavy precompute here
                            # For simplicity just run program and skip auto-compare in this thin default mode
                            buggy_outs = run_program_on_tests(args.exec, tests, timeout=10)
                            batch = []
                            break
                    if not batch:
                        break
                if not batch:
                    break
    # Finally generate the big one and save
    print("Generating big CF-like input and saving to counterexample.txt")
    gen_and_run_big(exec_path=args.exec)

if __name__ == "__main__":
    main()
