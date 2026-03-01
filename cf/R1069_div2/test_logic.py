def solve():
    import sys
    
    # Mock input for testing
    test_cases = [
        (3, 1, 3),
        (3, 2, 3),
        (4, 2, 4),
        (5, 2, 4)
    ]
    
    for n, l, r in test_cases:
        # Construction logic
        # P_i = i for 0 <= i < r
        # P_r = l - 1
        # P_i = i - 1 for r < i <= n
        
        P = [0] * (n + 1)
        for i in range(r):
            P[i] = i
        P[r] = l - 1
        for i in range(r + 1, n + 1):
            P[i] = i - 1
            
        # Calculate a
        a = []
        for i in range(1, n + 1):
            val = P[i] ^ P[i-1]
            a.append(val)
            
        # Verify
        # 1. a_i > 0
        if any(x <= 0 for x in a):
            print(f"Failed for {n, l, r}: non-positive element")
            return

        # 2. f(l, r) == 0
        # Recompute prefix xors
        curr = 0
        real_P = [0]
        for x in a:
            curr ^= x
            real_P.append(curr)
            
        if real_P[r] ^ real_P[l-1] != 0:
             print(f"Failed for {n, l, r}: f(l, r) != 0")
             return
             
        # 3. f(x, y) != 0 for other pairs
        for x in range(1, n + 1):
            for y in range(x, n + 1):
                if x == l and y == r:
                    continue
                if real_P[y] ^ real_P[x-1] == 0:
                    print(f"Failed for {n, l, r}: f({x}, {y}) == 0")
                    return
                    
        print(f"Passed {n, l, r}: {a}")

solve()
