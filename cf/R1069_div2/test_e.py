import subprocess

def run_test():
    # Compile
    subprocess.run(["g++", "e.cpp", "-o", "e"], check=True)
    
    # Input: 1 test case, n=2, m=2, p=1000000007
    input_str = "1\n2 2 1000000007\n"
    
    # Run
    result = subprocess.run(["./e"], input=input_str, text=True, capture_output=True)
    
    # Expected output: 6.5 mod 10^9+7
    # 6.5 = 13/2 = 13 * 500000004 = 6500000052 % 1000000007
    # 6500000052 = 6 * 1000000007 + 500000010
    expected = 500000010
    
    print(f"Output: {result.stdout.strip()}")
    print(f"Expected: {expected}")
    
    if str(expected) in result.stdout:
        print("Test Passed")
    else:
        print("Test Failed")

if __name__ == "__main__":
    run_test()
