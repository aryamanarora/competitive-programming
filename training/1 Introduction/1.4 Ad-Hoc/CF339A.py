nums = list(map(int, input().split('+')))
nums = sorted(nums)
print('+'.join([str(num) for num in nums]))