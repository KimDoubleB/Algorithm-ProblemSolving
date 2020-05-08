def solution(n, lost, reserve):
    answer = 0
    
    # 여벌 체육복 있으면서, 잃어버린 경우 삭제
    nlost = list(set(lost) - set(reserve))
    nreserve = list(set(reserve) - set(lost))
    
    # 왼쪽부터 확인하며 순회
    for r in nreserve:
        if r-1 in nlost:
            nlost.remove(r-1)
        elif r+1 in nlost:
            nlost.remove(r+1)
    
    # 수업들을 수 있는 학생 수
    answer = n - len(nlost)
    
    return answer