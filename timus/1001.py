import sys
nums = sys.stdin.read()

for num in nums.split()[::-1]:
    print(float(num)**0.5)
