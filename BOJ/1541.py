nums = input().rstrip().split('-')
nums = list(map(lambda x: sum(map(int, x.split('+'))), nums))
res = nums[0] * 2
for n in nums:
    res -= n
print(res)