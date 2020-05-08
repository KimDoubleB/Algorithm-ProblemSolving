# 에라토스테네스의 체 사용
def solution(n):
    s = set(range(3, n+1, 2))

    for i in range(3, n+1, 2):
        if i in s:
            s -= set(range(i*2, n+1, i))
    s.add(2)
    
    answer = len(s)
    return answer