# 보배
def solution(clothes):
    dic = {}
    for c in clothes:
        dic[c[1]] = dic[c[1]]+1 if dic.get(c[1], 0) else 2
    answer = 1
    for v in dic.values():
        answer *= v
    return answer - 1