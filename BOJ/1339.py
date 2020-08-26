# 백트랙킹 - 실패
# from itertools import permutations

# num = int(input())
# ss = [list(input()) for i in range(num)]
# tmp = [e for st in ss for e in st]
# unique_s = list(set(tmp))

# match_num = list(range(9, 9-len(unique_s), -1))
# max_num = -1
# for mn in permutations(match_num):
#     match_info = dict(zip(unique_s, mn))
#     num_str = [''.join(map(lambda x: str(match_info[x]), st)) for st in ss]
#     print(num_str)
#     res = 0
#     for n in num_str:
#         res += int(n)
#     if res > max_num:
#         max_num = res
# print(max_num)


N = int(input())
words = [list(reversed(input())) for _ in range(N)]
coefs = [0 for _ in range(ord('z') - ord('a') + 1)]

for word in words:
    digit = 1
    for char in word:
        coefs[ord(char)-ord('A')] += digit
        digit *= 10

coefs.sort(reverse=True)

res = 0
num = 9
for coef in coefs[:9]:
    res += coef * num
    num -= 1

print(res)