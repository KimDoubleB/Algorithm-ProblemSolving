def solution(h):
    answer = [0 for _ in h]
    
    for i in range(len(h)-1, -1, -1):
        for j in range(i-1, -1, -1):
            if h[j] > h[i]:
                answer[i] = j+1
                break
    
    return answer