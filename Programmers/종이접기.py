def solution(n):
    answer = []
    for _ in range(1, n+1):
        answer = answer + [0] + [(i+1)%2 for i in reversed(answer)]
    return answer