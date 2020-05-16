def solution(answers):
    #일번: 1, 2, 3, 4, 5
    #이번: 2, 1, 2, 3, 2, 4, 2, 5
    #삼번: 3, 3, 1, 1, 2, 2, 4, 4, 5, 5
    persons = [[1, 2, 3, 4, 5], [2, 1, 2, 3, 2, 4, 2, 5], [3, 3, 1, 1, 2, 2, 4, 4, 5, 5]]
    num = {1:0, 2:0, 3:0}
    
    for i, v in enumerate(answers):
        for pnum, p in enumerate(persons):
            if v == p[i % len(p)]: 
                # 현재 정답과 이 사람의 정답이 일치하면
                num[pnum+1] += 1
                
    num = sorted(num.items(), key=lambda v: v[1], reverse=True)
    max_val = num[0][1]
    answer = [v[0] for v in num if v[1]==max_val]
    
    return answer