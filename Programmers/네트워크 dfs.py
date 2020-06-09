def solution(n, c):
    answer = 0
    visited = [False] * n
    
    for i in range(n):
        if not visited[i]:
            answer += 1
            s = [i]
            visited[i] = True
            while s:
                now = s.pop()
                for j, v in enumerate(c[now]):
                    if not visited[j] and v == 1:
                        s.append(j)
                        visited[j] = True
    

    return answer